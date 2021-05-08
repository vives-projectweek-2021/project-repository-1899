#include <WiFi.h>
#include <HTTPClient.h>
 
const char* ssid = "WiFi-2.4-4050";
const char* password =  "WhNY3jFtp555";
int photoTran = 15;
int deRoos = 0;
 
void setup() {

  pinMode(photoTran,INPUT);
   
  Serial.begin(115200);
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
   
      http.begin("http://192.168.1.17:8080/api"); //Specify the URL
          // Specify content-type header
      http.addHeader("Content-Type", "application/json");
      
      // Data to send with HTTP POST
      // Send HTTP POST request
      int httpResponseCode = http.POST("{\"value\" : 1}");
      Serial.print("response: ");
      Serial.println(httpResponseCode);
   
      http.end(); //Free the resources
      delay(1);
    }
  }
}
