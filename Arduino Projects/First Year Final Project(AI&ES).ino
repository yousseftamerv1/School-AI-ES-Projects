//sensors define
#define LDR A0
#define LM35 A1
#define IR A2
#define VARIABLE_RESISTOR A3

//7 segments define 
#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define g 7
#define f 8

//leds define
#define LED_BLUE 9
#define LED_YELLOW_0 10
#define LED_GREEN 11
#define LED_YELLOW_1 12
#define LED_RED 13

//iportant variables
int irRead;

//sensor functions

void LDR_READ()
{
    int sensorRead = analogRead(LDR);
  
 
    float volt = (5.0 * sensorRead) / 1023.0 ;
  

    Serial.print("Light: ");
    Serial.print(sensorRead);
    Serial.println(" (0-512)");
    Serial.print("Volt: ");
    Serial.print(volt);
    Serial.println(" V");
  
    delay(500);

    if (volt <= 0.5)
    {
      //zero
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,LOW);
    }

    if (volt >= 1.0)
    {
      //one
      digitalWrite(a,LOW);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
    }
    
   if(volt >= 1.5)
    {
      //two
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,LOW);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,LOW);
      digitalWrite(g,HIGH);
    }
    
    if(volt >= 2.0)
    {
      //three
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,HIGH);
    }
  
    if(volt >= 2.5)
    {
      //four
      digitalWrite(a,LOW);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);  
    }
    
    if(volt >= 3.0)
    {
      //five
      digitalWrite(a,HIGH);
      digitalWrite(b,LOW);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
    }
    
    if(volt >= 3.5)
    {
      //six
      digitalWrite(a,HIGH);
      digitalWrite(b,LOW);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
    }
    
    if(volt >= 4.0)
    {
      //seven
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
    }
    
    if(volt >= 4.5)
    {
      //eight
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
    }
    
    if(volt >= 5.0)
    {
      //nine
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
    }
}

void LM35_READ()
{
  int sensorValue = analogRead(LM35);
  
  float volt = sensorValue * ((5.0 / 1023.0) / 2.0);
  
  float temperature = volt * 100.0  ;
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
  Serial.print("Volt: ");
  Serial.print(volt);
  Serial.println(" V");
  
  delay(500);

  if (temperature >= 10)
  {

    digitalWrite(LED_BLUE , HIGH);
    digitalWrite(LED_YELLOW_0 , LOW);
    digitalWrite(LED_GREEN , LOW);
    digitalWrite(LED_YELLOW_1 , LOW);
    digitalWrite(LED_RED , LOW);
  }

  if (temperature >= 20)
  {
    digitalWrite(LED_BLUE , HIGH);
    digitalWrite(LED_YELLOW_0 , HIGH);
    digitalWrite(LED_GREEN , LOW);
    digitalWrite(LED_YELLOW_1 , LOW);
    digitalWrite(LED_RED , LOW);    
  }

  if (temperature >= 30)
  {
    digitalWrite(LED_BLUE , HIGH);
    digitalWrite(LED_YELLOW_0 , HIGH);
    digitalWrite(LED_GREEN , HIGH);
    digitalWrite(LED_YELLOW_1 , LOW);
    digitalWrite(LED_RED , LOW);
  }

  if (temperature >= 40)
  {
    digitalWrite(LED_BLUE , HIGH);
    digitalWrite(LED_YELLOW_0 , HIGH);
    digitalWrite(LED_GREEN , HIGH);
    digitalWrite(LED_YELLOW_1 , HIGH);
    digitalWrite(LED_RED , LOW);
  }


  if (temperature >= 50)
  {
    digitalWrite(LED_BLUE , HIGH);
    digitalWrite(LED_YELLOW_0 , HIGH);
    digitalWrite(LED_GREEN , HIGH);
    digitalWrite(LED_YELLOW_1 , HIGH);
    digitalWrite(LED_RED , HIGH);
  }
  
}

void setup()
{
  Serial.begin(9600);
  pinMode(LDR , INPUT);
  pinMode(LM35 , INPUT);
  pinMode(IR , INPUT);
  pinMode(VARIABLE_RESISTOR , INPUT);
  
  for (int i = 2 ; i <= 13 ; i++)
  {
    pinMode(i , OUTPUT);
  }
}

void loop()
{
  irRead = digitalRead(IR);
  
  if (irRead == HIGH)
  {
    int Variable_Resistor_Read = analogRead(VARIABLE_RESISTOR);
    float Volt = (Variable_Resistor_Read * 5.0 / 1023.0);
    
    Serial.print("Variable Resistor Read: ");
    Serial.println(Variable_Resistor_Read);
    
    Serial.print("Variable Resistor Volt: " );
    Serial.print(Volt);
    Serial.println(" V");
    delay(500);
    
    if (Volt <= 1)
    {
      Serial.println("============");
      LM35_READ();
      Serial.println("============");
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      
      delay(500);
    }
    
    else if (Volt >= 4)
    {
      Serial.println("============");
      LDR_READ();
      Serial.println("============");
      digitalWrite(LED_BLUE , LOW);
      digitalWrite(LED_YELLOW_0 , LOW);
      digitalWrite(LED_GREEN , LOW);
      digitalWrite(LED_YELLOW_1 , LOW);
      digitalWrite(LED_RED , LOW);
      delay(500);
    }    
    
    else if (Volt > 1 && Volt < 4)
    {
      Serial.println("============");
      LM35_READ();
      Serial.println("============");
      LDR_READ();
      Serial.println("============");
      delay(500);
    }
    
  }
  
   if (irRead == LOW)
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(LED_BLUE , LOW);
    digitalWrite(LED_YELLOW_0 , LOW);
    digitalWrite(LED_GREEN , LOW);
    digitalWrite(LED_YELLOW_1 , LOW);
    digitalWrite(LED_RED , LOW);
  }

}
