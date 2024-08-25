#include<IRremote.hpp>
#include <AccelStepper.h>
#define IR_RECEIVER_PIN 5

const byte stepPin = 3;
const byte dirPin = 2;

bool isMoving = false;
int moveDirection = 0;
int speed = 50;
long home = 0;

AccelStepper stepper(AccelStepper::DRIVER, stepPin, dirPin);

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVER_PIN, ENABLE_LED_FEEDBACK);
  stepper.setMaxSpeed(2000);
  stepper.setAcceleration(speed);
  home = stepper.currentPosition();
}

void ControlMotor()
{
  if(isMoving)
  {
    stepper.move(moveDirection);
    stepper.run();
  }
}

void up()
{
  Serial.println("Up");
  isMoving = true;
  moveDirection = 1;
}
void down()
{
  Serial.println("Down");
  isMoving = true;
  moveDirection = -1;
}
void increase_speed()
{
  speed += 50;
  Serial.println("Speed: ");
  Serial.println(stepper.speed());
  stepper.setAcceleration(speed);
}
void decrease_speed()
{
  speed -= 50;
  Serial.println("Speed: ");
  Serial.println(stepper.speed());
  stepper.setAcceleration(speed);
}
void return_home()
{
  isMoving = false;
  Serial.println("Home");
  stepper.setAcceleration(10);
  stepper.runToNewPosition(home);
  stepper.stop();
}
void stop()
{
  Serial.println("Stop");
  isMoving = false;
}

void loop()
{
  if(IrReceiver.decode())
  {
    switch(IrReceiver.decodedIRData.command)
    {
      case 24:
        up();
        break;
      case 82:
        down();
        break;
      case 90:
        increase_speed();
        break;
      case 8:
        decrease_speed();
        break;
      case 25:
        return_home();
        break;
      case 28:
        stop();
        break;
      default:
        break;
    }
    IrReceiver.resume();
  }
  ControlMotor();
}