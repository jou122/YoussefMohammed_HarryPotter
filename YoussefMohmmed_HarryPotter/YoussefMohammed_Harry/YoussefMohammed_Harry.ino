const int left_pin = 3;
const int forward_pin = 4;
const int right_pin = 5;

//for this sketch to work the forward ir sensor must be alittle more forward than left and right
//as if the robot faces a T intersection where it can only move left or right the forward sensor should be in the front reading 0
// typically the forward sensor reads if there is a lean in front of the robot at the intersection it should be HIGH as long as the robot has a palce to move forward

void moveForward(){}

void rotate90left(){}

void rotate90right(){}

void moveBackward(){}

void stop(){}

void setup()
{
  pinMode(left_pin,INPUT);
  pinMode(forward_pin,INPUT);
  pinMode(right_pin,INPUT);
}

void loop()
{
  int left = digitalRead(3);
  int forward = digitalRead(4);
  int right = digitalRead(5);

  if (left == HIGH && forward == HIGH && right == HIGH)
      {
      moveForward();
      delay(50);
      if (left == HIGH && forward == HIGH && right == HIGH)
          {
            Serial.println("END");
            stop();
          }
      }

  if ( right == HIGH)
    {
      rotate90right(); // As left is possible
    }


  else if (forward == HIGH)
    {
      moveForward();
    }

  else if (left == HIGH )
    {
     rotate90left();
    }

  else
    {
      moveBackward();// As Left is possible
    }
  
}