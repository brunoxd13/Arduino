/*
Programação para Arduino - Primeiros Passos
Programa de exemplo: Blink
*/

/* 
Declaração da variável "led"
Indica que o LED está conectado no pino digital 13 do Arduino (D13).
*/
int led = 13;

/*
Declaração da função setup()
Esta função é chamada apenas uma vez, quando o Arduino é ligado ou reiniciado.
*/
void setup() {
  // Chama a função pinMode() que configura um pino como entrada ou saída
  pinMode(led, OUTPUT); // Configura o pino do LED como saída
}

/*
Declaração da função loop()
Após a função setup() ser chamada, a função loop() é chamada repetidamente até
o Arduino ser desligado.
*/
void loop() {
  // Todas as linhas a seguir são chamadas de função com passagem de parâmetros
  // As funções são executadas em sequência para fazer o LED acender e apagar
  digitalWrite(led, HIGH); // Atribui nível lógico alto ao pino do LED, acendendo-o
  delay(1000);             // Espera 1000 milissegundos (um segundo)
  digitalWrite(led, LOW);  // Atribui nível lógico baixo ao pino do LED, apagando-o
  delay(1000);             // Espera 1000 milissegundos (um segundo)
  
  // Após terminar a função loop(), ela é executada novamente repetidas vezes,
  // e assim o LED continua piscando.
}
