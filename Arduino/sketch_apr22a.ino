#define ch1    A0
#define ch2   A1
#define ch3   A2
#define ch4   A3
#define ch5   A4
#define ch6   A5
#define ch7   A6
#define ch8   A7
#define ch9   2
#define ch10    3
#define ch11  4
#define ch12    5
#define ch13    6
#define ch14    7
#define ch15    8
#define ch16    9
#define ch17    10
#define ch18    11

#define trigPin 12
#define echoPin 13



unsigned long Current_moment;
unsigned long Duty_cycle = 2000 ;
unsigned long Cycle_duration;
unsigned long Cycle_begin;
unsigned long Step_timer_start_time;
unsigned long Step_timer_step = 10000; // раз в секунду 



unsigned long PWM_CH1;
unsigned long PWM_CH2;
unsigned long PWM_CH3;
unsigned long PWM_CH4;
unsigned long PWM_CH5;
unsigned long PWM_CH6;
unsigned long PWM_CH7;
unsigned long PWM_CH8;
unsigned long PWM_CH9;
unsigned long PWM_CH10;
unsigned long PWM_CH11;
unsigned long PWM_CH12;
unsigned long PWM_CH13;
unsigned long PWM_CH14;
unsigned long PWM_CH15;
unsigned long PWM_CH16;
unsigned long PWM_CH17;
unsigned long PWM_CH18;

int inc;
char incomingByte;

unsigned long Radar_timer_start_time;
unsigned long Radar_timer_step = 1000000;
unsigned int integerValue=0;  // Max value is 65535
unsigned long Radar_trig_low_time = 2000;
unsigned long Radar_trig_high_time = 10000;
unsigned long Radar_Start_Meassure_Time;
unsigned long cm; // < - можно по сути сменить на int но надо поиграться в железе 

int Radar_Step;


void setup() {
  Serial.begin(115200);
  
  pinMode(ch1, OUTPUT);
  pinMode(ch2, OUTPUT);
  pinMode(ch3, OUTPUT);
  pinMode(ch4, OUTPUT);
  pinMode(ch5, OUTPUT);
  pinMode(ch6, OUTPUT);
  pinMode(ch7, OUTPUT);
  pinMode(ch8, OUTPUT);
  pinMode(ch9, OUTPUT);
  pinMode(ch10, OUTPUT);
  pinMode(ch11, OUTPUT);
  pinMode(ch12, OUTPUT);
  pinMode(ch13, OUTPUT);
  pinMode(ch14, OUTPUT);
  pinMode(ch15, OUTPUT);
  pinMode(ch16, OUTPUT);
  pinMode(ch17, OUTPUT);
  pinMode(ch18, OUTPUT);
  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
}

