#define LM35 A0

void setup()
{
  Serial.begin(9600);
  pinMode(LM35 , INPUT);
}

void loop()
{
  float sensorValue = analogRead(LM35);
  
  float Volt = sensorValue * (5.0 / 1023.0);
  float Temp = (Volt / 0.01) ;
  
  Serial.print("Temperature: ");
  Serial.print(Temp);
  Serial.println(" C");
  Serial.print("Volt: ");
  Serial.print(Volt);
  Serial.println(" V");
  delay(1000);
}
