#define PIEZO 8
#define POTENTIOMETER A0

void setup() {
  // put your setup code here, to run once:
  pinMode(PIEZO, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(POTENTIOMETER); // Leggi il valore dal potenziometro
  int delayTime = map(potValue, 0, 1023, 1, 100); // Mappa il valore del potenziometro a un intervallo di delay

  digitalWrite(PIEZO, HIGH);
  delay(delayTime);
  digitalWrite(PIEZO, LOW);
  delay(delayTime);
}