# Main Objective Of Repository  
- Display the :
    - Analog data generated from a potentiometer
    - A random number generated from an ESP8266

- Display the mentioned data to an HTML website
- Also provide two radio buttons on the mentioned website for GPIO manipulation for the Digital I/O ports on the ESP 8266

# Bill of Material(s)
- (1) ESP 8266
- (1) Optional OLED Display with the SH1106 Driver
- (1) Resistor of any value
- (1) Potentiometer

# Circuit Diagram Generated In Autodesk EAGLE
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

## AJAX, Asynchronous JavaScript And XML

What's the big deal with [AJAX](https://developer.mozilla.org/en-US/docs/Web/Guide/AJAX/Getting_Started)
- Uses the [XMLHttpRequest](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest) object to communicate with servers, which in this case is the ESP8266
- Using AJAX allows the user to send and recieve the mentioned data formats below asynchronously; without having to refresh the website
  - JSON
  - XML
  - HTML
  - Text files

## Displaying The Data and Google Charts

Displaying data on an Espressif-based microcontroller to a website isn't new

But displaying the data with a chart on the other hand is something I couldn't find much about, hence the main motivation on creating this repository

Then I stumbled upon [Google Charts](https://developers.google.com/chart)

For this repository, I used the [gague charts](https://developers.google.com/chart/interactive/docs/gallery/gauge) that were provided
