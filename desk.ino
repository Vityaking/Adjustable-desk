void setup() 
{
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  #define ButtonUp 5
  #define ButtonStop 6
  #define ButtonDown 7
  #define UpRight 8
  #define DownRight 9
  #define UpLeft 10
  #define DownLeft 11  
  Serial.begin(9600);
  Serial.println("setup");
}

void loop() 
{
  int control=0; //1:down, 2:stop, 3:up
  if (digitalRead(ButtonUp)==LOW)
  {
    control=3;
    Serial.println("három e");
  }
  if (digitalRead(ButtonStop)==LOW)
  {
    control=2;
  }
  if (digitalRead(ButtonDown)==LOW)
  {
    control=1;
  }
  while (control==3)
  {
    digitalWrite(UpRight, HIGH);
    digitalWrite(UpLeft, HIGH);
    Serial.println("megyen");
    if (digitalRead(ButtonStop)==LOW)
    {
      digitalWrite(UpRight, LOW);
      digitalWrite(UpLeft, LOW);
      Serial.println("nem megyen");
      break;
    }
  }
     while (control==1)
  {
    digitalWrite(DownRight, HIGH);
    digitalWrite(DownLeft, HIGH);
    if (digitalRead(ButtonStop)==LOW)
    {
      digitalWrite(DownRight, LOW);
      digitalWrite(DownLeft, LOW);
      break;
    }
  }
}
