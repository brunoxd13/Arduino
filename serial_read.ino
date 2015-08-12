#define LED 6

void setup() {
  Serial.begin(9600);    
  pinMode(LED,OUTPUT); 
  digitalWrite(LED, LOW) ;
}
void loop() {
  
  
   if (Serial.available()) //Existe alguma coisa para leitura
   {
    switch(Serial.read())//Pega o que foi enviado
    {
      case 'A':                  
        digitalWrite(LED,HIGH);
        break;
      case 'B':
        digitalWrite(LED,LOW);
        Serial.print("foi");
        break;
    }
  }
}
