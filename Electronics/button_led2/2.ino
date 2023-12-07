#define LED_PIN 2
#define BUTTON_PIN 4

byte lastButtonState = LOW;
byte ledState = LOW;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  byte buttonState = digitalRead(BUTTON_PIN);
  if (buttonState != lastButtonState) {
    lastButtonState = buttonState;
    if (buttonState == LOW) {
      ledState = (ledState == HIGH) ? LOW: HIGH;
      digitalWrite(LED_PIN, ledState);
    }
  }
  Serial.print("button is ");
  Serial.println(buttonState);
}