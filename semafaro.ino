//Definicao pinos leds
int pinoled_ver = 3;
int pinoled_ama = 4;
int pinoled_verm = 5;

void setup()
{
  pinMode(pinoled_ver, OUTPUT);
  pinMode(pinoled_ama, OUTPUT);
  pinMode(pinoled_verm, OUTPUT);
}

void loop()
{
  digitalWrite(pinoled_ama, LOW);
  digitalWrite(pinoled_verm, HIGH);
  
  delay(3000);
  
  digitalWrite(pinoled_verm, LOW);
  digitalWrite(pinoled_ver, HIGH);

  delay(3000);

  digitalWrite(pinoled_ver, LOW);
  digitalWrite(pinoled_ama, HIGH);

  delay(1500);
 }
