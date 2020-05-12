#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "3oXmXmwRJHAMDEPbLVPczQJLr5aIN9T3";
char ssid[] = "Galaxy M30sD87B";
char pass[] = "dqhj7663";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  pinMode(13,OUTPUT); // NodeMCU D7 pin : Reverse
  pinMode(15,OUTPUT); // NodeMCU D8 pin : Forward
  
 }
  
void loop()
{
  
  Blynk.run();
  
}

BLYNK_WRITE(D8)
{
   digitalWrite(15,HIGH);
   digitalWrite(13,LOW);
}

BLYNK_WRITE(D7)
{
   digitalWrite(13,HIGH);
   digitalWrite(15,LOW);
}
