int statut_led;
int loop_statut;
//the branche for interruption are '2,3,18,19,20,21' here we choose 22
const int Button=2;
const int loop_led=5;
const int interrupt_led=4;

void setup() 
{
  pinMode(Button, INPUT);
  pinMode(loop_led, OUTPUT);
  pinMode(interrupt_led, OUTPUT);
  statut_led=LOW;
  loop_statut=LOW;
  //interrupt the loop if the button are press
  attachInterrupt(digitalPinToInterrupt(Button), interrupt_method, FALLING);
}

void interrupt_method()
{
  statut_led=!statut_led;
  digitalWrite(interrupt_led, statut_led);
}

void loop()
{
  loop_statut=!loop_statut;
  digitalWrite(loop_led, loop_statut);
  delay(500);
}
