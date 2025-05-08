int nb_led_up;
bool statut_button;
bool memory_increase_led;
bool memory_decrease_led;
const int Leds[] = {2, 3, 4, 5};
const int Buttons[] = {6, 7};

void pinMode_loop(const int* TL_array, const int mod)
{
  for(int idx=0; idx < TL_array[idx]; idx++)
  {
    pinMode(TL_array[idx], mod);
  }
}

void setup()
{
  pinMode_loop(Leds, OUTPUT);
  pinMode_loop(Buttons, INPUT);

  nb_led_up=0;
  statut_button=false;
  memory_increase_led=false;
  memory_decrease_led=false;
  Serial.begin(9600);
}

void leds_gestion(const int nb_led)
{
  for(int idxup=0; idxup < nb_led; idxup++)
  {
    digitalWrite(Leds[idxup], HIGH);
  }

  for(int idxdown=nb_led; idxdown < Leds[idxdown]; idxdown++)
  {
    digitalWrite(Leds[idxdown], LOW);
  }
}

void loop()
{
  statut_button = digitalRead(Buttons[0]);
  //if we still press, the increment is continu
  if(statut_button != memory_increase_led && statut_button == true)
  {
    nb_led_up++;
  }
  memory_increase_led = statut_button;

  statut_button = digitalRead(Buttons[1]);

  if(statut_button != memory_decrease_led && statut_button == true)
  {
    nb_led_up--;
  }
  memory_decrease_led = statut_button;

  if(nb_led_up > 4)
  {
    nb_led_up = 4;
  }
  else if(nb_led_up < 0)
  {
    nb_led_up = 0;
  }

  Serial.print("nb led:");
  Serial.println(nb_led_up);

  leds_gestion(nb_led_up);
}
