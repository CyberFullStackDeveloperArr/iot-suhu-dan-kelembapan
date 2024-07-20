//*********DHT22, library****************************************
#include "DHTesp.h"

//*********DHT22, deklarasi pin**********************************
const int DHT_PIN = 15;
DHTesp dhtSensor;
float suhu = 0;
float kelembaban = 0;

void setup() {
  //*****SERIAL MONITOR, setting baud rate***********************
  Serial.begin(115200);
  pinMode(13,OUTPUT);

  //*****DHT 22, setting*****************************************
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
}

void loop() {
  //*********DHT22, membaca suhu dan kelembaban******************
  TempAndHumidity  data = dhtSensor.getTempAndHumidity();
  suhu=data.temperature;
  kelembaban=data.humidity;

  //*****SERIAL MONITOR, menampilkan data suhu dan kelembaban****
  Serial.print("Temp: ");
  Serial.print(suhu);
  Serial.println("C");
  Serial.print("Hum: ");
  Serial.print(kelembaban);
  Serial.println("%");

   
  if(suhu>25&&kelembaban<50)
  {
    digitalWrite(13, HIGH);
  }
  else 
  {
    digitalWrite(13, LOW);
  }
  delay(1000);
}