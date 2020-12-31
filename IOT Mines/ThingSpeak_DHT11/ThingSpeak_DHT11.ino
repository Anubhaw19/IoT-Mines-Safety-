#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>

DHT dht(D5, DHT11);
 bool test=true;

WiFiClient client;

long myChannelNumber = 1271584;
const char myWriteAPIKey[] = "VNIXN6FBA3C66XSL";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("hotspot", "wifi1808004");
  while(WiFi.status() != WL_CONNECTED)
  {
    if(WiFi.status() == WL_CONNECT_FAILED)
    {
      Serial.print("Unable to connect:(\n");
    }
    delay(200);
    Serial.print("Connecting..\n");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  dht.begin();
  ThingSpeak.begin(client);
}

void loop() {
 
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println("Temperature: " + (String) t);
  Serial.println("Humidity: " + (String) h);
//  if(test)
//  {
//    ThingSpeak.writeField(myChannelNumber, 2, t, myWriteAPIKey);
//    test=!test;
//  }
//  else{
//    ThingSpeak.writeField(myChannelNumber, 1, h, myWriteAPIKey);
//     test=!test;
//  }
  
   
   ThingSpeak.writeField(myChannelNumber, 1, h, myWriteAPIKey);
   delay(1500);
   ThingSpeak.writeField(myChannelNumber, 2, t, myWriteAPIKey);
   delay(1500);
 
}
