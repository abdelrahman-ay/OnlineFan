# Esp01 Smart Control

## About

Esp-01 WiFi module used to control fan speed using motor driver using IoT protocols like Blynk and MQTT
Use [installation](#Installation) and connect [[#BOM]] according to [[#Schematic]]

### Features
- 2 versions of connection(Blynk-MQTT)
- 2 channel communication protocol
- Motor speed control - Brightness control 
- Can be used with esp-01 WiFi module
- Can specify control messages 

## License

Published under the MIT license. Please see [license](license.txt) file

## Example Video
![Blynk](https://github.com/user-attachments/assets/32c7c02d-c2f8-4455-8e3d-dadd16c209c2)
![MQTT](https://github.com/user-attachments/assets/6cf44402-19e3-4bf0-a1f2-715a8441f3bc)

## Flow Chart

![FlowChart](/media/Flowchart.png)

## roadmap:

- [x] V1.0 Blynk method
- [x] V2.0 MQTT method
- [x] V3.0 Add support for fan speed
- [x] V3.1 Clean code for readability
- [ ] V4.0 Add OTA support
- [ ] V5.0 PCB design

## Installation

- Install PlatformIo extension in VSCode
- Add existing Project at platformio.ini file
- Copy required version to src folder
- (MQTT VERSION ONLY) Config credentials in initConnection.h and used pins in mqtt.h
- Build main.cpp
- connect pins to existing [[#Schematic]]

## BOM

![BOM](/media/BOM.pdf)
## Schematic

![Schematic](/media/Schematic1.SchDoc.PDF)
## Changelog

V1.0 Changelog

- Added blynk method

V2.0 Changelog

- Added basic MQTT example
- MQTT example reworked

V3.0 Changelog

- Added support for analog fan speed input
- Separated callback function from command execution function
- Improved command detection method

V3.1 Changelog

- Cleaned ESP Cam Code files
- Added extra files (for separation of functions)

V4.0 Changelog

- Added readme.md
- Added license file
- Added getting started steps
- Added schematic pdf
- Added BOM pdf

## Contact

<h4>
    <a href="https://www.linkedin.com/in/abdelrahman-ay/">LINKEDIN</a>
  <span> · </span>
    <a href="mailto:abdelrahman20012016@gmail.com">GMAIL</a>
  <span> · </span>
    <a href="tel:+201283430167">PHONE</a>
  <span> · </span>
    <a>WEBSITE</a>
  </h4>

 
