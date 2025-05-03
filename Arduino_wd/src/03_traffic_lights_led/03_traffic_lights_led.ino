int idx_FTL;
int idx_STL;
int FirstTL[] = {7, 6, 5};
int SecondTL[] = {4, 3, 2};

void pinMode_loop(int* TL_array)
{
  for(int idx=0; idx < TL_array[idx]; idx++)
  {
    pinMode(TL_array[idx], OUTPUT);
  }
}

void setup()
{
  pinMode_loop(FirstTL);
  pinMode_loop(SecondTL);
  idx_FTL=0;
  idx_STL=0;
}

void TL_gestion(int* TL_array, int *true_idx)
{
  int idx = *true_idx;
  if(idx > 0)
  {
    digitalWrite(TL_array[idx], LOW);
    idx=0;
  }
  
  digitalWrite(TL_array[idx], HIGH);
  delay(3000);
  digitalWrite(TL_array[idx], LOW);
  idx++;
  digitalWrite(TL_array[idx], HIGH);
  delay(1000);
  digitalWrite(TL_array[idx], LOW);
  idx++;
  digitalWrite(TL_array[idx], HIGH);
  *true_idx = idx;
}

void loop()
{
  TL_gestion(FirstTL, &idx_FTL);
  delay(3000);
  TL_gestion(SecondTL, &idx_STL);
  delay(3000);
}
