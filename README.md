# Main Objective Of Repository  
- Provide an example that uses AJAX communication between an ESP8266 and a HTML website to:
  - Display the following data on an HTML website using Google Charts :
    - Varying voltage from a potentiometer that's being sampled by the ESP8266 Analog to Digital converter
    - A random number generated from the ESP8266.
  - Provide two radio buttons on the same website that's displaying the mentioned information to allow the user to control a Digital I/O port on the ESP 8266.


<br>

# Items Needed
- (1) ESP 8266
- (1) OPTIONAL OLED Display with the SH1106 Driver
- (1) Resistor of any value
- (1) Potentiometer

<br>


# Circuit Diagram Overview 
### Generated in Autodesk EAGLE

![image](https://user-images.githubusercontent.com/39348633/141209415-88d050c6-39d0-4259-a6f1-ef40b1c957fa.png)

<br>

# Table Summerization of the Circuit Diagram  Above

<br>

| Component | Connection on ESP|
| :---: | :---: |
| Potentiometer (Pin1/Left-most Pin)| 3.3 Volts |
| Potentiometer (Pin2/Middle Pin) | AD0 |
| Potentiometer (Pin3/Right-most Pin)| GND |
| OLED (SDA) | D2 |
| OLED (SCL) | D1 |
| OLED (VCC) | 3.3 Volts |
| OLED (GND) | GND |
| LED  | D5 |

---

<br>


# High Level Overview Of What's Going On

## What's [Asynchronous JavaScript And XML (AJAX)](https://developer.mozilla.org/en-US/docs/Web/Guide/AJAX/Getting_Started).

Using AJAX allows the user to send and recieve the following data formats below asynchronously; without having to refresh the entire website by using [XMLHttpRequest](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest)
  - JSON
  - XML
  - HTML
  - Text files

<br>

## AJAX vs HTTP

In most basic IoT examples that use Espressif based boards like the ESP8266/32 use HyperText Transfer Protocol (HTTP) to display data on a website.

It gets the job done, but it falls short in the mentioned points below when using it for most IoT applications

<br>


## 1) HTTP only allows 1-1 communication.

HTTP was designed to communicate between two systems at one time.

In IoT applications, this is far from ideal.

For example :
  - Large industries/manufacturing units that have numerous sensors taking/pushing data to a server MUST wait for a request from the client (The user) to be made if HTTP was being used.
  - Once the request is recieved, the client must wait for the server to respond.
  - This process eats up valuable time and is overall an EXTREMELY slow way to transmit data.
  
<br>

## 2) HTTP wasn't made for event-based communication.

Most IoT applications have sensors that measure things like :
  - Temperature.
  - Air quality.
  - Ect.

Such parameters can be used to trigger a relay or some other peripheral.

Since HTTP was made for a REQUEST-RESPONSE based communication vs an EVENT-DRIVEN communication, the ESP must wait for the client (You, the user) to make a request for the server (The ESP8266) to respond accordingly.

<br>

---

## Displaying The Data and Google Charts

Displaying data on an Espressif-based microcontroller to a website isn't new.

But displaying the data with a chart on the other hand is something I couldn't find much about, hence the main motivation on creating this repository.

Then I stumbled upon [Google Charts](https://developers.google.com/chart).

For this repository, I used the [gague charts](https://developers.google.com/chart/interactive/docs/gallery/gauge) that were provided.

Detailed comments about how the Google Chart(s) were implimented into this project can be found in the index.h/html file
