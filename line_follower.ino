
#define SPEED_LEFT       6  //левое вперед
#define SPEED_RIGHT      46 // правое вперед
#define DIR_LEFT         7  // лево назад
#define DIR_RIGHT        45  // правое назад

#define sharp1 A8      // SHARP
#define sharp2 A9      // SHARP


#define LEFT_SENSOR_PIN  11
#define RIGHT_SENSOR_PIN 12
 
#define SPEED            50



 

 

boolean flag=false;


void runForward() 
{
   
    analogWrite(SPEED_LEFT, SPEED);
    analogWrite(SPEED_RIGHT, SPEED);
 
  
    
}
 
void steerRight() 
{
 
    analogWrite(SPEED_RIGHT, 0);
    analogWrite(SPEED_LEFT, SPEED );
 
    
}




void steerLeft() 
{
  
 
    analogWrite(SPEED_LEFT, 0);
    analogWrite(SPEED_RIGHT, SPEED );
 
  
}


 void ostanovka()
 {
   analogWrite(SPEED_LEFT, 0);
  analogWrite(SPEED_RIGHT, 0); 
  //analogWrite(DIR_LEFT, 0);
  //analogWrite(DIR_RIGHT, 0); 
  
 }
/*
void ivent_1(){
      digitalWrite(28, HIGH);
      runForward();
     
      delay(300);
       digitalWrite(28, LOW);
    
     ostanovka();
     delay(5000);

     analogWrite(DIR_LEFT, SPEED);   // turn left
     analogWrite(SPEED_RIGHT, SPEED );
     
     delay(450);
     
     analogWrite(DIR_LEFT, 0);   
     analogWrite(SPEED_RIGHT, 0 );
     analogWrite(DIR_RIGHT, 0);   
     analogWrite(SPEED_LEFT, 0 );
     
    int val1 = analogRead(sharp1);
   delay(100);
//    Serial.println(val1);
    int val2 = analogRead(sharp2);
   delay(100);
  //  Serial.println(val2);
   

}

void ivent_2(){
   digitalWrite(28, HIGH);
      runForward();
     
      delay(300);
       digitalWrite(28, LOW);
    
     ostanovka();
     delay(2000);

     analogWrite(DIR_RIGHT, SPEED);   // turn right
     analogWrite(SPEED_LEFT, SPEED );
     delay(450);
     analogWrite(DIR_LEFT, 0);   
     analogWrite(SPEED_RIGHT, 0 );
     analogWrite(DIR_RIGHT, 0);   
     analogWrite(SPEED_LEFT, 0 );


     
     int val1 = analogRead(sharp1);
   //delay(100);
 //   Serial.println(val1);
    int val2 = analogRead(sharp2);
   //delay(100);
   // Serial.println(val2);
}*/
void setup() 
{

   Serial.begin(115200);
    pinMode(SPEED_LEFT , OUTPUT);
    pinMode(SPEED_RIGHT , OUTPUT);
    pinMode(DIR_LEFT , OUTPUT);
    pinMode(DIR_RIGHT , OUTPUT);
    
   //while(digitalRead(9)==1)
  
} 
 
void loop() { 


  float volts1  = analogRead(sharp1)* 0.005 ; //    5/1024
                                   // value from sensor * (5/1024)
  int distance1 = 13*pow(volts1 , -1); // worked out from datasheet graph
 //Serial.println(distance1);

 
 
 float volts2  = analogRead(sharp2)* 0.005 ; //    5/1024                                  // value from sensor * (5/1024)
  int distance2 = 13*pow(volts2 , -1); // worked out from datasheet graph
// Serial.println(distance2);


 
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
   



    if (left_value <100)  left = 0;
    else left = 1;
   
    if (right_value <100)  right = 0;
    else right = 1;
/*
Serial.print("left_value = ");
   Serial.print(left_value);
    Serial.println(" ");
     Serial.println(" ");
      
   
  Serial.print("right_value = ");
   Serial.print(right_value);
  Serial.println(" ");
     Serial.println(" ");
      
*/

    
    if ((left == 0) && (right == 0)){
   runForward();                     } 
    
    else if (left == 1){ 
    steerLeft();       }
       
    else if (right == 1){
    steerRight();       }
       
/*

   
    if ((right == 1 && left==1 )&&(!flag)){
     //flag=true;
       while ((left==1) &&(right==1)){
          runForward();
       }
      }
        
        
  
   
   
     

      
    

      
  
     
   

      //int number = random(1,3);
      //if (number == 1)
        //ivent_1();
       
     // else ivent_2();
                                      
     

    else if (right == 0 || left==0 )
      flag=false;
   */
}
