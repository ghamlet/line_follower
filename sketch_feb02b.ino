// Моторы подключаются к клеммам M1+,M1-,M2+,M2-  
// Motor shield использует четыре контакта 6,5,7,4 для управления моторами 
#define SPEED_LEFT       6  //левое вперед
#define SPEED_RIGHT      46 // правое вперед
#define DIR_LEFT         7 // лево назад
#define DIR_RIGHT        45  // правое назад


#define LEFT_SENSOR_PIN  9
#define RIGHT_SENSOR_PIN 10
 
// Скорость, с которой мы движемся вперёд (0-255)
#define SPEED            50
 
// Коэффициент, задающий во сколько раз нужно затормозить
// одно из колёс для поворота
#define BRAKE_K          10
 
#define STATE_FORWARD    0
#define STATE_RIGHT      1
#define STATE_LEFT       2
 
//int state = STATE_FORWARD;
boolean flag=false;


void runForward() 
{
   
    analogWrite(SPEED_LEFT, SPEED);
    analogWrite(SPEED_RIGHT, SPEED);
 
  
    
}
 
void steerRight() 
{
 
    analogWrite(SPEED_RIGHT, SPEED / BRAKE_K);
    analogWrite(SPEED_LEFT, SPEED );
 
    
}
 
void steerLeft() 
{
  
 
    analogWrite(SPEED_LEFT, SPEED / BRAKE_K);
    analogWrite(SPEED_RIGHT, SPEED );
 
  
}


 void ostanovka()
 {
   analogWrite(SPEED_LEFT, 0);
  analogWrite(SPEED_RIGHT, 0); 
  analogWrite(DIR_LEFT, 0);
  analogWrite(DIR_RIGHT, 0); 
  
 }

void ivent_1(){
   digitalWrite(28, HIGH);
      runForward();
     
      delay(300);
       digitalWrite(28, LOW);
    
     ostanovka();
     delay(200);

     analogWrite(DIR_LEFT, SPEED);   // turn left
     analogWrite(SPEED_RIGHT, SPEED );
     delay(450);
     analogWrite(DIR_LEFT, 0);   
     analogWrite(SPEED_RIGHT, 0 );
     analogWrite(DIR_RIGHT, 0);   
     analogWrite(SPEED_LEFT, 0 );
    
}

void ivent_2(){
   digitalWrite(28, HIGH);
      runForward();
     
      delay(300);
       digitalWrite(28, LOW);
    
     ostanovka();
     delay(200);

     analogWrite(DIR_RIGHT, SPEED);   // turn right
     analogWrite(SPEED_LEFT, SPEED );
     delay(450);
     analogWrite(DIR_LEFT, 0);   
     analogWrite(SPEED_RIGHT, 0 );
     analogWrite(DIR_RIGHT, 0);   
     analogWrite(SPEED_LEFT, 0 );
    
}
void setup() 
{
   Serial.begin(115200);
    pinMode(SPEED_LEFT , OUTPUT);
    pinMode(SPEED_RIGHT , OUTPUT);
    pinMode(DIR_LEFT , OUTPUT);
    pinMode(DIR_RIGHT , OUTPUT);
    
   
  
} 
 
void loop() { 
    
    int left_value = analogRead(LEFT_SENSOR_PIN);
    int right_value = analogRead(RIGHT_SENSOR_PIN);


    
   Serial.print("left_value = ");
   Serial.print(left_value);
    Serial.println(" ");
     Serial.println(" ");
      
   
   Serial.print("right_value = ");
   Serial.print(right_value);
   Serial.println(" ");
     Serial.println(" ");
   
   

 
    int left = 0;
    int right = 0;
    int count_crossroad =0;



    if (left_value <100)  left = 0;
    else left = 1;
   
    if (right_value <100)  right = 0;
    else right = 1;


    
    if ((left == 0) && (right == 0)){
   runForward();                     } 
    
    else if (left == 1){ 
    steerLeft();       }
       
    else if (right == 1){
    steerRight();       }
       


    
     if ((right == 1 && left==1 )&&(!flag)){
      flag=true;

      int number = random(1,3);
      if (number == 1)
        ivent_1();
       
      else ivent_2();
                                      }
     

    else if (right == 0 || left==0 )
      flag=false;
   
}
