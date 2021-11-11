# Main Objective Of Repository  
- Display the following data on an HTML website using Google Charts :
    - Analog data generated from a potentiometer 
    - A random number generated from an ESP8266
- Also provide two radio buttons on the mentioned website for GPIO manipulation for the Digital I/O ports on the ESP 8266

# Items Needed
- (1) ESP 8266
- (1) Optional OLED Display with the SH1106 Driver
- (1) Resistor of any value
- (1) Potentiometer

# Circuit Diagram Overview 
### Generated in Autodesk EAGLE

![image](https://user-images.githubusercontent.com/39348633/141209415-88d050c6-39d0-4259-a6f1-ef40b1c957fa.png)

# Table Summerization of the Circuit Digram Above

| Component | Connection on ESP|
| :---: | :---: |
| Potentiometer (Pin1)| 3.3 Volts |
| Potentiometer (Pin2) | AD0 |
| Potentiometer (Pin3)| GND |
| OLED (SDA) | D2 |
| OLED (SCL) | D1 |
| OLED (VCC) | 3.3 Volts |
| OLED (GND) | GND |
| LED  | D5 |

# High Level Overview Of What's Going On

## Asynchronous JavaScript And XML (AJAX) 

In most IoT examples that use Espressif based boards like the ESP8266/32 use HyperText Transfer Protocol (HTTP) to display data on a website.

Despite HTTP being a reliable IoT communication protocol, it falls short as described in the following points:

---
## Only allows 1-1 communication
HTTP was designed to communicate between two systems at one time

In IoT applications, this is far from ideal
- Example : Large industries/manufacturing units could have numerous sensors that are generating and pushing data to a server at the same time.
- Once a request is made, the client has to wait for the server to respond, which freezes up the entire program and overall is an extremely slow way to send data.
---

## HTTP wasn't made for event-based communication
Most IoT applications are event based.
  - Example : Sensors that measure things like
    - Temperature
    - Air quality
    - Ect.
  - Such parameters are used to manipulate peripherals like a relay

HTTP was made for a REQUEST-RESPONSE based communication vs an EVENT-DRIVEN communication

---

## [AJAX](https://developer.mozilla.org/en-US/docs/Web/Guide/AJAX/Getting_Started) allows bi-directional communication 

Between the ESP8266 and the HTML website that enables the user to:
  - Control the GPIO pins via the website 
  - Be able to observe both the ADC values and the random numbers being generated from the ESP8266 and being sent to the website

---

## What's the big deal with [AJAX](https://developer.mozilla.org/en-US/docs/Web/Guide/AJAX/Getting_Started)

Uses the [XMLHttpRequest](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest) object to communicate with servers, which in this case is the ESP8266

Using AJAX allows the user to send and recieve the mentioned data formats below asynchronously; without having to refresh the entire website
  - JSON
  - XML
  - HTML
  - Text files

---

## Displaying The Data and Google Charts

Displaying data on an Espressif-based microcontroller to a website isn't new

But displaying the data with a chart on the other hand is something I couldn't find much about, hence the main motivation on creating this repository

Then I stumbled upon [Google Charts](https://developers.google.com/chart)

For this repository, I used the [gague charts](https://developers.google.com/chart/interactive/docs/gallery/gauge) that were provided
