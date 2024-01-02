const int potPin = A0;     // Collega il potenziometro al pin analogico A0
const int ledPin1 = 4;     // Collega il primo LED al pin digitale 4
const int ledPin2 = 10;    // Collega il secondo LED al pin digitale 10
const int buttonPin = 7;   // Collega il pulsante al pin digitale 7
const int threshold = 512;  // Imposta una soglia a metà del range del potenziometro

bool ledState = false;      // Flag per tenere traccia dello stato dei LED (acceso/spento)
int delayTime = 100;        // Tempo di ritardo iniziale in millisecondi (puoi regolare questo valore)

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Configura il pin del pulsante come input con resistenza di pull-up
}

void loop() {
  int potValue = analogRead(potPin);  // Legge il valore del potenziometro (da 0 a 1023)

  // Scala il valore del potenziometro al range del delayTime (da 50 a 500)
  delayTime = map(potValue, 0, 1023, 50, 500);

  // Controlla lo stato del pulsante
  if (digitalRead(buttonPin) == LOW) {  // Pulsante premuto
    ledState = !ledState;  // Inverte lo stato dei LED
    delay(200);  // Ritardo per evitare letture multiple mentre il pulsante è premuto
  }

  // Accende o spegne i LED in base allo stato
  if (ledState) {
    analogWrite(ledPin1, 255);
    analogWrite(ledPin2, 0);
    delay(delayTime);
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 255);
    delay(delayTime);
  } else {
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 0);
  }
}
