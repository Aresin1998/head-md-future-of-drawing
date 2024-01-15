void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);  // Assumi che il pulsante sia collegato al pin digitale 2
}

void loop() {
  int buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    Serial.println("Button pressed!");  // Aggiungi questo println
    int randomValue = random(400);
    Serial.print("X:");
    Serial.println(randomValue);
    delay(1000);  // Aggiungi un ritardo per evitare invii multipli se il pulsante viene tenuto premuto
  }
}
