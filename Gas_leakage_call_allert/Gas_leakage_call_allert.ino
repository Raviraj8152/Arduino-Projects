// // Sender phone number with country code
// const String PHONE = "+918152815260";

// // GSM Module RX pin to ESP32 2
// // GSM Module TX pin to ESP32 4
// #define rxPin 16
// #define txPin 17
// HardwareSerial sim800(1);

// const int disconnectPin = 4; // Digital pin connected to the sensor
// const int buzzerPin = 23;     // Buzzer connected to pin 34

// void setup() {
//   pinMode(disconnectPin, INPUT);
//   pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  
//   Serial.begin(115200);
//   Serial.println("ESP32 serial initialize");
  
//   sim800.begin(9600, SERIAL_8N1, rxPin, txPin);
//   Serial.println("SIM800L serial initialize");

//   // Initialize SIM800L for SMS and call function
//   sim800.println("AT+CMGF=1"); // Set SMS to text mode
//   delay(1000);
//   sim800.println("AT+CMGD=1,4"); // Delete all saved SMS
//   delay(1000);
// }

// void loop() {
//   // Check if sensor pin goes HIGH
//   if (digitalRead(disconnectPin) == LOW) {
//     Serial.println("Gas Leakage Detected!");

//         // Turn on the buzzer
//     digitalWrite(buzzerPin, HIGH);
    
//     // Send SMS alert
//     // sendAlertSMS();

//     // Make a call
//     makeAlertCall();
    
//     // Delay to avoid multiple alerts in quick succession
//     delay(10000); // 10 seconds
//   }

//   else {
//     // No gas leakage detected, turn off the buzzer
//     digitalWrite(buzzerPin, LOW);
//   }
// }

// void sendAlertSMS() {
//   sim800.print("AT+CMGF=1\r"); // Set SMS to text mode
//   delay(1000);
//   sim800.print("AT+CMGS=\"" + PHONE + "\"\r"); // Send to phone number
//   delay(1000);
  
//   String alertMessage = "Alert: Gas Leakage Detected!";
//   sim800.print(alertMessage); // Send the message text
//   delay(100);
//   sim800.write(0x1A); // ASCII code for Ctrl+Z to send the SMS
//   delay(1000);
  
//   Serial.println("Alert SMS Sent Successfully.");
// }

// void makeAlertCall() {
//   sim800.println("ATD" + PHONE + ";"); // Dial the number
//   delay(20000); // Keep the call active for 20 seconds
//   sim800.println("ATH"); // Hang up the call
//   Serial.println("Call Made Successfully.");
// }




#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <HardwareSerial.h>

// Define I2C pins for ESP32
#define I2C_SDA 21
#define I2C_SCL 22

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Sender phone number with country code
const String PHONE = "+918152815260";

// GSM Module RX pin to ESP32 16
// GSM Module TX pin to ESP32 17
#define rxPin 16
#define txPin 17
HardwareSerial sim800(1);

const int disconnectPin = 4; // Pin connected to the sensor
const int buzzerPin = 23;     // Buzzer connected to pin 23

void setup() {
  pinMode(disconnectPin, INPUT);
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output

  Serial.begin(115200);
  Serial.println("ESP32 serial initialize");

  // Initialize SIM800L module
  sim800.begin(9600, SERIAL_8N1, rxPin, txPin);
  Serial.println("SIM800L serial initialize");

  sim800.println("AT+CMGF=1"); // Set SMS to text mode
  delay(1000);
  sim800.println("AT+CMGD=1,4"); // Delete all saved SMS
  delay(1000);

  // Initialize the LCD
  Wire.begin(I2C_SDA, I2C_SCL);
  lcd.begin();
  lcd.backlight();
  
  // Display initial message
  lcd.setCursor(0, 0);
  lcd.print("LPG Gas Detection");

}

void loop() {
  // Check if gas leakage is detected
  if (digitalRead(disconnectPin) == LOW) {
    Serial.println("Gas Leakage Detected!");

    // Turn on the buzzer
    digitalWrite(buzzerPin, HIGH);

    // Update the LCD display
    lcd.setCursor(0, 0); 
    lcd.print("Leakage Detected "); // Display on first line
    lcd.setCursor(0, 1);
    lcd.print("Call Alert Sent  "); // Display on second line

    // Send SMS and make call
    // sendAlertSMS();
    makeAlertCall();

    // Delay to avoid multiple alerts in quick succession
    delay(10000); // 10 seconds
  } else {
    // No gas leakage detected, turn off the buzzer
    digitalWrite(buzzerPin, LOW);

    // Update LCD to show monitoring status
    lcd.setCursor(0, 0);
    lcd.print("LPG Gas Detection"); // Keep this message on the first line
    lcd.setCursor(0, 1);
    lcd.print("Monitoring...    "); // Update second line to show "Monitoring"
  }
}

void sendAlertSMS() {
  sim800.print("AT+CMGF=1\r"); // Set SMS to text mode
  delay(1000);
  sim800.print("AT+CMGS=\"" + PHONE + "\"\r"); // Send to phone number
  delay(1000);

  String alertMessage = "Alert: Gas Leakage Detected!";
  sim800.print(alertMessage); // Send the message text
  delay(100);
  sim800.write(0x1A); // ASCII code for Ctrl+Z to send the SMS
  delay(1000);

  Serial.println("Alert SMS Sent Successfully.");
}

void makeAlertCall() {
  sim800.println("ATD" + PHONE + ";"); // Dial the number
  delay(20000); // Keep the call active for 20 seconds
  sim800.println("ATH"); // Hang up the call
  Serial.println("Call Made Successfully.");
}