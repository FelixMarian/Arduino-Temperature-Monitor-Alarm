# Arduino Temperature Monitor Alarm

This project controls a system that monitors temperature using a temperature sensor (connected to pin A0) and displays the temperature on an LCD screen. It also features LED indicators (green, yellow, and red) and a buzzer to alert when the temperature exceeds a predefined threshold.

## Table of Contents
- [Components Used](#components-used)
- [Circuit Diagram](#circuit-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [Acceleration and Deceleration Cycles](#acceleration-and-deceleration-cycles)
- [Arduino Code Explanation](#arduino-code-explanation)
- [Note Regarding Practical Demonstration](#Note Regarding Practical Demonstration)
- [License](#license)
- [Credits](#credits)

## Components Used
- 1x Arduino UNO
- 2x Breadboard
- 1x LM35DZ temperature sensor
- 2x Push-button
- 1x 100 Ω Resistor
- 4x 220 Ω Resistor
- 2x 1 kΩ Resistor
- 1x 10 kΩ Potentiometer
- 1x LCD 16x2
- 1x Buzzer
- (A lot)x Male-to-male jumper wires

## Circuit Diagram
![Tinkercad-assembly](https://github.com/FelixMarian/Arduino-Temperature-Monitor-Alarm/blob/main/Diagrams/Tinkercad-assembly.png)

## Installation
1. **Connect the Components**: Wire up the components according to the provided circuit diagram. Ensure a proper connection between the components.
2. **Upload Arduino Code**: Upload the provided Arduino code (`Arduino-Temperature-Monitor-Alarm.ino.ino`) to your Arduino board using the Arduino IDE or any other suitable software.

## Usage
1. **Using the Buttons**: Press the left button to decrease the temperature threshold by 5 degrees Celsius and the right button to increase it by 5 degrees Celsius.
   - Press and release the left button to decrease the threshold.
   - Press and release the right button to increase the threshold.
2. **Observing Temperature Threshold**: The current and adjusted temperature thresholds will be displayed on a 16x2 LCD screen connected to the Arduino.

## Arduino Code Explanation

This project implements a temperature monitoring and control system using various components such as an LCD, LEDs, buttons, and a buzzer.

- **LCD Initialization**: The LiquidCrystal library is utilized to initialize and configure the LCD screen with the specified pins.

- **Pin Declarations**: Pins for the LCD, LEDs, buttons, buzzer, and temperature sensor are declared with their corresponding Arduino pin numbers.

- **Setup Function**: In the `setup()` function:
  - The `pinMode()` function is used to set the pins as either inputs or outputs.
  - The LCD is initialized with its dimensions.
  - Serial communication is initiated for debugging purposes.

- **Loop Function**: In the `loop()` function:
  - The temperature is continuously monitored using the `getTempC()` function.
  - Information about the current temperature and the maximum temperature threshold is displayed on the LCD using the `showStats()` function.
  - The LEDs and buzzer are controlled based on the measured temperature using the `setAlarmNLeds()` function.
  - The maximum temperature threshold can be adjusted by pressing the buttons.

- **getTempC() Function**: Calculates the current temperature in Celsius degrees using the voltage readings from the temperature sensor.

- **showStats() Function**: Prints the current temperature and the maximum temperature threshold on the LCD screen, ensuring proper formatting even when the temperature value transitions from three digits to two digits.

- **setAlarmNLeds() Function**: Adjusts the LEDs and buzzer based on the measured temperature:
  - If the temperature is below 90% of the maximum threshold, only the green LED is turned on.
  - If the temperature is between 91% and 100% of the maximum threshold, both the green and yellow LEDs are turned on.
  - If the temperature exceeds the maximum threshold, all LEDs (green, yellow, and red) are turned on, and the buzzer emits a sound with a fading effect.

This code provides a comprehensive solution for temperature monitoring and control, allowing users to set thresholds and receive alerts based on temperature conditions.

## Note Regarding Practical Demonstration

Please note that in the provided demonstration video (`video.mp4`), due to issues with the physical temperature sensor, a constant real temperature has been simulated in the code. The demonstration showcases how the system responds to temperature threshold adjustments using the buttons provided in the setup.

## License
This project is licensed under the [MIT License](LICENSE).

## Credits
- **Author**: Felix-Marian STOENOIU
- **Email**: Stoenoiu.Felix1@gmail.com
- **GitHub**: [My GitHub profile](https://github.com/FelixMarian)

