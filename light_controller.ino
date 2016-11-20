const byte ledPin = 10;
const byte interrupt1Pin = 2;
const byte interrupt2Pin = 3;
volatile int counter = 0;
byte lightArray[16]={0, 1, 2, 3, 5, 7, 10, 15, 22, 31, 44, 63, 90, 127, 180, 255};
volatile byte light = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interrupt1Pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt1Pin), change, CHANGE); 
  pinMode(interrupt2Pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt2Pin), change, CHANGE); 
  digitalWrite(ledPin, 0);
}

void loop() {  
  if (counter > 0) {
    if ( (counter == 600) && ( light == 0 ) ) {
      light = 0;
    }
    if (counter > 583) {
      // зажигаем 
      analogWrite(ledPin, lightArray[light]);      
      if (light < 15 ) { 
        light++;
      }  
    } 
    if (light == 15) {
      digitalWrite(ledPin, HIGH);      
    }
    if ( counter == 16  && ( light  == 15 ) ) {
      light = 15;
    }
    if (counter < 16) {
      // гасим
      analogWrite(ledPin, lightArray[light]);      
      if (light > 0 ) { 
        light--;
      }
    }
    if (light == 0) {
      digitalWrite(ledPin, LOW);      
    }
    counter--;
    delay(100);    
  }
}

void change() {
  counter = 600;
}
