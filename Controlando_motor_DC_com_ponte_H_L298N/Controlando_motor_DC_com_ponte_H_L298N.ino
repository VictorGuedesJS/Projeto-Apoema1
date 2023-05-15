//Controlando até dois motores DC usando Ponte H L298N

//Definiçõs dos pinos Arduino conectados a entrada da Ponte H
//motor_A
int IN1 = 26;
int IN2 = 27;
int velocidadeA = 14;

//// motor B
//int IN3 = 6;
//int IN4 = 7;
//int velocidadeB = 5;

//variavel auxiliar
int velocidade = 0;
  
void setup()
{
  //Define os pinos como saida
  Serial.begin(9600); 	
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
// pinMode(IN3, OUTPUT);
// pinMode(IN4, OUTPUT);
 pinMode(velocidadeA,OUTPUT);
// pinMode(velocidadeB,OUTPUT);

 Serial.println("Digite A (acina) ou D (desliga) para controlar Motor DC");
}
  
void loop()
{
   
     if  (Serial.available() > 0) {
     
     EntradaDados = Serial.read();  		// lê o primeiro dado do buffer da serial
     if (EntradaDados == 'A') {  
       analogWrite(velocidadeA,150)       		// se for A
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);   		// aciona o pino
        Serial.println(" Motor acionado");
     } 
     
     if (EntradaDados == 'D') {        		// se for D
        digitalWrite(IN1, HIGH);  
        digitalWrite(IN2, HIGH);  		// desativa o pino
        Serial.println(" Motor desligado");
     }
     
  }  
}
