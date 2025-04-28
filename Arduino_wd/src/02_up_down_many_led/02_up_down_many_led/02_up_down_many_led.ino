const int Led_one = 5;
const int Led_two = 4;
const int Led_three = 3;
const int Led_four = 2;

void UpDown(const int led, const int time)
{
  digitalWrite(led, HIGH);
  delay(time);
   digitalWrite(led, LOW);
  delay(time);
}

void setup()
{
  pinMode(Led_one, OUTPUT);
  pinMode(Led_two, OUTPUT);
  pinMode(Led_three, OUTPUT);
  pinMode(Led_four, OUTPUT);
}

void loop()
{
  UpDown(Led_one, 500);
  UpDown(Led_two, 500);
  UpDown(Led_three, 500);
  UpDown(Led_four, 500);
}
