int relevador = 23;

void setup() {
  pinMode(relevador,OUTPUT);
}

void loop() {
  digitalWrite(relevador,HIGH);
  delay(400);
  digitalWrite(relevador,LOW);
  delay(400);
}