/*
 * ESP8266 NodeMCU AJAX Demo
 * Updates and Gets data from webpage without page refresh
 */
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "U8g2lib.h"
#include <Wire.h>
#include "index.h" // Header file with HTML/JS Scripts for webpage

#define LED_WHITE 14
#define LED_GREEN 12
const char *ssid = "INSERT_WIFI_NETWORK_HERE";
const char *password = "INSERT_WIFI_PASSWORD_HERE";
int a;
String t_state, ledState;
// Create ESP8266WebServer class object | Server on port 80
ESP8266WebServer server(80);
U8G2_SH1106_128X64_NONAME_F_HW_I2C OLED(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

void handleRoot()
{
  /*
      MAIN_page[] 
        - What is it
          - A constant char array that holds all the HTML/JS scripts for the webpage
          - Storing it as a seperate header file makes things "Easier" to read in the CPP/Sketch file
  */
  String s = MAIN_page;
  /*
      server.send()
        - Sends responses to the client
        - Parameters server.send(code,content_type,content);
          - code : HTTP response code
            - Can be 200 (OKAY) or 404 (NOT FOUND)
          - content_type : HTTP content, for example :
            - text/plain
            - image/png
          - content : actual concent body
  */
  server.send(200, "text/html", s); //Send web page
}

// Read ADC values from potentiometer
void handleADC()
{
  a = analogRead(A0);
  String adcValue = String(a);

  //Serial.print("ADC : ");
  //Serial.println(a);
  OLED.setCursor(5, 15);
  OLED.print("ADC Value:");
  OLED.setCursor(80, 15);
  OLED.print(a);

  // Send ADC value when the webpage makes a ajax request
  server.send(200, "text/plane", adcValue);
}

// Generate and send random number
void randomNum()
{
  float randomNumber;

  randomNumber = random(5);
  String randomNum_value = String(randomNumber);

  // send() command needs the value to be stored as a string
  server.send(200, "text/plane", randomNum_value);
}
// Generate and send random number
void randomNum2()
{
  float randomNumber2;

  randomNumber2 = random(75);
  String randomNum_value2 = String(randomNumber2);

  // send() command needs the value to be stored as a string
  server.send(200, "text/plane", randomNum_value2);
}
void handleLED()
{
  ledState = "OFF";

  /*
      server.arg()
        - Returns the number of query parameters that were passed on the HTTP request
          that triggered the execution of the handling function
        - Refer  xhttp.open("GET", "setLED?LEDstate="+LED_WHITE, true); in index.h file
  */
  t_state = server.arg("LEDstate");
  Serial.print("LED_WHITE State : ");
  Serial.println(t_state);

  if (t_state == "1")
  {
    digitalWrite(LED_WHITE, HIGH);
    // Parameter sent back to webpage
    ledState = "ON";
  }
  else
  {
    digitalWrite(LED_WHITE, LOW);
    // Parameter sent back to webpage
    ledState = "OFF";
  }

  // LED_WHITE state sent to webpage
  server.send(200, "text/plane", ledState);
}

void setup(void)
{
  Serial.begin(115200);

  OLED.setI2CAddress(0x3C * 2);
  OLED.begin();
  OLED.setFont(u8g2_font_mozart_nbp_t_all);

  WiFi.begin(ssid, password);
  Serial.println("");

  pinMode(LED_WHITE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(250);
    Serial.print(".");
  }

  // Show IP if connecting ot WiFi was successful
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Specify which routine handles what
  server.on("/", handleRoot);
  server.on("/setLED", handleLED);
  server.on("/readADC", handleADC);
  server.on("/randomNum", randomNum);
  server.on("/barADC", handleADC);

  // Start server
  server.begin();
  Serial.println("HTTP server started");
}

void loop()
{
  //Handle client requests | Looks for pending requests
  server.handleClient();

  a = analogRead(A0);
  //t_state = server.arg("LEDstate");

  String adcValue = String(a);
  //Serial.print("ADC : ");
  //Serial.println(a);
  OLED.setCursor(5, 15);
  OLED.print("ADC Value:");
  OLED.setCursor(80, 15);
  OLED.print(a);

  OLED.setCursor(5, 30);
  OLED.print("LED Status:");

  OLED.setCursor(80, 30);
  OLED.print(ledState);

  OLED.setCursor(5, 45);
  OLED.print("---- ESP Address ----");

  OLED.setCursor(30, 60);
  OLED.print(WiFi.localIP());

  OLED.sendBuffer();
  OLED.clearBuffer();
}