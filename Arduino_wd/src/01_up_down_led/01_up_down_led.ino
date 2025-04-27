//broche number
const int xi_RedLed = 2;

void UpDown(const int led, const int sleep_time)
{
  digitalWrite(led, HIGH); //up led (like true)
  delay(sleep_time); //ms
  digitalWrite(led, LOW); //down led (like false)
  delay(sleep_time); //ms
}

//code execution one time
void setup() {
//pin led in card (OUPUT: SET DATA)
  pinMode(LED_BUILTIN, OUTPUT);
//pin led in breadboard (INPUT: GET DATA)
  pinMode(xi_RedLed, OUTPUT);
}

void loop() {
  UpDown(LED_BUILTIN, 500);
  UpDown(xi_RedLed, 500);
}
