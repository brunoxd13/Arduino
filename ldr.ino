int sensorPin = 0;
int val;
 
void setup() {
 Serial.begin(9600);
}
 
void loop() {
 val = analogRead(sensorPin);    // ler o valor do sensor 
 Serial.println(val);            //envia valor para o pc
 delay(1000);                    //aguarda 1 segundo
}
