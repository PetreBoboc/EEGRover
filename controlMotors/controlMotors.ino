// Source code inspired from here:
// https://forum.arduino.cc/index.php?topic=398011.0

// Motor 1
int dir1PinA = 2;
int dir2PinA = 3;
int speedPinA = 9;

// Motor 2
int dir1PinB = 4;
int dir2PinB = 5;
int speedPinB = 10;

void setup()
{
  Serial.begin(9600);

  //Define L298N Dual H-Bridge Motor Controller Pins

  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);

}

void loop()
{

  if (Serial.available() > 0)
  {
    int inByte = Serial.read();

    switch (inByte)
    {

      case '1': //Forward
        //Motor 1
        analogWrite(speedPinA, 255);
        digitalWrite(dir1PinA, LOW);
        digitalWrite(dir2PinA, HIGH);
        //Motor 2
        analogWrite(speedPinB, 255);
        digitalWrite(dir1PinB, LOW);
        digitalWrite(dir2PinB, HIGH);
        break;
        
      case '0': //Stop
        //Motor 1
        analogWrite(speedPinA, 0);
        digitalWrite(dir1PinA, LOW);
        digitalWrite(dir2PinA, HIGH);
        //Motor 2
        analogWrite(speedPinB, 0);
        digitalWrite(dir1PinB, LOW);
        digitalWrite(dir2PinB, HIGH);
        break;
    }
  }
}
