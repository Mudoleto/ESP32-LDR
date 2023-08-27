#define LDRPIN 2

void setup() {
  Serial.begin(115200);
  delay(1000);

}

void loop() {
  int val = analogRead(2);
  Serial.println("Valor:");
  Serial.println(val);
  delay(4000);
}