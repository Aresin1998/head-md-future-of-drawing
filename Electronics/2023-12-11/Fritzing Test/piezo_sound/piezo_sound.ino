const int potPin = A0;     // Collega il potenziometro al pin analogico A0
const int ledPin1 = 4;     // Collega il primo LED al pin digitale 4
const int ledPin2 = 10;    // Collega il secondo LED al pin digitale 10
const int buttonPin = 7;   // Collega il pulsante al pin digitale 7
const int threshold = 512;  // Imposta una soglia a metà del range del potenziometro
const int delayTime = 100;  // Tempo di ritardo in millisecondi (puoi regolare questo valore)

bool inverted = false;  // Flag per tenere traccia dello stato invertito dei LED

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Configura il pin del pulsante come input con resistenza di pull-up
}

void loop() {
  int potValue = analogRead(potPin);  // Legge il valore del potenziometro (da 0 a 1023)

  // Scala il valore del potenziometro al range del LED (da 0 a 255)
  int scaledValue = map(potValue, 0, 1023, 0, 255);

  // Controlla lo stato del pulsante
  if (digitalRead(buttonPin) == LOW) {  // Pulsante premuto
    inverted = !inverted;  // Inverte lo stato
    delay(200);  // Ritardo per evitare letture multiple mentre il pulsante è premuto
  }

  // Accende i LED in base allo stato invertito
  if (!inverted) {
    analogWrite(ledPin1, scaledValue);
    analogWrite(ledPin2, 255 - scaledValue);
  } else {
    analogWrite(ledPin1, 255 - scaledValue);
    analogWrite(ledPin2, scaledValue);
  }

  delay(delayTime);  // Introduce un ritardo prima di effettuare la prossima lettura del potenziometro
}

