const int LED_PIN_1 = 2;  // Substitua pelos pinos corretos para seus LEDs
const int LED_PIN_2 = 3;
const int LED_PIN_3 = 4;
const int LED_PIN_4 = 5;
const int LED_PIN_5 = 6;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int num_fingers = Serial.parseInt();  // Lê o número de dedos da porta serial
    
    if (num_fingers == 1) {
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
    }
    else if (num_fingers == 2) {
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
    }
    else if (num_fingers == 3) {
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
    }
    else if (num_fingers == 4) {
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, LOW);
    }
    else if (num_fingers == 5) {
      digitalWrite(LED_PIN_1, HIGH);
      digitalWrite(LED_PIN_2, HIGH);
      digitalWrite(LED_PIN_3, HIGH);
      digitalWrite(LED_PIN_4, HIGH);
      digitalWrite(LED_PIN_5, HIGH);
    }
    else{
      digitalWrite(LED_PIN_1, LOW);
      digitalWrite(LED_PIN_2, LOW);
      digitalWrite(LED_PIN_3, LOW);
      digitalWrite(LED_PIN_4, LOW);
      digitalWrite(LED_PIN_5, LOW);
    }
  }
}
