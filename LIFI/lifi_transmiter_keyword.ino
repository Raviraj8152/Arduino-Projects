// #include <Keypad.h>

// const byte ROWS = 4; /* four rows */
// const byte COLS = 4; /* four columns */
// /* define the symbols on the buttons of the keypads */
// char hexaKeys[ROWS][COLS] = {
//   {'1','2','3','A'},
//   {'4','5','6','B'},
//   {'7','8','9','C'},
//   {'*','0','#','D'}
// };
// byte rowPins[ROWS] = {10, 11, 12, 13}; /* connect to the row pinouts of the keypad */
// byte colPins[COLS] = {6, 7, 8, 9}; /* connect to the column pinouts of the keypad */

// /* initialize an instance of class NewKeypad */
// Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

// String input = ""; // Variable to store the accumulated input

// void setup(){
//   Serial.begin(9600);
// }

// void loop(){
//   char customKey = customKeypad.getKey();

//   if (customKey){
//     if (customKey == 'D') {
//       Serial.println(input); // Print the stored input
//       input = ""; // Clear the input variable
//     } else {
//       input += customKey; // Add the key to the input variable
//       Serial.println(customKey); // Optionally print each key press
//     }
//   }
// }

#include <Keypad.h>

#define TRANSMIT_LED 16
#define SAMPLING_TIME 50

const byte ROWS = 4; /* four rows */
const byte COLS = 4; /* four columns */

/* define the symbols on the buttons of the keypads */
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {5, 4, 0, 2}; /* connect to the row pinouts of the keypad */
byte colPins[COLS] = {14, 12, 10, 9}; /* connect to the column pinouts of the keypad */

/* initialize an instance of class NewKeypad */
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

String input = ""; // Variable to store the accumulated input
bool led_state = false;
bool transmit_data = true;
int bytes_counter = 20;
int total_bytes;

void setup() {
  Serial.begin(9600);
  pinMode(TRANSMIT_LED, OUTPUT);
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    if (customKey == 'D') {
      input.concat("       #"); // Append the terminator sequence
      total_bytes = input.length();
      while (transmit_data) {
        transmit_byte(input[total_bytes - bytes_counter]);
        bytes_counter--;
        if (bytes_counter == 0) {
          transmit_data = false;
        }
      }
      transmit_data = true;
      bytes_counter = total_bytes;
      delay(1000);
      input = ""; // Clear the input variable for the next input sequence
    } else {
      input += customKey; // Add the key to the input variable
      Serial.println(customKey); // Optionally print each key press
    }
  }

  if (Serial.available()) {
    input = Serial.readString();
    input.trim();
    Serial.println(input);
    // input.concat("       #");
  }
}

void transmit_byte(char data_byte) {
  digitalWrite(TRANSMIT_LED, LOW);
  delay(SAMPLING_TIME);
  for (int i = 0; i < 8; i++) {
    digitalWrite(TRANSMIT_LED, (data_byte >> i) & 0x01);
    delay(SAMPLING_TIME);
  }
  digitalWrite(TRANSMIT_LED, HIGH); 
  delay(SAMPLING_TIME);
}


