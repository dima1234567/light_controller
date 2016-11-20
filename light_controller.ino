const byte ledPin = 10;
const byte interrupt1Pin = 2;
const byte interrupt2Pin = 3;
volatile int counter = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interrupt1Pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt1Pin), change, CHANGE); 
  pinMode(interrupt2Pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt2Pin), change, CHANGE); 
  Serial.begin(115200);
  digitalWrite(ledPin, 0);
}

void loop() {  
  if (counter > 0) {
    if (counter == 1) {
      // выключаем
      Serial.println("Led is off "); 
      digitalWrite(ledPin, 0);
    }
    counter--;
    delay(50);    
    Serial.print("Conter is "); 
    Serial.println(counter, DEC);
  }
}

void change() {
  counter = 7200;
  Serial.print("Conter is "); 
  Serial.println(counter, DEC);
  digitalWrite(ledPin, 1);
  Serial.println("Led is on "); 
}
