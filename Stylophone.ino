int b0 = 233.0819;
int h0 = 246.9417;
int c1 = 261.6256;
int cis1 = 277.1826;
int d1 = 293.6648;
int dis1 = 311.1270;
int e1 = 329.6276;
int f1 = 349.2282;
int fis1 = 369.9944;
int g1 = 391.9954;
int gis1 = 415.3047;
int a1 = 440.0000;
int b1 = 466.1638;
int h1 = 493.8833;
int c2 = 523.2511;
int cis2 = 554.3653;
int d2 = 587.3295;
int dis2 = 622.2540;
int e2 = 659.2551;

int reprak = 12;
int analog = A1;

boolean inRange(int analogValue, int hodnota){
  int low = hodnota - 25;
  int high = hodnota + 24;

  if ((low <= analogValue) && (analogValue <= high)){
    return true;
  } else {
    return false;
  }
}

boolean inRange(int analogValue, int low, int high){
    if ((low <= analogValue) && (analogValue <= high)){
    return true;
  } else {
    return false;
  }
}

void setup() {
pinMode(reprak,OUTPUT);
Serial.begin(9600);
}

void loop() {
  int readAnalog = analogRead(analog);
  Serial.println(readAnalog);

  if(readAnalog >= 1000){
    noTone(reprak);
  } else if (inRange(readAnalog, 955, 985)){
    tone(reprak,b0);
  } else if (inRange(readAnalog, 905)){
    tone(reprak,h0);
  } else if (inRange(readAnalog, 855)){
    tone(reprak,c1);
  } else if (inRange(readAnalog, 805)){
    tone(reprak,cis1);
  } else if (inRange(readAnalog, 755)){
    tone(reprak,d1);
  } else if (inRange(readAnalog, 705)){
    tone(reprak,dis1);
  } else if (inRange(readAnalog, 655)){
    tone(reprak,e1);
  } else if (inRange(readAnalog, 605)){
    tone(reprak,f1);
  } else if (inRange(readAnalog, 555)){
    tone(reprak,fis1);
  } else if (inRange(readAnalog, 505)){ 
    tone(reprak,g1);
  } else if (inRange(readAnalog, 455)){
    tone(reprak,gis1);
  } else if (inRange(readAnalog, 405)){
    tone(reprak,a1);
  } else if (inRange(readAnalog, 355)){
    tone(reprak,b1);
  } else if (inRange(readAnalog, 305)){
    tone(reprak,h1);
  } else if (inRange(readAnalog, 255)){
    tone(reprak,c2);
  } else if (inRange(readAnalog, 205)){
    tone(reprak,cis2);
  } else if (inRange(readAnalog, 155)){
    tone(reprak,d2);
  } else if (inRange(readAnalog, 105)){
    tone(reprak,dis2);
  } else if (inRange(readAnalog, 55)){
    tone(reprak,e2);
  } else {
    noTone(reprak);
  }
}
