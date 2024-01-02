#define BUTTON_PIN 4
#define LED_PIN 2

void setup() {
  //IL SETUP SI ATTIVA SOLO UNA VOLTA ALL'INIZIO
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  pinMode (LED_PIN, OUTPUT);

//LUCE SPENTA QUANDO SI STARTA
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  boolean value = digitalRead(BUTTON_PIN);
  digitalWrite(LED_PIN, !value);
  }
