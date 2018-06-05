#define BLYNK_PRINT Serial

#define TINY_GSM_MODEM_SIM900


// Default heartbeat interval for GSM is 60
// If you want override this value, uncomment and set this option:
//#define BLYNK_HEARTBEAT 30

#include <TinyGsmClient.h>
#include <BlynkSimpleSIM800.h>
#include <SHT1x.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "8065c608edb848c4a89e9512280d7424";

// Your GPRS credentials
// Leave empty, if missing user or pass
char apn[]  = "internet";
char user[] = "";
char pass[] = "";

// Hardware Serial on Mega, Leonardo, Micro
#define SerialAT Serial1

// or Software Serial on Uno, Nano
//#include <SoftwareSerial.h>
//SoftwareSerial SerialAT(7, 8); // RX, TX

TinyGsm modem(SerialAT);


//Sensor 1
#define dataPin1  2
#define clockPin1 3
SHT1x sht1x(dataPin1, clockPin1);

//Sensor 2
#define dataPin2  5
#define clockPin2 4
SHT1x sht2x(dataPin2, clockPin2);

//Sensor 3
//#define dataPin  2
//#define clockPin 3
//SHT1x sht1x(dataPin, clockPin);



BlynkTimer timer;

void sendSensor()
{
  float t1 = sht1x.readTemperatureC();
  float h1 = sht1x.readHumidity();
  
  
  // Print the values to the serial port
  Serial.print("Температура 25см: ");
  Serial.print(t1, 0);
  Serial.print(" ºC / ");
  Serial.print("Влажность 25см: ");
  Serial.print(h1,0);
  Serial.println("%");
 
//Sensor 2 
  float t2 = sht2x.readTemperatureC();
  float h2 = sht2x.readHumidity();
  
  
  // Print the values to the serial port
  Serial.print("Температура 50см: ");
  Serial.print(t2, 0);
  Serial.print(" ºC / ");
  Serial.print("Влажность 50см: ");
  Serial.print(h2,0);
  Serial.println("%");
 
  // You can send any value at any time.
  // Please don't send more that 10 values per second.

//Sensor 1
Blynk.virtualWrite(V5, t2);
Blynk.virtualWrite(V6, h2);

//Sensor 2
Blynk.virtualWrite(V3, t1);
Blynk.virtualWrite(V4, h1);

}


void setup()
{
  // Debug console
  Serial.begin(19200);

 Serial.println("Starting up");

  delay(10000);

  // Set GSM module baud rate
  SerialAT.begin(19200);
  delay(3000);

  // Restart takes quite some time
  // To skip it, call init() instead of restart()
  Serial.println("Initializing modem...");
  modem.restart();

  // Unlock your SIM card with a PIN
  //modem.simUnlock("1234");

  Blynk.begin(auth, modem, apn, user, pass);
  timer.setInterval(18000L, sendSensor);
 
delay(36000);

}



void loop()
{
  Blynk.run();
  timer.run();
}
