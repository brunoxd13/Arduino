//Constante que representa o pino onde o positivo do buzzer será ligado.
const int buzzer = 3;

//Método setup, executado uma vez ao ligar o Arduino.
void setup() {
  //Definindo o pino buzzer como de saída.
  pinMode(buzzer,OUTPUT);
}

//Método loop, executado enquanto o Arduino estiver ligado.
void loop() {  
  int melodiaGuns[] = {69,277,208,185,740,208, 698,208,69,277,208,185,740,208, 698,208,
  
                       156,277,208,185,740,208, 698,208,156,277,208,185,740,208, 698,208,
  
                       185,277,208,185,740,208, 698,208,185,277,208,185,740,208, 698,208,
  
                       622,415,554,415,622,415,698,415,740,415,698,415,622,415};

					 

  for (int nota = 0; nota < 62; nota++){
  
    tone(buzzer, melodiaGuns[nota]*4,200);
  
    delay(260);
  
    noTone(buzzer);
  
  }
} 
