#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "LAB_02.65";
const char* password =  "CONNECT2LAB";
int photoTran = 12;
int deRoos = 0;
 
void setup() {

  pinMode(photoTran,INPUT);
   
  Serial.begin(9600);
  delay(4000);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
}
 
void loop() {
 
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status

    if (digitalRead(photoTran) == false)
    {
       
      HTTPClient http;
   
      http.begin("http://172.20.101.121:8080/api"); //Specify the URL
          // Specify content-type header
      http.addHeader("Content-Type", "application/json");
      
      // Data to send with HTTP POST
      // Send HTTP POST request
      int httpResponseCode = http.POST("{\"value\" : 1}");
      Serial.print("response: ");
      Serial.println(httpResponseCode);
   
      http.end(); //Free the resources
      delay(1000);
    }
  }
}
