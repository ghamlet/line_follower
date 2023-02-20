#define RM_PIN_1 45
#define RM_PIN_2 46

#define LM_PIN_1 7
#define LM_PIN_2 6

#define LS_PIN   A6
#define RS_PIN   A5


#define SPEED 50

void setMotor(int lval, int rval);
void setup() {
  Serial.begin(9600);
  pinMode(LM_PIN_1, OUTPUT);
  pinMode(LM_PIN_2, OUTPUT);
  pinMode(RM_PIN_1, OUTPUT);
  pinMode(RM_PIN_2, OUTPUT);

}

void loop() 
{
  int error = analogRead(LS_PIN) - analogRead(RS_PIN);

  int cor_val = error * 1;

  cor_val = map(cor_val, -1023,1023,-255,255);
  cor_val = constrain(cor_val, -255,255);

  setMotor(SPEED - cor_val, SPEED + cor_val);
}


void setMotor(int lval, int rval)
{
  if (lval < 0)
  {
    analogWrite(LM_PIN_1, abs(lval));
    analogWrite(LM_PIN_2, 0);
  }
  else if (lval > 0)
  {
    analogWrite(LM_PIN_1, 0);
    analogWrite(LM_PIN_2, abs(lval));
  }
  else
  {
    analogWrite(LM_PIN_1, 0);
    analogWrite(LM_PIN_2, 0);
  }

  if (rval > 0)
  {
    analogWrite(RM_PIN_1, abs(rval));
    analogWrite(RM_PIN_2, 0);
  }
  else if (rval < 0)
  {
    analogWrite(RM_PIN_1, 0);
    analogWrite(RM_PIN_2, abs(rval));
  }
  else
  {
    analogWrite(RM_PIN_1, 0);
    analogWrite(RM_PIN_2, 0);
  }
}
