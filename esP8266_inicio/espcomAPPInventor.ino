#include <ESP8266WiFi.h>
const char WiFiPassword[] = "";//Leave Blank if you do not want to have a password to enter the Node
const char AP_NameChar[] = "rodrigo" ;

WiFiServer server(80);

String request = "";
int LED_Pin = D0;

void setup()
{
  Serial.begin(115200);
  pinMode(LED_Pin, OUTPUT);
  digitalWrite(LED_Pin, LOW);//Turn on LED
  delay(400);
  digitalWrite(LED_Pin, HIGH);//Turn off LED
  WiFi.disconnect();
  boolean conn = WiFi.softAP(AP_NameChar, WiFiPassword);
  server.begin();
 


} 

void loop()
{

  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client)  {
    return;
  }

  // Read the first line of the request
  request = client.readStringUntil('\r');

  if       ( request.indexOf("LEDOFF") > 0 )  {
    digitalWrite(LED_Pin, LOW);
    //client.flush();
    client.println("HTTP/1.1 200 OK\r\n");
    client.println( "LEDON");
    client.flush();
    Serial.println("inside ON");
  }
  else if  ( request.indexOf("LEDON") > 0 ) {
    digitalWrite(LED_Pin, HIGH);
    //client.flush();
    client.println("HTTP/1.1 200 OK\r\n");
    client.println( "LEDOFF");
    client.flush();
    Serial.println("inside OFF");
  }
  delay(5);

}
