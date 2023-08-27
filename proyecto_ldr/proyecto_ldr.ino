#define LDRPIN 2

int relevador=23;


void setup() {
  Serial.begin(115200);
  pinMode(relevador,OUTPUT);
  delay(1000);
}

void loop() {

  int val = analogRead(2);

  if (val <= 1800){
    digitalWrite(relevador, LOW);
    delay(4000);
  }
  else{
    digitalWrite(relevador,HIGH);
  }
}  