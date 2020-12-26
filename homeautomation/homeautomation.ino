//#include "DHT.h"

//#define DHTPIN 11
//#define DHTTYPE DHT22

const int trigPin = 7;
const int echoPin = 6;
int relayPin = 12;

// defines variables
long duration;
int distance;

//DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
//  dht.begin();
  pinMode(relayPin, OUTPUT);
}

void loop() {

//  delay(2000);
  
//  float h =dht.readHumidity();
//
//  float t = dht.readTemperature();
//
//  if (isnan(h) || isnan(t)) {
//    Serial.println("Failed to read from DHT sensor!");
//    return;
//  }
//
//  Serial.print("Humidity: "); 
//  Serial.print(h);
//  Serial.print(" %\t");
//  Serial.print("Temperature: "); 
//  Serial.print(t);
//  Serial.println(" *C ");

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
delay(100);
Serial.println(distance);
if(distance <20) {
  digitalWrite(relayPin, LOW);
  delay(10);
}
else {
  digitalWrite(relayPin, HIGH);
}
}
