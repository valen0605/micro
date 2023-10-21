void setup()
{
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
}

void loop()
{
  bool A, B, C, D, E,F,G;
  A = digitalRead(11);
  B = digitalRead(10);
  C = !digitalRead(9);
  D = !digitalRead(8);
  E = D&&(A&&(B||C)||!A&&!B&&!C||B&&C)||!A&&!D&&(B^C)||A&&B&&C;
  digitalWrite(7, E);
  F = A&&B&&C&&D;
  digitalWrite(6, F);
  G = A&&(B||D||C)||B&&(D||C)||C&&D;
  digitalWrite(5, G);
}