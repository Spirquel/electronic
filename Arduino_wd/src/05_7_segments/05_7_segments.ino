const char segment_declare = 0;
const int segments_array[] = {2, 3, 4, 5, 6, 7, 8, 9};

void pinMode_loop(const int* TL_array)
{
  for(int idx=0; idx < TL_array[idx]; idx++)
  {
    pinMode(TL_array[idx], OUTPUT);
    digitalWrite(TL_array[idx], LOW);
  }
}

void setup()
{
  pinMode_loop(segments_array);
  //use Serial Monitor to 9600 for read print
  Serial.begin(9600);
}



void set_segments_declare(const int* TL_array, int size_array, const char declare)
{
  //cabling currently segment: up: '10, 9, 7, 6' (arduino: 2, 3, 4 ,5); down: '1, 2, 4, 5' (arduino:  6, 7, 8, 9)
  //7 segment: Common Anode 0.56 Inch (14.20mm)
  //output arduino to letter segment
  int C_G=2; int C_F=3; int C_A=4; int C_B=5; int C_E=6; int C_D=7; int C_C=8; int C_DP=9;
  
  if(declare == 0)
  {//TL_declare choose what output arduino choose for up segment
    const int TL_declare[] = {C_F, C_A, C_B, C_E, C_D, C_C};
    int size_declare = sizeof(TL_declare)/sizeof(TL_declare[0]);
    affiche_segment(TL_array, TL_declare, size_array, size_declare);
  }
  else if(declare == 1)
  {
    const int TL_declare[] = {5, 8};
    int size_declare = sizeof(TL_declare)/sizeof(TL_declare[0]);
    affiche_segment(TL_array, TL_declare, size_array, size_declare);
  }
  else if(declare == 2)
  {
    const int TL_declare[] = {2, 4, 5, 6, 7};
    int size_declare = sizeof(TL_declare)/sizeof(TL_declare[0]);
    affiche_segment(TL_array, TL_declare, size_array, size_declare);
  }
  else if(declare == 3)
  {//cabling currently segment: up: '10, 9, 7, 6' (arduino: 2, 3, 4 ,5); down: '1, 2, 4, 5' (arduino:  6, 7, 8, 9)
    const int TL_declare[] = {};
    int size_declare = sizeof(TL_declare)/sizeof(TL_declare[0]);
    affiche_segment(TL_array, TL_declare, size_array, size_declare);
  }

}

void affiche_segment(const int* TL_array, const int* TL_declare, int size_array, int size_declare)
{
  if(size_declare > size_array)
  {
    int diff = size_declare - size_array;
    Serial.print("[ERROR SIZE]: declare size is high to array size, not running code, diff:");
    Serial.println(diff);
    exit(1);
  }

  int idx_declare=0;
  for(int idx=0; idx < size_array; idx++)
  {
    if(TL_array[idx] == TL_declare[idx_declare])
    {
      digitalWrite(TL_array[idx], HIGH);
      if(idx_declare < (size_declare - 1))
      {
        idx_declare++;
      }
    }
  }
}

void loop()
{
  int size_array = sizeof(segments_array)/sizeof(segments_array[0]);
  set_segments_declare(segments_array, size_array, segment_declare);
}
