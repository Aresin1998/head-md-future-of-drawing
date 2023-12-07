#define LED 13

int potPin = A1;
int lum = 15;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);
  
  int delayTime = map(potValue, 0, 1023, 50, 1000);

  digitalWrite(LED, HIGH);
  delay(100);  // Adjust this value if needed for the desired on time

  digitalWrite(LED, LOW);
  delay(delayTime);

Serial.println(potValue);
}