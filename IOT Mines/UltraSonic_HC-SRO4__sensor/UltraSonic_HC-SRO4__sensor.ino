#include <ESP8266WiFi.h>
//#include <DHT.h>
#include <ThingSpeak.h>

//DHT dht(D5, DHT11);
// bool test=true;
 int n;

//const int trigPin = D5;   
const int trigPin = D7; 
const int echoPin = D6; 

long duration;
int distance,distance_cm,feet,inch;
float distance_in;


WiFiClient client;

long myChannelNumber = 1271584;
const char myWriteAPIKey[] = "VNIXN6FBA3C66XSL";

void setup() {
  // put your setup code here, to run once:

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
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
//  dht.begin();
  ThingSpeak.begin(client);
}

void loop() {

  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
distance_cm = ( duration / 29 ) / 2;
distance_in = distance_cm * 0.393701;    
feet=(int)distance_in/12;
inch=(int)distance_in%12;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
Serial.print("Distance(cm):"+String(distance_cm)+"cm ");
//Serial.print(" Distance(inch):"+String(distance_in));
Serial.print(" Distance(feet):"+String(feet)+"feet "+String(inch)+"in");
Serial.print("\n");
//delay(2000);
//  n=analogRead(A0);
//  Serial.println("Methane Gas :"+(String)n);
//  ThingSpeak.writeField(myChannelNumber, 3, n, myWriteAPIKey);
    ThingSpeak.writeField(myChannelNumber, 4, (float)distance_in/12, myWriteAPIKey);
//  // put your main code here, to run repeatedly:
//  float h = dht.readHumidity();
//  float t = dht.readTemperature();
//  Serial.println("Temperature: " + (String) t);
//  Serial.println("Humidity: " + (String) h);

  
//   
//   ThingSpeak.writeField(myChannelNumber, 1, h, myWriteAPIKey);
//   delay(1500);
//   ThingSpeak.writeField(myChannelNumber, 2, t, myWriteAPIKey);
   delay(2000);
 
}
