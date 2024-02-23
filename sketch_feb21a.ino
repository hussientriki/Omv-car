 # define THRESHOLD 400

//Define Pins

//Motor Pins
//Enable Pin of the Right Motor (must be PWM)
#define LM1 5       // left motor
#define LM2 6       // left motor
#define ENA 11
#define RM1 7       // right motor
#define RM2 8       // right motor
#define ENB 10

//Sensors Pins
int Out1 = 0;
int Out2 = 1;
int Out3 = 2;
int Out4 = 3;
int Out5 = 4;


//Sensor values initialization
int Sensor1 = 1;
int Sensor2 = 1;
int Sensor3 = 1;
int Sensor4 = 1;
int Sensor5 = 1;


//Funtion Declerations
void MoveForward(void);
void MoveRight(void);
void MoveLeft(void);
void MoveBack(void);
void MoveSRight(void);
void MoveSLeft(void);
void Stop (void);


void setup() {

  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(Out1, INPUT);
  pinMode(Out2, INPUT);
  pinMode(Out3, INPUT);
  pinMode(Out4, INPUT);
  pinMode(Out5, INPUT);

  Serial.begin(9600); 
  
}

void loop(){
  //Use analogWrite to run motor at adjusted speed
    analogWrite(ENA, 100);
    analogWrite(ENB, 100);
  Sensor1 = digitalRead(Out1);
  Sensor2 = digitalRead(Out2);
  Sensor3 = digitalRead(Out3);
  Sensor4 = digitalRead(Out4);
  Sensor5 = digitalRead(Out5);


  // White = 1
  // Black = 0
  
  //Sensor1 = Sensor1 > THRESHOLD? 0:1;
  //Sensor2 = Sensor2 > THRESHOLD? 0:1;
  //Sensor3 = Sensor3 > THRESHOLD? 0:1;
  //Sensor4 = Sensor4 > THRESHOLD? 0:1;
 // Sensor5 = Sensor5 > THRESHOLD? 0:1;



if (Sensor1 && Sensor2 && Sensor4 && Sensor5) //  2 sensor work
 {
  
   MoveForward();
   Stop();
 }
 if (!Sensor1 || !Sensor2){
   MoveSRight();
  
  while (!Sensor1 || !Sensor2)
   MoveSRight();
   
 }
//if (!Sensor4 && !Sensor5)
//{
 //  MoveLeft();
   //Stop();
   //while (!Sensor4 && !Sensor5){
    //MoveLeft();
   //}
 //}

delay(5);

}

void MoveForward(void)
{

    
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    delay(35);
}

void MoveBack(void)
{

    
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    delay(40);
}

void MoveSRight(void)
{
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
delay(110);
}

void MoveSLeft(void)
{
    
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH); 
    digitalWrite(RM2, LOW);
delay(110);
}

void MoveRight(void)
{
     
    
    digitalWrite(LM1, LOW); 
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
   
}

void MoveLeft(void)
{
     
    
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW); 
    digitalWrite(RM2, LOW);
}

void Stop(void)
{
       
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
}