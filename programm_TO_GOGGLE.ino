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
 


  int t25;
  int h25;
  int t50;
  int h50;
  int t75;
  int h75;
  int t1;
  int h1;
  int o;



  // Read values from the sensor 25 cm
  t25 = sht1x_1.readTemperatureC();
  h25 = sht1x_1.readHumidity();
  Serial1.print(t25);
  Serial1.print(h25);
  


 // Read values from the sensor 50 cm
  t50 = sht1x_2.readTemperatureC();
  h50 = sht1x_2.readHumidity();
  Serial1.print(t50);
  Serial1.print(h50);
  

 // Read values from the sensor 75 cm
  t75 = sht1x_3.readTemperatureC();
  h75 = sht1x_3.readHumidity();
  Serial1.print(t75);
  Serial1.print(h75);



 // Read values from the sensor 1 m
  t1 = sht1x_4.readTemperatureC();
  h1 = sht1x_4.readHumidity();
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
  Serial1.println("AT+HTTPPARA=\"URL\",\"http://api.pushingbox.com/pushingbox?devid=v7EB0C16B3DF61EB&t25=t25&h25=h25&t50=t50&h50=h50&t75=t75&h75=h75&t1=t1&h1=h1&o=o\"");
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


    Serial.print(o);
    Serial.print("осадки мм:   ");


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


