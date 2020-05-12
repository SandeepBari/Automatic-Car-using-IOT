
int NodeMCU_Forward  = 8;
int NodeMCU_Reverse  = 12;
int Forward = 10;
int Reverse = 11;
int Forward_Bool= 0;
int Reverse_Bool= 0;
int IR= 7;
int IR_Bool= 0;

void setup()
{
  pinMode(NodeMCU_Forward, INPUT);
  pinMode(NodeMCU_Reverse, INPUT);
  pinMode(Forward, OUTPUT);
  pinMode(Reverse, OUTPUT);
  pinMode(IR, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  Forward_Bool= digitalRead(NodeMCU_Forward);
  Reverse_Bool= digitalRead(NodeMCU_Reverse);
  IR_Bool= digitalRead(IR);

  if(IR_Bool==0)
  {
    Serial.println("Obstacle");
    digitalWrite(Forward, LOW);
    digitalWrite(Reverse, LOW);
  }
  else
  {

  if (Forward_Bool== 1 && Reverse_Bool== 0)
   {
     Serial.println("Motor ON");
     digitalWrite(Forward, HIGH);
     digitalWrite(Reverse, LOW);
   }

   if (Forward_Bool== 0 && Reverse_Bool== 1)
   {
     Serial.println("Reverse");
     digitalWrite(Forward, LOW);
     digitalWrite(Reverse, HIGH);
   }
   
  else 
   {   
     Serial.println("Motor OFF");
     digitalWrite(Forward, LOW);
     digitalWrite(Reverse, LOW);
   }
  }
}
