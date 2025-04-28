int Nb_Pin_leds = 4;
int ledPins[] = {5, 4, 3, 2};

void UpDown(int led, const int time_stop)
{
  digitalWrite(led, HIGH);
  delay(time_stop);
  digitalWrite(led, LOW);
  delay(time_stop);
}

void setup()
{
  for(int idx_led = 0; idx_led < Nb_Pin_leds; idx_led++)
  {
    pinMode(ledPins[idx_led], OUTPUT);
  }
}

void loop()
{
  for(int idx_led = 0; idx_led < Nb_Pin_leds; idx_led++)
  {
    UpDown(ledPins[idx_led], 1000);
  }
}
