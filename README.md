# Variable Voltage Controller
Desktop device that outputs a variable voltage whos value is controlled by the user.  The user will be able to monitor the input and output voltage and current.  This device will be suitable for prototyping, lab-bench testing and recreational purposes
# System Scope
The system will provide:
- A jack and terminal block for connecting to an external power supply with a range of 5-10V
- A screen to display the input voltage, input current, output voltage and output current in real time
- The ability to change the output voltage from 0V to 20V
- Terminal block connectors that allow an external load to connect to this device
# System Overview
An external power supply connects to the device via the input connectors.  The voltage is stepped down to 3.3V to power the display, microcontroller, and voltage controller.  A voltage and current sensor measures the external power supply’s voltage and current output and sends the readings to the microcontroller.  The user can operate the voltage controller to adjust the voltage sent to the output connector, which involves either a buck or boost conversion as the output voltage can range from 0 to 20V.  Another set of voltage and current sensors measures the voltage and current delivered to the load and sends those readings to the microcontroller.  The microcontroller processes the signals received from the sensors and sends the processed data to the display, allowing the user to view the voltage and current supplied by the external power supply as well as the voltage and current delivered to the load.

![Variable Voltage Converter Block Diagram](https://github.com/user-attachments/assets/820230b2-cb31-4bf0-b403-fd2d67b47592)