void loop() {
  Current_moment = micros();
  Cycle_duration = Current_moment - Cycle_begin;
  
  if ( Cycle_duration >= Duty_cycle )
  {
 
    Cycle_begin = Current_moment;
    Cycle_duration = 0;
 //процедура поднятия всех ножек
    digitalWrite(ch1,HIGH); 
  digitalWrite(ch2,HIGH); 
    digitalWrite(ch3,HIGH); 
  digitalWrite(ch4,HIGH); 
    digitalWrite(ch5,HIGH); 
  digitalWrite(ch6,HIGH); 
    digitalWrite(ch7,HIGH); 
  digitalWrite(ch8,HIGH); 
    digitalWrite(ch9,HIGH); 
  digitalWrite(ch10,HIGH); 
    digitalWrite(ch11,HIGH); 
  digitalWrite(ch12,HIGH); 
    digitalWrite(ch13,HIGH); 
  digitalWrite(ch14,HIGH); 
    digitalWrite(ch15,HIGH); 
  digitalWrite(ch16,HIGH); 
    digitalWrite(ch17,HIGH); 
  digitalWrite(ch18,HIGH); 
}

  if (Cycle_duration >= PWM_CH1 ){digitalWrite(ch1,LOW);}
  if (PWM_CH1 >= Duty_cycle){PWM_CH1 = Duty_cycle;}
//----------------------------------------------
  if (Cycle_duration >= PWM_CH2 ){digitalWrite(ch2,LOW);}
  if (PWM_CH2 >= Duty_cycle){PWM_CH2 = Duty_cycle;}
//----------------------------------------------
  if (PWM_CH3 >= Duty_cycle){PWM_CH3 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH3 ){digitalWrite(ch3,LOW);}
//----------------------------------------------
  if (PWM_CH4 >= Duty_cycle){PWM_CH4 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH4 ){digitalWrite(ch4,LOW);}
//----------------------------------------------
  if (PWM_CH5 >= Duty_cycle){PWM_CH5 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH5 ){digitalWrite(ch5,LOW);}
//----------------------------------------------
  if (PWM_CH6 >= Duty_cycle){PWM_CH6 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH6 ){digitalWrite(ch6,LOW);}
//----------------------------------------------
  if (PWM_CH7 >= Duty_cycle){PWM_CH7 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH7 ){digitalWrite(ch7,LOW);}
//----------------------------------------------
  if (PWM_CH8 >= Duty_cycle){PWM_CH8 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH8 ){digitalWrite(ch8,LOW);}  
  //----------------------------------------------
  if (PWM_CH9 >= Duty_cycle){PWM_CH9 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH9 ){digitalWrite(ch9,LOW);}
//----------------------------------------------
  if (PWM_CH10 >= Duty_cycle){PWM_CH10 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH10 ){digitalWrite(ch10,LOW);}
//----------------------------------------------
  if (PWM_CH11 >= Duty_cycle){PWM_CH11 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH11 ){digitalWrite(ch11,LOW);}
//----------------------------------------------
  if (PWM_CH12 >= Duty_cycle){PWM_CH12 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH12 ){digitalWrite(ch12,LOW);}
 //----------------------------------------------
  if (PWM_CH13 >= Duty_cycle){PWM_CH13 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH13 ){digitalWrite(ch13,LOW);}
 //----------------------------------------------
  if (PWM_CH14 >= Duty_cycle){PWM_CH14 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH14 ){digitalWrite(ch14,LOW);}
//----------------------------------------------
  if (PWM_CH15 >= Duty_cycle){PWM_CH15 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH15 ){digitalWrite(ch15,LOW);}
//----------------------------------------------
  if (PWM_CH16 >= Duty_cycle){PWM_CH16 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH16 ){digitalWrite(ch16,LOW);}
//----------------------------------------------
  if (PWM_CH17 >= Duty_cycle){PWM_CH17 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH17 ){digitalWrite(ch17,LOW);}
//----------------------------------------------
  if (PWM_CH18 >= Duty_cycle){PWM_CH18 = Duty_cycle;}
  if (Cycle_duration >= PWM_CH18 ){digitalWrite(ch18,LOW);}
//----------------------------------------------
//----------------------------------------------



  if (Serial.available() > 0) {   
    integerValue = 0;         
    while(1) {            
      incomingByte = Serial.read();
      if (incomingByte == ';') {
    inc++;
    break;}   
      if (incomingByte == -1) continue;  // if no characters are in the buffer read() returns -1 
      integerValue *= 10;  // shift left 1 decimal place
      // convert ASCII to integer, add, and shift left 1 decimal place
      integerValue = ((incomingByte - 48) + integerValue);
    }
  if (inc >= 18){inc = 0;}
  }
  if (inc == 1 ) {PWM_CH1 = integerValue;} // <- по сути если переписать на case switch будет быстрее 
  else if (inc ==2 ){PWM_CH2 = integerValue;}
  else if (inc == 3){PWM_CH3 = integerValue;}
  else if (inc == 4){PWM_CH4 = integerValue;}
  else if (inc == 5){PWM_CH5 = integerValue;}
  else if (inc == 6){PWM_CH6 = integerValue;}
  else if (inc == 7){PWM_CH7 = integerValue;} 
  else if (inc == 8){PWM_CH8 = integerValue;}
  else if (inc == 9){PWM_CH9 = integerValue;}
  else if (inc == 10){PWM_CH10 = integerValue;}
  else if (inc == 11){PWM_CH11 = integerValue;}
  else if (inc == 12){PWM_CH12 = integerValue;}
  else if (inc == 13){PWM_CH13 = integerValue;}
  else if (inc == 14){PWM_CH14 = integerValue;}
  else if (inc == 15){PWM_CH15 = integerValue;}
  else if (inc == 16){PWM_CH16 = integerValue;}
  else if (inc == 17){PWM_CH17 = integerValue;}
  else if (inc == 18){PWM_CH18 = integerValue;}


if (Current_moment - Radar_timer_start_time >= Radar_timer_step)
{
  Radar_timer_start_time = Current_moment;
  Radar_Step = 1;
  digitalWrite(trigPin, LOW); 
}
if (Radar_Step == 1){
  if ((Current_moment - Radar_timer_start_time) >= Radar_trig_low_time ){
  digitalWrite(trigPin, HIGH);
  Radar_Step = 2;
  }
}
if (Radar_Step == 2 ){
  if ((Current_moment - Radar_timer_start_time) >= Radar_trig_high_time){
    Radar_Step = 3;
    digitalWrite(trigPin, LOW);
  }}
if (Radar_Step == 3){
  if (digitalRead(echoPin) == HIGH){
    Radar_Start_Meassure_Time = Current_moment;
  Radar_Step = 4;
}}
if (Radar_Step == 4)
{
  if (digitalRead(echoPin) == LOW)
  {
  int duration = Current_moment - Radar_Start_Meassure_Time;
  cm = (duration / 58);
  
   Serial.print(Current_moment); 
  Serial.println(" Current_moment"); 
  
  Serial.print(duration); 
  Serial.println(" duration");

  Serial.print(cm); 
  Serial.println(" cm");
  
  Serial.print(PWM_CH10); 
  Serial.println(" PWM_CH10");
 

  Radar_Step = 0;
    
  }
//  PWM_CH10 = cm *40; <- баловался с дальномером
}



}

  


