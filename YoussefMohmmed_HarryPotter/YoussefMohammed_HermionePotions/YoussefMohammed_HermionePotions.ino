#include "Timer.h"
const int But=2;          //button pin attach to interupt pin  
const int Red = 3;         //red led pin     
const int Green = 4;      //green led pin
const int White = 5;      //white led pin
const int potionTimeInMin=15;   //time of the potion
unsigned long startTime=0;      //time you press the button
volatile bool start = true;     //check if the button is already pushed

int8_t green_flash_id;           //id of the function that flashes the green led
int8_t white_flash_id;           //id of the function that flashes the white led
int8_t red_id;                   //id of the function that turns the red led on for 15 min
int8_t green_id;                 //id of the function that starts the flashing of the green led
int8_t white1_id;                //id of the function that starts the flashing of the white led every 5 min
int8_t white2_id;                //id of the function that starts the flashing of the white led every 8 min


const unsigned long heat = 15*60*1000;  //time the heat should be on 
const unsigned long mix = 2*60*1000;    //peroid of mixing 
const unsigned long add1 = 5*60*1000;   //peroid of adding first element 
const unsigned long add2 = 8*60*1000;   //peroid of adding second element   
Timer timer;

void green_flash(){ //flashes the green led for 5 seconds
green_flash_id=timer.oscillate(Green,100,LOW,5);
Serial.println(millis());
Serial.println("green_flash");
}
void white_flash(){ //flashes the white led for 5 seconds
white_flash_id = timer.oscillate(White,100,LOW,10);
Serial.println(millis());
Serial.println("white_flash");
}

void startPotion(){// interupt function starts at pressing the button
  if(start){
    startTime=millis();
    Serial.println("startTime interupt");
    Serial.println(startTime);
    detachInterrupt(But);
    start=false;    
    red_id = timer.oscillate(Red,heat,HIGH);
    green_id = timer.every(mix,green_flash);
    white1_id = timer.every(add1,white_flash);
    white2_id = timer.every(add2,white_flash);
  }
    
}




void setup(void)
{
    Serial.begin(9600);
    Serial.println("startTime setup");
    Serial.println(startTime);
    pinMode(Red, OUTPUT);
    pinMode(White, OUTPUT);
    pinMode(Green, OUTPUT);
    pinMode(But,INPUT);//digitalWrite(But,LOW);
   attachInterrupt(digitalPinToInterrupt(But), startPotion, HIGH);   
}

void loop(void)
{
    timer.update();
    if(millis()-startTime>potionTimeInMin*60*1000){//stoping all timers after potion time 
    //could be handeled more decently by adding each timer to a list then stopping them with loop but tic toc
    timer.stop(green_flash_id);
    timer.stop(white_flash_id);
    timer.stop( red_id);
    timer.stop( green_id);
    timer.stop( white1_id);
    timer.stop( white2_id);
    }     
}

