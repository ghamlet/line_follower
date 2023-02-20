#define SPEED_LEFT            45  //левое вперед
#define SPEED_RIGHT          6      // правое вперед
#define DIR_LEFT              46   // лево назад
#define DIR_RIGHT            7     // правое назад
#define LEFT_SENSOR_PIN      A7
#define RIGHT_SENSOR_PIN     A6
#define sharp_left       A8    // SHARP
#define sharp_right      A9    // SHARP
int left = 0;
int right = 0;
int count_crossroad = 0;
bool flag=false;
//int right_value=11;
//int left_value = 10;
#define SPEED                40  // 50 дохлый акк  40 свежий 
void left_()
{
   analogWrite(DIR_LEFT, 0);
  analogWrite(DIR_RIGHT, 0);   
  analogWrite(SPEED_LEFT, 0);
  analogWrite(SPEED_RIGHT, SPEED ); 
}
void right_(){
  analogWrite(DIR_LEFT, 0);
  analogWrite(DIR_RIGHT, 0);   
  analogWrite(SPEED_LEFT, 0);
  analogWrite(SPEED_RIGHT, SPEED ); 
}
void stop_(){
  analogWrite(DIR_LEFT, 0);
  analogWrite(DIR_RIGHT, 0);   
  analogWrite(SPEED_LEFT, 0);
  analogWrite(SPEED_RIGHT, 0 ); 
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
 
  Serial.println(distance1);  
  Serial.println(distance2); 
 }
void setup() {
  Serial.begin(115200);
 // serva_c_provolkoy.attach(30); 
  pinMode(SPEED_LEFT , OUTPUT);
  pinMode(SPEED_RIGHT , OUTPUT);
  pinMode(DIR_LEFT , OUTPUT);
  pinMode(DIR_RIGHT , OUTPUT); 
 
}

void loop() {
  int left_value = analogRead(LEFT_SENSOR_PIN);
  int right_value = analogRead(RIGHT_SENSOR_PIN);
  //Serial.println(left_value);
  //Serial.println(right_value);
  
   analogWrite(SPEED_LEFT, SPEED);
   analogWrite(SPEED_RIGHT, SPEED);  
    if (left_value <200)  left = 0;
   else left = 1;
   Serial.println(left);
   
   if (right_value <200)  right = 0;
   else right = 1;
   Serial.println(right);



if ((right_value == 1) && (left_value==1 )&&(!flag))
{ 
  digitalWrite(28,HIGH);
 // Serial.println("crossroad");
  flag=true; 
  count_crossroad++; 
  digitalWrite(28,LOW);            
           
}                                       
  
else if ((right_value == 0 ) || (left_value==0 ))  // НАХОЖДЕНИЕ ПЕРЕКРЕСТКА И ОБНОВЛЕНИЕ КОГДА ВЫЕХАЛ НА ПРЯМУЮ ДОРОГУ
  flag=false;  
  
if ((left_value == 0) && (right_value == 0))
{
   analogWrite(SPEED_LEFT, SPEED);
   analogWrite(SPEED_RIGHT, SPEED);  
} 
else if ((left_value == 1) && (right_value == 0))
{    
  right_();
}                                     //     ЛОГИКА ДВИЖЕНИЯ
else if((right_value == 1) && (left_value == 0))
{
 left_();
} 
else if ((left_value == 1) && (right_value == 1)  && (count_crossroad==1))   // УСЛОВИЯ ПОВОРОТА НА НУЖНОМ ПЕРЕКРЕСТКЕ
{

 //Serial.println("поворот на лево");

   // ОБЯЗАТЕЛЬНО  
right_();
delay(500);
Serial.println( count_crossroad);
}
else if ((left_value == 1) && (right_value == 1)  && (count_crossroad==2))   // УСЛОВИЯ ПОВОРОТА НА НУЖНОМ ПЕРЕКРЕСТКЕ
{

 //Serial.println("поворот на лево");

stop_();  // ОБЯЗАТЕЛЬНО  

Serial.println( count_crossroad);
}
/*else  if ((left == 1) && (right == 1)  && (count_crossroad==3))
{
  STOP();
  delay(200);   //  НА ХОДУ НЕ УСПЕВАЕТ ПРОВЕРИТЬ НАЛИЧИЕ

  SHARP();
if (find_cube == true)
  {  
    //serva_c_provolkoy.write(90);
    Serial.println("cube"); +
    STOP();
    delay(3000);  
} 
else {
  Serial.println("no cube"); 
runForward();
}
*/
}
