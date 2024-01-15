import oscP5.*;
import netP5.*;

OscP5 oscP5;
NetAddress myRemoteLocation;

void setup() {
  size(400, 400);
  frameRate(25);
  oscP5 = new OscP5(this, 12000);
  myRemoteLocation = new NetAddress("127.0.0.1", 1000);
}

void draw() {
  float sectionWidth = width / 4.0;
  
  if (mouseX < sectionWidth) {
    background(255, 0, 0); // Sezione 1: Rosso
  } else if (mouseX >= sectionWidth && mouseX < sectionWidth * 2) {
    background(0, 255, 0); // Sezione 2: Verde
  } else if (mouseX >= sectionWidth * 2 && mouseX < sectionWidth * 3) {
    background(0, 0, 255); // Sezione 3: Blu
  } else {
    background(255); // Sezione 4: Bianco
  }
}

void mouseMoved() {
  OscMessage myMessage1 = new OscMessage("/1");
  OscMessage myMessage2 = new OscMessage("/2");
  OscMessage myMessage3 = new OscMessage("/3");
  OscMessage myMessage4 = new OscMessage("/4");
  
  float sectionWidth = width / 4.0;
  
  if (mouseX < sectionWidth) {
    myMessage1.add(1 - mouseY / 100.0);
    oscP5.send(myMessage1, myRemoteLocation);
  } else if (mouseX >= sectionWidth && mouseX < sectionWidth * 2) {
    myMessage2.add(1 - mouseY / 100.0);
    oscP5.send(myMessage2, myRemoteLocation);
  } else if (mouseX >= sectionWidth * 2 && mouseX < sectionWidth * 3) {
    myMessage3.add(1 - mouseY / 100.0);
    oscP5.send(myMessage3, myRemoteLocation);
  } else {
    myMessage4.add(1 - mouseY / 100.0);
    oscP5.send(myMessage4, myRemoteLocation);
  }
}

void oscEvent(OscMessage theOscMessage) {
  print("### received an osc message.");
  print(" addrpattern: " + theOscMessage.addrPattern());
  println(" typetag: " + theOscMessage.typetag());
}
