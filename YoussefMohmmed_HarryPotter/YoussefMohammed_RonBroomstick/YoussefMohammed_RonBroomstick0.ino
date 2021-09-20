#include <Wire.h>
const int i2c_addr = 0x3F;
const int led_pin = 13;

int gyro_x,gyro_y,gyro_z;
long gyro_x_cal,gyro_y_call,gyro_z_cal;
boolean set_gyro_angles ;

long acc_x, acc_y, acc_z, acc_total_vector;
float angle_roll_acc, angle_pitch_acc;

float angle_pitch,angel_roll;
int angle_pitch_buffer, angel_roll_buffer;
float angle_pitch_output,angle_roll_output;


int ledState = LOW;          
unsigned long previousMillis = 0;      
const long interval = 100; 



void setup() {

  Wire.begin();

  pinMode(led_pin,OUTPUT)

  setup_imu_registers();

  for (int cal_int  = 0 ;  cal_int < 1000  ; cal_int ++){
    read_mpu_6050_data();

    gyro_x_cal += gyro_x;

    gyro_y_cal += gyro_y;

    gyro_z_cal += gyro_z;

    delay(1);
  }

  gyro_x_cal /= 1000;

  gyro_y_cal /= 1000;

  gyro_z_cal /= 1000;

}

void loop() {
  read_imu();

  gyro_x -= gyro_x_cal;
  gyro_y -= gyro_y_cal;
  gyro_z -= gyro_z_cal;

  angle_pitch += gyro_x * 0.0000611;

  angel_roll += gyro_y *0.0000611;

  angle_pitch += angel_roll*sin(gyro_z*0.000001066);

  angel_roll += angel_pitch*sin(gyro_z*0.000001066);


  acc_total_vector = sqrt((acc_x*acc_x)+(acc_y*acc_y)+(acc_z*acc_z));


  angle_pitch_acc = asin((float)acc_y/acc_total_vector)*57.296;

  angle_roll_acc = asin((float)acc_x/acc_total_vector)*-57.296;


  if(set_gyro_angles){

    angle_pitch = angle_pitch*0.9996 + angel_pitch_acc*0.0004;

    angle_pitch = angle_pitch*0.9996 + angel_pitch_acc*0.0004;
  }
  else{
    angle_pitch = angle_pitch_acc;
    angle_roll = angle_roll_acc;
    set_gyro_angles = true;
  }

  angle_pitch_output = angle_pitch_output * 09 + angle_pitch *0.1;

  angle_roll_output = angle_roll_output*0.9 + angle_roll * 0.1;


  if (abs(angle_pitch_output)>60){

      blink();
  }
  else if(abs(angle_roll_output)>60){
      blink();
  }

}

void setup_imu_registers(){

  ///configure the mpu
  Wire.beginTransmission(0x68);

  Wire.write(0x6B);

  Wire.write(0x00);

  Wire.endTransmission();


  //configure the accelerometer
  Wire.beginTransmission(0x68);

  Wire.write(0x1c);

  Wire.write(0x18);

  Wire.endTransmission();


  //configure the gyro
  Wire.beginTransmission(0x68);

  Wire.write(0x1B);

  Wire.write(0x18);

  Wire.endTransmission();
}


void read_imu(){

  Wire.beginTransmission(0x68);

  Wire.write(0x3B);

  Wire.endTransmission();

  Wire.requestFrom(0x68,14);

  While(Wire.available()<14);

  acc_x = Wire.read()<<8|Wire.read();
  acc_y = Wire.read()<<8|Wire.read();
  acc_z = Wire.read()<<8|Wire.read();
  temp = Wire.read()<<8|Wire.read();
  gyro_x = Wire.read()<<8|Wire.read();
  gyro_y = Wire.read()<<8|Wire.read();
  gyro_z = Wire.read()<<8|Wire.read();

}


void blink(){
unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
     digitalWrite(ledPin, ledState);
  }
  digitalWrite(ledPin, LOW);
}
