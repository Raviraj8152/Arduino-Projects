
// // MOTER 1 LRDRS
// int LDR_Val1 = 0;
// int LDR_Val2 = 0;

// // MOTER 2 LRDRS
// int LDR_Val3 = 0;
// int LDR_Val4 = 0;

// // M1 SENSOR
// int sensor1 = 34;
// int sensor2 = 35;

// // M2 SENSOR

// int sensor3 = 32;
// int sensor4 = 33;


// // Motor A connections
// int enA = 4;
// int in1 = 21;
// int in2 = 19;

// // Motor B connections
// int enB = 2;
// int in3 = 18;
// int in4 = 5;



// void setup() {
//   Serial.begin(9600);
//   // Set all the motor control pins to outputs
//   pinMode(enA, OUTPUT);
//   pinMode(enB, OUTPUT);
//   pinMode(in1, OUTPUT);
//   pinMode(in2, OUTPUT);
//   pinMode(in3, OUTPUT);
//   pinMode(in4, OUTPUT);

//   // Turn off motors - Initial state
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, LOW);
//   digitalWrite(in3, LOW);
//   digitalWrite(in4, LOW); /*Baud rate for serial communication*/ /*LED Pin set as output */
// }
// void loop() {
//   LDR_Val1 = digitalRead(sensor1); /*DIGITAL read LDR value*/
//   LDR_Val2 = digitalRead(sensor2); /*DIGITAL read LDR value*/
//   LDR_Val3 = digitalRead(sensor3); /*DIGITAL read LDR value*/
//   LDR_Val4 = digitalRead(sensor4); /*DIGITAL read LDR value*/
 
  
//   if (LDR_Val1 == LOW) {   /*If light intensity is HIGH*/
//     Serial.println(" LDR 1");
//     // Rotate counterclockwise at high speed
//     rotateMotor(false);
//     }

//   else if (LDR_Val2 == LOW) {
//     // Rotate clockwise at high speed
//     Serial.println(" LDR 2");
//     rotateMotor(true);

//   }

//   else if (LDR_Val3 == LOW) {
//     // Rotate clockwise at high speed
//     Serial.println(" LDR 3");
//     rotateMotor2(false);

//   }

//     else if (LDR_Val4 == LOW) {
//     // Rotate clockwise at high speed
//     Serial.println(" LDR 4");
//     rotateMotor2(true);

//   }

//   delay(1000); /*Reads value after every 1 sec*/
// }



// void rotateMotor(bool clockwise) {
//   // Set motors to maximum speed
//   analogWrite(enA, 100);
//   // analogWrite(enB, 100);

//   if (clockwise) {
//     // Rotate motors clockwise
//     digitalWrite(in1, HIGH);
//     digitalWrite(in2, LOW);
//     // digitalWrite(in3, HIGH);
//     // digitalWrite(in4, LOW);
//   } else if (!clockwise){
//     // Rotate motors counterclockwise
//     digitalWrite(in1, LOW);
//     digitalWrite(in2, HIGH);
//     // digitalWrite(in3, LOW);
//     // digitalWrite(in4, HIGH);
//   }
// }




// void rotateMotor2(bool clockwise) {
//   // Set motors to maximum speed
//   // analogWrite(enA, 100);
//   analogWrite(enB, 100);

//   if (clockwise) {
//     // Rotate motors clockwise
//     // digitalWrite(in1, HIGH);
//     // digitalWrite(in2, LOW);
//     digitalWrite(in3, HIGH);
//     digitalWrite(in4, LOW);
//   } else if (!clockwise){
//     // Rotate motors counterclockwise
//     // digitalWrite(in1, LOW);
//     // digitalWrite(in2, HIGH);
//     digitalWrite(in3, LOW);
//     digitalWrite(in4, HIGH);
//   }
// }





// MOTOR 1 LDRS
int LDR_Val1 = 0;
int LDR_Val2 = 0;

// MOTOR 2 LDRS
int LDR_Val3 = 0;
int LDR_Val4 = 0;

// M1 SENSOR
int sensor1 = 23;
int sensor2 = 22;

// M2 SENSOR
int sensor3 = 13;
int sensor4 = 14;

// Motor A connections
int enA = 4;
int in1 = 21;
int in2 = 19;

// Motor B connections
int enB = 5;
int in3 = 16;
int in4 = 17;




void setup() {
  Serial.begin(9600);
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
  LDR_Val1 = digitalRead(sensor1);
  LDR_Val2 = digitalRead(sensor2);
  LDR_Val3 = digitalRead(sensor3);
  LDR_Val4 = digitalRead(sensor4);

  if (LDR_Val1 == LOW) {   // If light intensity is HIGH
    Serial.println("LDR 1");
    // Rotate motor 1 counterclockwise at high speed
    rotateMotor(false);
  } else if (LDR_Val2 == LOW) {
    // Rotate motor 1 clockwise at high speed
    Serial.println("LDR 2");
    rotateMotor(true);
  } else {
    // Turn off motor 1 if no LDR condition is met
    stopMotor1();
  }

  if (LDR_Val3 == LOW) {
    // Rotate motor 2 counterclockwise at high speed
    Serial.println("LDR 3");
    rotateMotor2(false);


  } else if (LDR_Val4 == LOW) {
    // Rotate motor 2 clockwise at high speed
    Serial.println("LDR 4");
    rotateMotor2(true);
  } else {
    // Turn off motor 2 if no LDR condition is met
    stopMotor2();
  }

}

void rotateMotor(bool clockwise) {
  // Set motor A to maximum speed
  analogWrite(enA, 150);  // Use 255 for full speed

  if (clockwise) {
    // Rotate motor A clockwise
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

  } else {
    // Rotate motor A counterclockwise
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
}

void rotateMotor2(bool clockwise) {
  // Set motor B to maximum speed
  analogWrite(enB, 150);  // Use 255 for full speed

  if (clockwise) {
    // Rotate motor B clockwise
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  } else {
    // Rotate motor B counterclockwise
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }

}

void stopMotor1() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
}

void stopMotor2() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}

