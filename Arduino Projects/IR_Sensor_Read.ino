#define IR 2

void setup() 
{
  Serial.begin(9600);
  pinMode(IR , INPUT);
}

void loop() 
{
  int sensorRead = digitalRead(IR);
  
  if (sensorRead == LOW)
  {
    Serial.println("Connected!!");
    delay(1000);
  } 

  else if (sensorRead == HIGH)
  {
    Serial.println("No Signal!!");
    delay(1000);    
  }
}
