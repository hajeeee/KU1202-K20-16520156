#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
const int pingPin = A1;
long dur, cm;
void setup()
{
  lcd.begin(16, 2);
  lcd.print("PING Sensor");
}

void loop()
{		
  cm = read_sensor_ultrasonic();
  lcd.setCursor(0,1);
  lcd.print("Jarak");
  lcd.setCursor(6,1);
  lcd.print(cm);
  if(cm>99){
    lcd.setCursor(9,1);
    lcd.print("cm");
  }
  else if(cm>9 && cm<=99){
    lcd.setCursor(8,1);
    lcd.print("cm");
    lcd.setCursor(10,1);
    lcd.print("   ");
  }
  else {
    lcd.setCursor(7,1);
    lcd.print("cm");
    lcd.setCursor(9,1);
    lcd.print("     ");
  }
  
}
long read_sensor_ultrasonic()
{
  long duration, cm;
  
  pinMode(pingPin, OUTPUT);		
  digitalWrite(pingPin, LOW);	
  delayMicroseconds(2);			
  digitalWrite(pingPin, HIGH);	
  delayMicroseconds(5);			
  digitalWrite(pingPin, LOW);	
  
  pinMode(pingPin, INPUT);						
  duration = pulseIn(pingPin, HIGH);			
  cm = microsecondsToCentimeters(duration);	
}

long microsecondsToCentimeters(long microseconds)
{
  // kecepatan suara 340 m/s atau 29 microsecond/cm
  // dibagi dua untuk mencari jarak sensor-objek
  return microseconds / 29 / 2;
}