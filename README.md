# Overview
Desktop device that outputs a variable voltage whos value is controlled by the user.  The user will be able to monitor the input and output voltage and current.  This device will be suitable for prototyping, lab-bench testing and recreational purposes.
**The firmware for this projected is in the "Program" folder**
<img width="1753" height="1071" alt="Adjusted" src="https://github.com/user-attachments/assets/2edda560-392f-467c-8678-44168af7e8bd" />
## Notable Features!!!!!!
- Reverse voltage protection
- Power multiplexing between the input voltage terminal block and input voltage jack (explanation of circuit in section Schematic->Power->System Power Input)
  - **Allows user to hot-swap power sources while minimzing conduction losses!!!!**
- Real time voltage and current updates
<img width="3802" height="2294" alt="Labelled" src="https://github.com/user-attachments/assets/d77dbf2f-d36c-4764-9b36-617134c6021b" />

## PCB Notes
- 6-Layer stackup: Signal/GNDD/VCC/PGND/AGND/Signal
- Manufactured by JLCPCB
<img width="1237" height="788" alt="PCB View" src="https://github.com/user-attachments/assets/32733f73-9e1e-46c7-9c09-df14d8dbefa2" />

# System Architecture
The system provides:
- A jack and terminal block for connecting to an external power supply with a range of 3-17V
- A screen to display the input voltage, input current, output voltage and output current in real time
- The ability to change the output voltage from 1.3V to 20V
- Terminal block connectors that allow an external load to connect to this device
<img width="3935" height="2104" alt="Block Diagram" src="https://github.com/user-attachments/assets/76be301a-cbb4-4697-87c2-f9112a4264fc" />

## System Description
An external power supply connects to the device via the input connectors.  The voltage is stepped down to 3.3V to power the display, microcontroller, and voltage controller.  A voltage and current sensor measures the external power supply’s voltage and current output and sends the readings to the microcontroller.  The user can operate the voltage controller to adjust the voltage sent to the output connector, which involves either a buck or boost conversion as the output voltage can range from 0 to 20V.  Another set of voltage and current sensors measures the voltage and current delivered to the load and sends those readings to the microcontroller.  The microcontroller processes the signals received from the sensors and sends the processed data to the display, allowing the user to view the voltage and current supplied by the external power supply as well as the voltage and current delivered to the load.

# Schematics
## Power 
<img width="1773" height="983" alt="Power" src="https://github.com/user-attachments/assets/0c2cf3ff-ab5f-4155-ab94-22b589c5eac6" />


### System Power Input
- Power source connects to the device via a jack or a screw terminal block
- Systems needs at least 3V, and input voltage should not exceed 17V
-	Power Multiplexer circuit acts like an OR-GATE, automatically allows the higher input voltage to power the device
-	For more information about the circuit operation: [Basics of Ideal Diodes](https://www.ti.com/lit/an/slvae51a/slvae51a.pdf?ts=1756570557169&ref_url=https%253A%252F%252Fwww.google.com%252F)
-	Supplies power to the 3.3V buck converter and the buck-boost converter
### 3V3 Priority Power Multiplexing
-	Either the 3.3V buck converter or the 3.3V pin from the ST-Link programmer interface can be used to power the 3.3V circuitry
-	Priority is given to the buck converter
-	For more information about the circuit operation: [Basics of Power MUX](https://www.ti.com/lit/an/slvae51a/slvae51a.pdf?ts=1756570557169&ref_url=https%253A%252F%252Fwww.google.com%252F)
### Variable Power Output
-	Can deliver between 1.32V to 20V and up to 4A current
-	Maximum output power for each voltage given by: $P_O = \frac{5}{3}V_I + 10$
-	Potentiometer in the feedback circuitry allows the user to control the output voltage
### 3V LDO - Display Power
-	LDO used to power the LCD screen, as the nominal input voltage is 3V
### Power-On Indicator
- Indicates whether the system is receiving power

## Microcontroller
<img width="1087" height="977" alt="Microcontroller" src="https://github.com/user-attachments/assets/0a5e8968-7693-43a3-8bdd-6a705bfa19c6" />

-	Powered by 3.3V and uses a 16MHz clock
-	Can be programmed/debugged via the SWD interface
- Senses the input current and voltage as well as the output current and voltage via the ADC pins
- Communicates with the LCD display via the SPI interface

## Sensors
<img width="1301" height="832" alt="Sensors" src="https://github.com/user-attachments/assets/0598e9c8-049d-4041-bd50-eaddb18ed854" />

### Current Sensors
- Composed of an 11 mΩ current-shunt resistor (shown in **Power Schematic**) and a difference amplifier with a 50V/V gain
- Senses uni-directional current up to 4A, scales output to 3.3V 
### Voltage Sensors
- Made using a voltage divider circuit
- Appropriately scaled so that the max voltage it experiences will output to 3.3V approximately

## Display
<img width="616" height="385" alt="LCD" src="https://github.com/user-attachments/assets/477fb470-b908-4cfa-8df0-e43eb662042a" />

-	Powered by 3.0V
-	Has a backlight that is always on
-	Receives information about the system from the microcontroller via SPI 
- Display has a refresh rate of 10Hz


