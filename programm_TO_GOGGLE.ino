#include <SHT1x.h>;

//Sensor 1 (25 cm)
#define dataPin 2
#define clockPin 3
SHT1x sht1x_1(dataPin, clockPin);

//Sensor 2 (50 cm)
#define dataPin2 5
#define clockPin2 6
SHT1x sht1x_2(dataPin2, clockPin2);

//Sensor 3 (75 cm)
#define dataPin 14
#define clockPin 15
SHT1x sht1x_3(dataPin, clockPin);

//Sensor 4 (1 m)
#define dataPin2 12
#define clockPin2 11
SHT1x sht1x_4(dataPin2, clockPin2);


//Sensor 5 (osadki)





void setup() {
  Serial1.begin(19200);
  Serial.begin(19200);
  
}






void loop () {
 


  char t25[10];
  char h25[10];
  char t50[10];
  char h50[10];
  char t75[10];
  char h75[10];
  char t1[10];
  char h1[10];
  char o[10];



  // Read values from the sensor 25 cm
  format(sht1x_1.readTemperatureC(), t25);
  format(sht1x_1.readHumidity(), h25);
  Serial1.print(t25);
  Serial1.print(h25);
  


 // Read values from the sensor 50 cm
  format(sht1x_2.readTemperatureC(), t50);
  format(sht1x_2.readHumidity(), h50);
  Serial1.print(t50);
  Serial1.print(h50);
  

 // Read values from the sensor 75 cm
  format(sht1x_3.readTemperatureC(), t75);
  format(sht1x_3.readHumidity(), h75);
  Serial1.print(t75);
  Serial1.print(h75);



 // Read values from the sensor 1 m
  format(sht1x_4.readTemperatureC(), t1);
  format(sht1x_4.readHumidity(), h1);
  Serial1.print(t1);
  Serial1.print(h1);




  Serial1.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");  //Установка настроек подключения
  delay(100);
  Serial1.println("AT+SAPBR=3,1,\"APN\",\"internet\"");
  delay(100);
  Serial1.println("AT+SAPBR=3,1,\"USER\",\"\"");
  delay(100);
  Serial1.println("AT+SAPBR=3,1,\"PWD\",\"\"");
  delay(100);
  Serial1.println("AT+SAPBR=1,1");  //Устанавливаем GPRS соединение
  delay(100);
  Serial1.println("AT+HTTPINIT");  //Инициализация http сервиса
  delay(100);

  char strOut[200]; 
  sprintf(strOut, "AT+HTTPPARA=\"URL\",\"http://api.pushingbox.com/pushingbox?devid=v810F5DBC791B54C&t25=%s&h25=%s&t50=%s&h50=%s&t75=%s&h75=%s&t1=%s&h1=%s\"", t25,h25,t50,h50,t75,h75,t1,h1);

  Serial1.println(strOut);
  Serial1.println("AT+HTTPPARA=\"CID\",1");  //Установка CID параметра для http сессии
  delay(100);
  Serial1.println("AT+HTTPACTION=1");
  Serial1.println("AT+HTTPTERM");



  // Print the values to the serial port
  Serial.print("Температура на 25 см: ");
    Serial.print(t25);
    Serial.print("ºC     ");
    Serial.print("Влажность на 25 см: ");
    Serial.print(h25);
    Serial.println(" %");



  Serial.print("Температура на 50 см: ");
    Serial.print(t50);
    Serial.print("ºC     ");
    Serial.print("Влажность на 50 см: ");
    Serial.print(h50);
    Serial.println(" %");


    Serial.print("Температура на 75 см: ");
    Serial.print(t75);
    Serial.print("ºC     ");
    Serial.print("Влажность на 75 см: ");
    Serial.print(h75);
    Serial.println(" %");



    Serial.print("Температура на 1 м:   ");
    Serial.print(t1);
    Serial.print("ºC     ");
    Serial.print("Влажность на 1 м:   ");
    Serial.print(h1);
    Serial.println(" %");


   
    Serial.println("осадки мм:   ");
    Serial.println(o);


delay(6000);
  
  ////////////////////////////////////////////////////////
  /*
    //void SubmitHttpPost()
    //{

    Serial1.println("AT");
    delay(100);

    //ShowSerialData();// this code is to show the data from gprs shield, in order to easily see the process of how the gprs shield submit a http request, and the following is for this purpose too.

    Serial1.println("AT+CIPSHUT");
    delay(100);

    //ShowSerialData();

    Serial1.println("AT+CIPSTATUS");
    delay(100);

    //ShowSerialData();


    Serial1.println("AT+SAPBR=2,1");
    delay(2000);

    Serial1.println("AT+SAPBR=1,1");
    //ShowSerialData();

    Serial1.println("AT+HTTPINIT");
    delay(100);


    Serial1.print("AT+HTTPPARA=\"URL\",\"http://api.pushingbox.com/pushingbox?devid=v7EB0C16B3DF61EB&t25=" (temp_c_25) "&h25=111&t50=27&h50=46&t75=5&h75=16&t1=7&h1=8&o=90\"");
    // setting the httppara, the second parameter is the website you want to access
    delay(36000);

    //ShowSerialData();

    Serial1.println("AT+HTTPACTION=1");//submit the request
    delay(10000);//the delay is very important, the delay time is base on the return from the website, if the return datas are very large, the time required longer.
    //while(!Serial1.available());

    //ShowSerialData();

     Serial1.println("AT+HTTPPARA=\"CID\",1");
    delay(100);

    //ShowSerialData();

    Serial1.println("AT+HTTPACTION=1");
    delay(100);

    //ShowSerialData();

    //Serial1.println("");
    //delay(100);


     Serial1.println("AT+HTTPTERM");
    delay(100);
  */



  ////////////////////////////////////////////////////////////////


}

void format(float value, char* result) {
  dtostrf(value, 0, 2, result);
}


