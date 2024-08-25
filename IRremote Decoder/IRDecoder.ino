#include <IRremote.h>
#define IR_RECEIVER_PIN 5

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  IrReceiver.begin(IR_RECEIVER_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("Enabled IRin");
}

void loop()
{
  if (IrReceiver.decode())
  {
    Serial.println(IrReceiver.decodedIRData.command);
    IrReceiver.resume();
  }
  delay(500);
}