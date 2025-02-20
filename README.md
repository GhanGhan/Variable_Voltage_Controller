# Variable Voltage Controller
Desktop device that outputs a variable voltage whos value is controlled by the user.  The user will be able to monitor the input and output voltage and current.  This device will be suitable for prototyping, lab-bench testing and recreational purposes
![3D_View1](https://github.com/user-attachments/assets/0222784d-f8b2-4f9d-8bee-c49972aa614e)
![Top_Signal Layer](https://github.com/user-attachments/assets/28cae700-05df-46ca-88bc-d9f8d714b924)


# System Scope
The system will provide:
- A jack and terminal block for connecting to an external power supply with a range of 3-17V
- A screen to display the input voltage, input current, output voltage and output current in real time
- The ability to change the output voltage from 1.3V to 20V
- Terminal block connectors that allow an external load to connect to this device
# System Overview
An external power supply connects to the device via the input connectors.  The voltage is stepped down to 3.3V to power the display, microcontroller, and voltage controller.  A voltage and current sensor measures the external power supply’s voltage and current output and sends the readings to the microcontroller.  The user can operate the voltage controller to adjust the voltage sent to the output connector, which involves either a buck or boost conversion as the output voltage can range from 0 to 20V.  Another set of voltage and current sensors measures the voltage and current delivered to the load and sends those readings to the microcontroller.  The microcontroller processes the signals received from the sensors and sends the processed data to the display, allowing the user to view the voltage and current supplied by the external power supply as well as the voltage and current delivered to the load.

![Variable Voltage Converter Block Diagram](https://github.com/user-attachments/assets/820230b2-cb31-4bf0-b403-fd2d67b47592)

# Power 
![Power](https://github.com/user-attachments/assets/2997ac6a-9d08-4582-9637-3b40fb22a77a)
## System Power Input
- Power source connects to the device via a jack or a screw terminal block
- Systems needs at least 3V, and input voltage should not exceed 17V
-	Power Multiplexer circuit acts like an OR-GATE, automatically allows the higher input voltage to power the device
-	Supplies power to the 3.3V buck converter and the buck boost converter
## 3V3 Priority Power Multiplexing
-	Either the 3.3V buck converter or the 3.3V pin from the ST-Link programmer interface can be used to power the 3.3V circuitry
-	Priority is given to the buck converter
## Variable Power Output
-	Can deliver between 1.32V to 20V and up to 4A current
-	Potentiometer in the feedback circuitry allows the suer to control the output voltage
## Variable Power Output
-	LDO used to power the LCD screen, as the nominal input voltage is 3V
## Power-On Indicator
- Indicates whether the system is receiving power

# Microcontroller
![Microcontroller](https://github.com/user-attachments/assets/fb5508e2-9901-45b2-86a0-6fb54de6729d)
-	Powered by 3.3V and uses a 16MHz clock
-	Can be programmed/debugged via the SWD interface
- Senses the input current and voltage as well as the output current and voltage via the ADC pins
- Communicates with the LCD display via the SPI interface

# Sensors
![Sensors](https://github.com/user-attachments/assets/b217a8b5-d91f-4c90-83cd-475027d0d3ba)
## Current Sensors
- Composed of an 11 mΩ current-shunt resistor and a difference amplifier with a 75V/V gain
- Senses uni-directional voltage up to 4A, scales output to 3.3V 
## Voltage Sensors
- Made using a voltage divider circuit
- Appropriately scaled so that the max voltage it experiences will output to 3.3V approximately

# Display
![Display](https://github.com/user-attachments/assets/77a6e472-e37b-4479-b55f-0bde12dcc57e)
-	Powered by 3.0V
-	Has a backlight that is always on
-	Receives information about the systems from the microcontroller via SPI and updates the display at 10Hz


