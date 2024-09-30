// #define TRANSMIT_LED 1
// #define SAMPLING_TIME 50

// char* text = "Li-Fi is wireless communication technology which utilizes light to transmit data and position between devices. The term was first introduced by Harald Haas during a 2011 TEDGlobal talk in Edinburgh.";
// int total_bytes;
// int bytes_counter;

// void setup() {
//   pinMode(TRANSMIT_LED, OUTPUT);
//   total_bytes = strlen(text);
//   bytes_counter = total_bytes;  // Start with full text length
// }

// void loop() {
//   while (bytes_counter > 0) {
//     transmit_byte(text[total_bytes - bytes_counter]);
//     bytes_counter--;
//   }
//   bytes_counter = total_bytes;  // Reset for the next loop
//   delay(1000);  // Delay between full message transmissions
// }

// void transmit_byte(char data_byte) {
//   digitalWrite(TRANSMIT_LED, LOW); 
//   delay(SAMPLING_TIME);
//   for (int i = 0; i < 8; i++) {
//     digitalWrite(TRANSMIT_LED, (data_byte >> i) & 0x01); 
//     delay(SAMPLING_TIME);
//   }
//   digitalWrite(TRANSMIT_LED, HIGH); // Return to IDLE state
//   delay(SAMPLING_TIME);
// }


#define TRANSMIT_LED A2
#define SAMPLING_TIME 50
 
String text;
 
bool led_state = false;
bool transmit_data = true;
int bytes_counter = 20;
int total_bytes;
 
 
void setup() {
   
Serial.begin(9600);
  pinMode(TRANSMIT_LED, OUTPUT);
  text="HelloThisIs LiFi       #";
}
 
void loop() {
  if(Serial.available())
  {
    text=Serial.readString();
    text.trim();
     Serial.println(text);
   text.concat("       #");
    
  }
 
    
   
 total_bytes = text.length();
  while (transmit_data)
  {
    transmit_byte(text[total_bytes - bytes_counter]);
    bytes_counter--;
    if (bytes_counter == 0)
    {
      transmit_data = false;
    }
    //delay(100);
  }
  transmit_data = true;
  bytes_counter = total_bytes;
  delay(1000);
}
 
void transmit_byte(char data_byte)
{
  digitalWrite(TRANSMIT_LED, LOW);
  delay(SAMPLING_TIME);
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(TRANSMIT_LED, (data_byte >> i) & 0x01);
    delay(SAMPLING_TIME);
  }
  digitalWrite(TRANSMIT_LED, HIGH); 
  delay(SAMPLING_TIME);
}
