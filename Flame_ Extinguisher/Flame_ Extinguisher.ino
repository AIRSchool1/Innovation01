// EAZYTRONIC.COM
int val = 0 ;
void setup()
{
    Serial.begin(9600);
    pinMode(5,INPUT);  // Rain sensor output pin connected
    pinMode(6,OUTPUT); // Relay
    pinMode(7,OUTPUT); // BuzZer 

    digitalWrite(6,HIGH); // Relay
}
void loop() 
{
   val = digitalRead(5);  //  Rain sensor output pin connected
   Serial.println(val);   // see the value in serial monitor in Arduino IDE
   delay(100);
   
  if(val == 0 )
  {
    digitalWrite(6,LOW); // Relay
    digitalWrite(7,HIGH); // Buzzer
  }
   if(val == 1 )
  {
    digitalWrite(6,HIGH); // Relay
    digitalWrite(7,LOW); // Buzzer
  }
  }