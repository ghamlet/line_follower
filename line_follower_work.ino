#include <Servo.h>
Servo serva_c_provolkoy; 
#define SPEED_LEFT            45      //левое вперед
#define SPEED_RIGHT          6       // правое вперед
#define DIR_LEFT              46    // лево назад
#define DIR_RIGHT            7     // правое назад
                                  //
#define sharp_left       A13     // SHARP
#define sharp_right      A12    // SHARP


#define LEFT_SENSOR_PIN      A15
#define RIGHT_SENSOR_PIN     A14
 
#define SPEED                50  // 50 дохлый акк  40 свежий 


int left = 0;
int right = 0;
   
int count_crossroad = 0;

bool flag=false; //НАХОЖДЕНИЕ ПЕРЕКРЕСТКА


void runForward() 
{  
  analogWrite(DIR_LEFT, 0);
  analogWrite(DIR_RIGHT, 0);   
  analogWrite(SPEED_LEFT, SPEED);
  analogWrite(SPEED_RIGHT, SPEED);   
}
 
void steerRight() 
{
  analogWrite(DIR_LEFT, 0);
  analogWrite(DIR_RIGHT, 0);   
  analogWrite(SPEED_RIGHT, 0);
  analogWrite(SPEED_LEFT, SPEED );  
}

void steerLeft() 
{ 
  analogWrite(DIR_LEFT, 0);
  analogWrite(DIR_RIGHT, 0);   
  analogWrite(SPEED_LEFT, 0);
  analogWrite(SPEED_RIGHT, SPEED ); 
}


 void STOP()
 {
  analogWrite(SPEED_LEFT, 0);
  analogWrite(SPEED_RIGHT, 0); 
 }
 


 
bool find_cube = false;

 bool  SHARP()  // ПОТОМУ ЧТО ВОЗВРАЩАЕЕ ЛОГИЧЕКСОЕ ЗНАЧЕНИЕ
 {
  float volts1  = analogRead(sharp_left)* 0.005 ; //    5/1024             
  int distance1 = 13*pow(volts1 , -1);
 
  float volts2  = analogRead(sharp_right)* 0.005 ; //    5/1024             
  int distance2 = 13*pow(volts2 , -1);
  
  if ((distance1 < 6) || (distance2 < 6))  // ЕСЛИ ОДИН ИЗ ДАТЧИКОВ УВИДЕЛ КУБИК
  {
    return find_cube = true;
  } else{
   return find_cube = false;
  }
 
 // Serial.println(distance1);  
  //Serial.println(distance2); 
 }

 

void setup() 
{
  Serial.begin(115200);

  serva_c_provolkoy.attach(30);
  
  pinMode(SPEED_LEFT , OUTPUT);
  pinMode(SPEED_RIGHT , OUTPUT);
  pinMode(DIR_LEFT , OUTPUT);
  pinMode(DIR_RIGHT , OUTPUT); 
} 
 
void loop() { 

    int left_value = analogRead(LEFT_SENSOR_PIN);
    int right_value = analogRead(RIGHT_SENSOR_PIN);


  /*
   Serial.print("left_value = ");
   Serial.print(left_value);
    Serial.println(" ");
     Serial.println(" ");
      delay(100);
   
  Serial.print("right_value = ");
   Serial.print(right_value);
  Serial.println(" ");
     Serial.println(" ");
    delay(100);
   
*/
 
    if (left_value <100)  left = 0;
    else left = 1;
   
    if (right_value <100)  right = 0;
    else right = 1;

 

if ((right == 1) && (left==1 )&&(!flag))
{ 
 // Serial.println("crossroad");
  flag=true; 
  count_crossroad++;             
}                                       
  
else if ((right == 0 ) || (left==0 ))  // НАХОЖДЕНИЕ ПЕРЕКРЕСТКА И ОБНОВЛЕНИЕ КОГДА ВЫЕХАЛ НА ПРЯМУЮ ДОРОГУ
  flag=false;
   



  
if ((left == 0) && (right == 0))
{
  runForward();         
} 
else if ((left == 1) && (right == 0))
{    
  steerLeft();      
}                                     //     ЛОГИКА ДВИЖЕНИЯ
else if((right == 1) && (left == 0))
{
steerRight(); 
}
  


 
else if ((left == 1) && (right == 1)  && (count_crossroad==1))   // УСЛОВИЯ ПОВОРОТА НА НУЖНОМ ПЕРЕКРЕСТКЕ
{

 //Serial.println("поворот на лево");
 steerRight(); 
 delay(500);   // ОБЯЗАТЕЛЬНО  

 
}
  /*
else if ((left == 1) && (right == 1)  && (count_crossroad==2))
{
 //Serial.println("поворот на право");  
 steerRight();
 delay(500);
}
    
  
*/
   
else  if ((left == 1) && (right == 1)  && (count_crossroad==2))
{
  STOP();
  delay(200);   //  НА ХОДУ НЕ УСПЕВАЕТ ПРОВЕРИТЬ НАЛИЧИЕ

  SHARP();
  if (find_cube == true)
  {
       
    serva_c_provolkoy.write(90);
    Serial.println("cube"); 
    STOP();


delay(3000);  


} 
//else {
 // Serial.println("no cube"); 
//runForward();
//}
  
}  
 
/*
else if ((left == 1) && (right == 1)  && (count_crossroad==1))
{
  
  SHARP();
  if (find_cube== false)
  {
   Serial.println("no cube"); 
STOP();
delay(5000);  
}
}  
 

  

 // Serial.println(count_crossroad);  
*/
}




