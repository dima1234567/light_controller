const byte ledPin = 10;
const byte interrupt1Pin = 2;
const byte interrupt2Pin = 3;
volatile int counter = 0;
byte lightArray[16]={0, 1, 2, 3, 5, 7, 10, 15, 22, 31, 44, 63, 90, 127, 180, 255};
byte light = 0;
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
    if ( counter == 180 ) {
      light = 0;
    }
    if (counter > 164) {
      // зажигаем 
      analogWrite(ledPin, lightArray[light]);      
      light++;
    } 
    if ( counter == 16 ) {
      light = 15;
    }
    if (counter < 17) {
      // гасим
      analogWrite(ledPin, lightArray[light]);      
      light--;
    }
    counter--;
    delay(200);    
    Serial.print("Conter is "); 
    Serial.println(counter, DEC);
  }
}

void change() {
  counter = 180;
  Serial.print("Conter is "); 
  Serial.println(counter, DEC);
  digitalWrite(ledPin, 1);
  Serial.println("Led is on "); 
}
