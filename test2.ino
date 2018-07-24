#define m11 11    // rear motor
#define m12 12
#define m21 10    // front motor
#define m22 9
char str[2], i;
void forward()
{ analogWrite(m11, 180); // Run in half speed
    analogWrite(m12, 0); // Run in full speed
    analogWrite(m21, 255); // Run in half speed
    analogWrite(m22, 0); // Run in full speed
  
}
void backward()
{
  analogWrite(m11, 0); // Run in half speed
    analogWrite(m12, 180); // Run in full speed
    analogWrite(m21, 0); // Run in half speed
    analogWrite(m22, 255); // Run in full speed
  
}
void left()
{analogWrite(m11, 0); // Run in half speed
    analogWrite(m12, 0); // Run in full speed
    analogWrite(m21, 255); // Run in half speed
    analogWrite(m22, 0); // Run in full speed
  
}
void right()
{analogWrite(m11,180); // Run in half speed
    analogWrite(m12, 0); // Run in full speed
    analogWrite(m21, 0); // Run in half speed
    analogWrite(m22, 0); // Run in full speed
  
}
void Stop()
{analogWrite(m11, 0); // Run in half speed
    analogWrite(m12, 0); // Run in full speed
    analogWrite(m21, 0); // Run in half speed
    analogWrite(m22, 0); // Run in full speed
  
}
void setup()
{
  Serial.begin(9600);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
}
void loop()
{
  while (Serial.available())
  {
    char ch = Serial.read();
    str[i++] = ch;

    if (str[i - 1] == '1')
    {
      Serial.println("Forward");
      forward();
      i = 0;
    }
    else if (str[i - 1] == '2')
    {
      Serial.println("Left");
      right();
      i = 0;
    }
    else if (str[i - 1] == '3')
    {
      Serial.println("Right");
      left();
      i = 0;
    }

    else if (str[i - 1] == '4')
    {
      Serial.println("Backward");
      backward();
      i = 0;
    }
    else if (str[i - 1] == '5')
    {
      Serial.println("Stop");
      Stop();
      i = 0;
    }
    delay(100);
  }
}
