#include <IRremote.h>
#define RECV_PIN 7

#define r1 5
int relay1 = LOW;
#define r2 12
int relay2 = LOW;
#define r3 11
int relay3 = LOW;



void setup() 
{
IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
pinMode(r1, OUTPUT); 
pinMode(r2, OUTPUT);
pinMode(r3, OUTPUT);

}
void loop() {
if(IrReceiver.decode()) {
switch (IrReceiver.decodedIRData.decodedRawData) {
case 948:
digitalWrite(r1,0);
digitalWrite(r2,0);
digitalWrite(r3,0);  //all off
delay(100);
break; 
case 1016:
relay1 = ~ relay1;
digitalWrite(r1,relay1);
delay(100);
break;
case 1012:
relay2 = ~ relay2;
digitalWrite(r2,relay2);
delay(100);
break;
case 1008:
relay3 = ~ relay3;
digitalWrite(r3,relay3);
delay(100);
break;

}

IrReceiver.resume();
}
}
