//enter the value of show with 7 segments
const char segment_declare = 'E';
//cabling hardware segment branches
//7 segment: Common Anode 0.56 Inch (14.20mm)
     //all member of segment {A, B, C, D, E, F, G, DP};
const int segments_array[] = {2, 3, 4, 5, 6, 7, 8, 9};

//get arduino digital for show nb or alph in 7 segments
const byte segment_patterns[][8] = {
  //NUMBER
  //show: 0
  {1, 1, 1, 1, 1, 1, 0, 0},
  //show: 1
  {0, 1, 1, 0, 0, 0, 0, 0},
  //show: 2
  {1, 1, 0, 1, 1, 0, 1, 0},
  //show: 3
  {1, 1, 1, 1, 0, 0, 1, 0},
  //show: 4
  {0, 1, 1, 0, 0, 1, 1, 0},
  //show: 5
  {1, 0, 1, 1, 0, 1, 1, 0},
  //show: 6
  {1, 0, 1, 1, 1, 1, 1, 0},
  //show: 7
  {1, 1, 1, 0, 0, 0, 0, 0},
  //show: 8
  {1, 1, 1, 1, 1, 1, 1, 0},
  //show: 9
  {1, 1, 1, 1, 0, 1, 1, 0},

  //ALPHABETICS
  //show: A
  {1, 1, 1, 0, 1, 1, 1, 0},
  //show: b
  {0, 0, 1, 1, 1, 1, 1, 0},
  //show: c
  {0, 0, 0, 1, 1, 0, 1, 0},
  //show: C
  {1, 0, 0, 1, 1, 1, 0, 0},
  //show: d
  {0, 1, 1, 1, 1, 0, 1, 0},
  //show: E
  {1, 0, 0, 1, 1, 1, 1, 0},
  //show: F
  {1, 0, 0, 0, 1, 1, 1, 0},
  //show: H
  {0, 1, 1, 0, 1, 1, 1, 0},
  //show: I
  {0, 1, 1, 0, 0, 0, 0, 0},
  //show: J
  {0, 1, 1, 1, 0, 0, 0, 0},
  //show: L
  {0, 0, 0, 1, 1, 1, 0, 0},
  //show: o
  {0, 0, 1, 1, 1, 0, 1, 0},
  //show: O
  {1, 1, 1, 1, 1, 1, 0, 0},
  //show: P
  {1, 1, 0, 0, 1, 1, 1, 0},
  //show: S
  {1, 0, 1, 1, 0, 1, 1, 0},
  //show: t
  {0, 0, 0, 1, 1, 1, 1, 0},
  //show: U
  {0, 1, 1, 1, 1, 1, 0, 0},
  //show: u
  {0, 0, 1, 1, 1, 0, 0, 0},
  //show: .
  {0, 0, 0, 0, 0, 0, 0, 1}
};

const char segment_declare_valid[] = {
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
  'A', 'b', 'c', 'C', 'd', 'E', 'F',
  'H', 'I', 'J', 'L', 'o', 'O', 'P',
  'S', 't', 'U', 'u', '.'
};

void pinMode_loop(const int* TL_array, int size_array)
{
  for(int i = 0; i < size_array; i++) {
    pinMode(TL_array[i], OUTPUT);
    digitalWrite(TL_array[i], LOW);
  }
}

void setup()
{
  int size_array = sizeof(segments_array) / sizeof(segments_array[0]);
  pinMode_loop(segments_array, size_array);
  Serial.begin(9600);
}

void declare_verification(int decalre, int* idx_declare)
{
  int size_segment_valid = sizeof(segment_declare_valid) / sizeof(segment_declare_valid[0]);

  for(int idx=0; idx < size_segment_valid; idx++)
  {
    if(decalre == segment_declare_valid[idx])
    {
      *idx_declare = idx;
    }
  }
}

void set_segments_declare(const int* TL_array, int size_array, const char declare)
{
  int idx_declare = -1;

  declare_verification(declare, &idx_declare);

  if(idx_declare == -1)
  {
    Serial.print("[ERROR] Segment pattern index not found, cause declare not valid:");
    Serial.println(declare);
    return;
  }

  for(int idx=0; idx < size_array; idx++)
  {
    digitalWrite(TL_array[idx], segment_patterns[idx_declare][idx] ? HIGH : LOW);
  }
}

void loop()
{
  int size_array = sizeof(segments_array) / sizeof(segments_array[0]);
  set_segments_declare(segments_array, size_array, segment_declare);
  delay(1000);
}
