#include <LiquidCrystal.h>

// Declaration of LCD pins
const int RS = 13;
const int E = 12;
const int DB4 = 11;
const int DB5 = 10;
const int DB6 = 9;
const int DB7 = 8;

LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);

// Declaration of variable pins
const int g_led = 4;
const int y_led = 5;
const int r_led = 6;
const int btn_dec = 2;
const int btn_inc = 3;
const int buzzer = 7;
const int tmp_sens = A0;

float voltage;
int max_temp = 30;
int curr_temp;

void setup() {
  // Setting up pinModes for each pin
  pinMode(RS, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(DB4, OUTPUT);
  pinMode(DB5, OUTPUT);
  pinMode(DB6, OUTPUT);
  pinMode(DB7, OUTPUT);
  pinMode(g_led, OUTPUT);
  pinMode(y_led, OUTPUT);
  pinMode(r_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(btn_dec, INPUT);
  pinMode(btn_inc, INPUT);
  pinMode(tmp_sens, INPUT);

  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  getTempC(tmp_sens); // Constantly getting the temperature
  showStats();        // After each temperature measured, print the info to LCD
  // Check if the requirements are met to set the LEDs and buzzer accordingly
  setAlarmNLeds();
  // Modify the maximum temperature threshold with 5 degrees on the press of a button
  // One button is for increasing it, and the other one for decreasing it
  if (digitalRead(btn_inc) == HIGH)
    max_temp += 5;
  else if (digitalRead(btn_dec) == HIGH)
    max_temp -= 5;
}

// Getting the temperature in Celsius degrees using some formulas
float getTempC(int pin) {
  voltage = (analogRead(pin) * 0.004882814);
  curr_temp = (voltage - 0.5) * 100.0;
}

// Function that prints on the LCD the info, current temperature and maximum temperature
void showStats() {
  lcd.setCursor(0, 0);
  lcd.print("Current temp:");
  // This IF statement handles cases where the temperature drops from 3 digits to 2 digits,
  // clearing the last digit.
  if (curr_temp >= 100)
    lcd.print(curr_temp);
  else {
    lcd.print(curr_temp);
    lcd.print(" ");
  }
  lcd.setCursor(0, 1);
  lcd.print("Max temp: ");
  lcd.print(max_temp);
}

/*
This function adjusts the LEDs and buzzer based on the measured temperature.
- When the current temperature is within 0 to 90% of the maximum temperature threshold,
only the green LED is turned on.
- When the current temperature is within 91 to 100% of the maximum temperature threshold,
both the green and yellow LEDs are turned on.
- If the current temperature exceeds the maximum temperature threshold,
all three LEDs (green, yellow, and red) are turned on, and the buzzer emits sounds.
*/
void setAlarmNLeds() {
  if (curr_temp < (max_temp * 0.9)) {
    digitalWrite(g_led, HIGH);
    digitalWrite(y_led, LOW);
    digitalWrite(r_led, LOW);
    noTone(buzzer);
  }
  else if (curr_temp >= (max_temp * 0.9) && curr_temp < max_temp) {
    digitalWrite(g_led, HIGH);
    digitalWrite(y_led, HIGH);
    digitalWrite(r_led, LOW);
    noTone(buzzer);
  }
  else {
    digitalWrite(g_led, HIGH);
    digitalWrite(y_led, HIGH);
    digitalWrite(r_led, HIGH);
    // Here I wanted to make a fade effect for the sound, therefore I used for loops
    for (int i = 200; i <= 1000; i += 25) {
      tone(buzzer, i);
      delay(15);
    }
    delay(20);
    for (int i = 1000; i >= 200; i -= 25) {
      tone(buzzer, i);
      delay(15);
    }
    delay(20);
  }
}
