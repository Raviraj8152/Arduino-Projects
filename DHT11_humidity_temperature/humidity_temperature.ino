// #include "DHT.h"
// #include <LiquidCrystal_I2C.h>
// #include <Wire.h>


// #define DHTPIN1 4       // Pin to connect the first DHT sensor (GPIO number)
// #define DHTPIN2 2       // Pin to connect the second DHT sensor (GPIO number)
// #define DHTTYPE DHT11   // Define DHT 11 or DHT22 sensor type


// DHT dht1(DHTPIN1, DHTTYPE);  // Create DHT object for first sensor
// DHT dht2(DHTPIN2, DHTTYPE);  // Create DHT object for second sensor
// // Set the LCD address to 0x27 for a 16 chars and 2 line display
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// void setup() {
//   Serial.begin(9600);
//   dht1.begin();  // Initialize the first DHT sensor
//   dht2.begin();  // Initialize the second DHT sensor
//     // Initialize the LCD
//   Wire.begin(I2C_SDA, I2C_SCL);
//   lcd.begin();
//   lcd.backlight();
// }

// void loop() {
//   delay(1000);
  
//   // Read temperature from both sensors in Celsius
//   float t1 = dht1.readTemperature(false);  // Sensor 1 temperature in C
//   float t2 = dht2.readTemperature(false);  // Sensor 2 temperature in C

//   // Check if readings are valid, otherwise print error
//   if (isnan(t1) || isnan(t2)) {
//     Serial.println("Failed to read from DHT sensor(s)");
//     return;
//   }

//   // Print the temperatures
//   Serial.print("Temp Sensor 1: ");
//   Serial.print(t1);
//   Serial.println(" C");

//   Serial.print("Temp Sensor 2: ");
//   Serial.print(t2);
//   Serial.println(" C");
// }




#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// Define I2C pins for ESP32
#define I2C_SDA 21
#define I2C_SCL 22

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);  

// DHT11 sensor pin definitions
#define DHTPIN1 4  // Pin to connect the first DHT sensor (GPIO number)
#define DHTPIN2 23  // Pin to connect the second DHT sensor (GPIO number)
#define DHTTYPE DHT11  // Define DHT 11 or DHT22 sensor type

DHT dht1(DHTPIN1, DHTTYPE);  // Create DHT object for first sensor
DHT dht2(DHTPIN2, DHTTYPE);  // Create DHT object for second sensor

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize the DHT sensors
  dht1.begin();
  dht2.begin();

  // Initialize the I2C LCD display
  lcd.begin();
  lcd.backlight();  // Turn on the LCD backlight
  lcd.clear();
  // Print an initial message to the LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp1: -- C");
  lcd.setCursor(0, 1);
  lcd.print("Temp2: -- C");
}

void loop() {
  delay(1000);
  
  // Read temperature from both sensors in Celsius
  float t1 = dht1.readTemperature(false);  // Sensor 1 temperature in C
  float t2 = dht2.readTemperature(false);  // Sensor 2 temperature in C

  // Check if readings are valid, otherwise print error
  if (isnan(t1) || isnan(t2)) {
    lcd.clear();
    Serial.println("Failed to read from DHT sensor(s)");
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    return;
  }
  lcd.clear();
  // Print the temperatures to Serial Monitor
  Serial.print("Temp Sensor 1: ");
  Serial.print(t1);
  Serial.println(" C");
  
  Serial.print("Temp Sensor 2: ");
  Serial.print(t2);
  Serial.println(" C");

  // Display the temperatures on the LCD
  lcd.setCursor(0, 0);  // Set the cursor to the first row
  lcd.print("Temp1: ");
  lcd.print(t1);
  lcd.print(" C ");

  lcd.setCursor(0, 1);  // Set the cursor to the second row
  lcd.print("Temp2: ");
  lcd.print(t2);
  lcd.print(" C ");
}
