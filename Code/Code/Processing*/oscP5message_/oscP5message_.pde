import oscP5.*;
import netP5.*;

OscP5 oscP5;
NetAddress myRemoteLocation;

int teinte = 0; // 0 == rouge, 180 == cyan, ...

void setup() {
  size(400, 400);
  colorMode(HSB, 360, 100, 100);
  frameRate(25);
  oscP5 = new OscP5(this, 12000);
  myRemoteLocation = new NetAddress("127.0.0.1", 1000);
}

void draw() {
  float sectionWidth = width / 4.0;
  int sectionIndex = mouseX / int(sectionWidth);
  noStroke();
  fill(0, 0, 80, 50);
  rect(sectionWidth * sectionIndex, 0, sectionWidth, height);

  // Disegna la divisione in 4 parti in verticale
  for (int i = 1; i < 4; i++) {
    float x = i * sectionWidth;
    stroke(0, 0, 0);
    line(x, 0, x, height);
  }

  // 0 ... height > 0 ... 360° 
  teinte = int(map(mouseY, 0, height, 0, 360));

  // Disegna un cerchio rosso intorno alla posizione del mouse
  fill(teinte, 100, 100);  // La teinte va changer
  noStroke();       // Nessun contorno
  ellipse(mouseX, mouseY, 20, 20);  // Cerchio centrato sulla posizione del mouse
}

void mousePressed() {
  float sectionWidth = width / 4.0;

  OscMessage myMessage = new OscMessage("/" + (int) (mouseX / sectionWidth + 1));
  myMessage.add(1 - mouseY / 400.0);
  oscP5.send(myMessage, myRemoteLocation);
}

void oscEvent(OscMessage theOscMessage) {
  print("### received an osc message.");
  print(" addrpattern: " + theOscMessage.addrPattern());
  println(" typetag: " + theOscMessage.typetag());
}
