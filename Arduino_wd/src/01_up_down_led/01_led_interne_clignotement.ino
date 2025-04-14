void setup() {
  // code execution one time:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // boucle:
  digitalWrite(LED_BUILTIN, HIGH); //up led
  delay(500); //ms
  digitalWrite(LED_BUILTIN, LOW); //down led
  delay(500); //ms
}
