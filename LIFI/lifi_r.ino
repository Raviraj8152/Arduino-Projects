// #define RECEIVE_PIN 4   // Digital input pin for receiving data

// volatile unsigned long last_interrupt_time = 0;
// volatile unsigned long bit_time = 0;
// volatile int bit_count = 0;
// char received_text[200];
// int receive_index = 0;

// void setup() {
//   Serial.begin(9600);
//   attachInterrupt(digitalPinToInterrupt(RECEIVE_PIN), handleInterrupt, CHANGE);
// }

// void loop() {
//   // Check if we received a complete message
//   if (bit_count >= 8) {
//     decode_byte();
//     bit_count = 0;
//   }
// }

// void handleInterrupt() {
//   unsigned long interrupt_time = micros();
//   bit_time = interrupt_time - last_interrupt_time;
//   last_interrupt_time = interrupt_time;
//   bit_count++;
// }

// void decode_byte() {
//   char received_char = 0;
//   for (int i = 0; i < 8; i++) {
//     delayMicroseconds(bit_time); // Wait for the next bit
//     if (digitalRead(RECEIVE_PIN) == HIGH) {
//       received_char |= (1 << i); // Set the bit in the received byte
//     }
//   }
//   received_text[receive_index++] = received_char;
  
//   // Check for end of message
//   if (received_char == '\0') {
//     Serial.println(received_text);
//     receive_index = 0;
//   }
// }



#include<LiquidCrystal_I2C.h>
#define LDR_PIN 36
#define SAMPLING_TIME 50
 
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
//Declaration
bool led_state = false;
bool previous_state = true;
bool current_state = true;
char buff[64];
int threshold;
void setup()
{
 
  Serial.begin(9600);
  lcd.begin();
  lcd.setCursor(0, 0);
  lcd.backlight();
  lcd.print("hello lifi");
  delay(2000);
  lcd.clear();
}
 
void loop()
{
  // int val = analogRead(LDR_PIN);
  // Serial.println(val);
  
  //threshold = analogRead(A6);
  //Serial.println(threshold);
  current_state = get_ldr();
  if (!current_state && previous_state)
  {
     sprintf(buff, "%c", get_byte());
    Serial.print(buff);
   lcd.print(buff);
    if (strcmp(buff, "#") == 0)
    {
      lcd.clear();
    }
     
  }
  //  digitalWrite(LED, current_state);
  previous_state = current_state;
//Serial.println(finaldata);
}
bool get_ldr()
{
//bool val = analogRead(LDR_PIN) > threshold ? true : false;
bool val = analogRead(LDR_PIN) >  800? true : false;
  return val;
}
 
char get_byte()
{
  char data_byte = 0;
  delay(SAMPLING_TIME * 1.5);
  for (int i = 0; i < 8; i++)
  {
    data_byte = data_byte | (char)get_ldr() << i;
    delay(SAMPLING_TIME);
  }
  return data_byte;
}