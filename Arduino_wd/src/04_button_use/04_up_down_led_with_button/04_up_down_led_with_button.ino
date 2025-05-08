int LedPin=2;
int ButtonPin=3;
bool ButtonIsActivate;

//we used a koms resistor for simulate the statut of button
void setup()
{
  pinMode(LedPin, OUTPUT);
  pinMode(ButtonPin, INPUT);
  ButtonIsActivate=false;
  //use Serial Monitor to 9600 for read print
  Serial.begin(9600);
  
}

void loop()
{
  ButtonIsActivate = digitalRead(ButtonPin);
  Serial.print("Button is activate:");
  Serial.println(ButtonIsActivate);
  if(ButtonIsActivate == true)
  {
    digitalWrite(LedPin, HIGH);
  }
  else
  {
    digitalWrite(LedPin, LOW);
  }
}
