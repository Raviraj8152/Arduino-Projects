// // int ENA = 13; // PWM pin
// // int IN1 = 5;  // Motor direction pin 1
// // int IN2 = 4;  // Motor direction pin 2

// // const int frequency = 500;       // PWM frequency
// // const int pwm_channel = 0;       // PWM channel
// // const int resolution = 8;        // PWM resolution (8 bits)
// // const int low_speed = 60;        // Duty cycle value for low speed (adjust as needed)
// // const int rotate_delay = 1000;   // Time in milliseconds to rotate approximately 90 degrees (adjust this value)

// // void setup() {
// //   pinMode(ENA, OUTPUT);
// //   pinMode(IN1, OUTPUT);
// //   pinMode(IN2, OUTPUT); 
// //   digitalWrite(IN1, LOW);
// //   digitalWrite(IN2, LOW);

// //   // Set up PWM
// //   ledcSetup(pwm_channel, frequency, resolution);
// //   ledcAttachPin(ENA, pwm_channel);
// // }

// // void loop() {
// //   setDirection();
// // }

// // void setDirection() {
// //   // Set motor speed to low
// //   ledcWrite(pwm_channel, low_speed);

// //   // Rotate motor clockwise
// //   digitalWrite(IN1, HIGH);
// //   digitalWrite(IN2, LOW);
// //   delay(rotate_delay);

// //   // Stop the motor
// //   digitalWrite(IN1, LOW);
// //   digitalWrite(IN2, LOW);
// //   delay(1000); // Optional delay before changing direction

// //   // Rotate motor anticlockwise
// //   digitalWrite(IN1, LOW);
// //   digitalWrite(IN2, HIGH);
// //   delay(rotate_delay);

// //   // Stop the motor
// //   digitalWrite(IN1, LOW);
// //   digitalWrite(IN2, LOW);
// //   delay(1000); // Optional delay before next loop iteration
// // }



// // Motor A connections
// int enA = 13;
// int in1 = 5;
// int in2 = 4;
// // Motor B connections
// int enB = 3;
// int in3 = 5;
// int in4 = 4;
// void setup() {
// 	// Set all the motor control pins to outputs
// 	pinMode(enA, OUTPUT);
// 	pinMode(enB, OUTPUT);
// 	pinMode(in1, OUTPUT);
// 	pinMode(in2, OUTPUT);
// 	pinMode(in3, OUTPUT);
// 	pinMode(in4, OUTPUT);
	
// 	// Turn off motors - Initial state
// 	digitalWrite(in1, LOW);
// 	digitalWrite(in2, LOW);
// 	digitalWrite(in3, LOW);
// 	digitalWrite(in4, LOW);
// }
// void loop() {
// 	directionControl();
// 	delay(1000);
// 	speedControl();
// 	delay(1000);
// }
// // This function lets you control spinning direction of motors
// void directionControl() {
// 	// Set motors to maximum speed
// 	// For PWM maximum possible values are 0 to 255
// 	analogWrite(enA, 255);
// 	analogWrite(enB, 255);
// 	// Turn on motor A & B
// 	digitalWrite(in1, HIGH);
// 	digitalWrite(in2, LOW);
// 	digitalWrite(in3, HIGH);
// 	digitalWrite(in4, LOW);
// 	delay(2000);
	
// 	// Now change motor directions
// 	digitalWrite(in1, LOW);
// 	digitalWrite(in2, HIGH);
// 	digitalWrite(in3, LOW);
// 	digitalWrite(in4, HIGH);
// 	delay(2000);
	
// 	// Turn off motors
// 	digitalWrite(in1, LOW);
// 	digitalWrite(in2, LOW);
// 	digitalWrite(in3, LOW);
// 	digitalWrite(in4, LOW);
// }
// // This function lets you control speed of the motors
// void speedControl() {
// 	// Turn on motors
// 	digitalWrite(in1, LOW);
// 	digitalWrite(in2, HIGH);
// 	digitalWrite(in3, LOW);
// 	digitalWrite(in4, HIGH);
	
// 	// Accelerate from zero to maximum speed
// 	for (int i = 0; i < 256; i++) {
// 		analogWrite(enA, i);
// 		analogWrite(enB, i);
// 		delay(20);
// 	}
	
// 	// Decelerate from maximum speed to zero
// 	for (int i = 255; i >= 0; --i) {
// 		analogWrite(enA, i);
// 		analogWrite(enB, i);
// 		delay(20);
// 	}
	
// 	// Now turn off motors
// 	digitalWrite(in1, LOW);
// 	digitalWrite(in2, LOW);
// 	digitalWrite(in3, LOW);
// 	digitalWrite(in4, LOW);
// }


// Motor A connections
int enA = 13;
int in1 = 5;
int in2 = 4;

// Motor B connections
int enB = 3;
int in3 = 2;
int in4 = 1;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
  // Rotate clockwise at high speed
  rotateMotor(true);
  delay(2000);

  // Stop motors for a moment
  stopMotor();
  delay(1000); // Optional delay before changing direction

  // Rotate counterclockwise at high speed
  rotateMotor(false);
  delay(2000);

  // Stop motors
  stopMotor();
  delay(1000); // Optional delay before next loop iteration
}

void rotateMotor(bool clockwise) {
  // Set motors to maximum speed
  analogWrite(enA, 100);
  analogWrite(enB, 255);

  if (clockwise) {
    // Rotate motors clockwise
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  } else {
    // Rotate motors counterclockwise
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
}

void stopMotor() {
  // Turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
