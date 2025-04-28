long old_time;
boolean led_status;
int Nb_Pin_Leds=4;
int idx_led_loop;
int LedsPin[]={5, 4, 3, 2};

void setup()
{
  for(int idx_led=0; idx_led < Nb_Pin_Leds; idx_led++)
  {
    pinMode(LedsPin[idx_led], OUTPUT);
  }
  idx_led_loop=0;
  old_time = millis();
}

void loop()
{
  digitalWrite(LedsPin[idx_led_loop], led_status);
  delay(500);
  led_status = !led_status;
  
  if((millis() - old_time) > 1000)
    idx_led_loop++;
    if(idx_led_loop > 3)
      idx_led_loop=0;
}
