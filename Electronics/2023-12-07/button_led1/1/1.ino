// Definisci il pin al quale è collegato il pulsante
const int pinPulsante = 2;

void setup() {
  // Imposta il pin del pulsante come input
  pinMode(pinPulsante, INPUT);

  // Inizializza la comunicazione seriale a 9600 bps
  Serial.begin(9600);
}

void loop() {
  // Leggi lo stato attuale del pulsante
  int statoPulsante = digitalRead(pinPulsante);

  // Verifica se il pulsante è stato premuto (stato basso)
  if (statoPulsante == LOW) {
    // Stampa un messaggio sulla console seriale
    Serial.println("Il pulsante è stato premuto!");
    // Aggiungi un ritardo breve per evitare la lettura multipla durante la pressione
    delay(50);
  }
}
