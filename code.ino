int botao = 6;
int leds[]{2,3,4,5};
int posicaoSequencia;

void setup() 
{
  posicaoSequencia = 0;
  pinMode(botao,INPUT);
  //Serial.begin(9600);
 
  for(int i = 0; i<4; i++)
  {
    pinMode(leds[i],OUTPUT);
  } 
}
void loop() 
{  
  if(digitalRead(botao) == HIGH)
  {
    posicaoSequencia += 1;
  }

  if(posicaoSequencia > 2){posicaoSequencia = 0;}

   switch(posicaoSequencia)
  {
    case 1:
    Sequencia(200);
    break;
    
    case 2:
    Sequencia(100);
    break;
  }
}
void Sequencia(int delayTime)
{
  for(int i = 0; i < 4; i++)
  {
    digitalWrite(leds[i],HIGH);
  }

  delay(delayTime);

  for(int i = 0; i < 4; i++)
  {
    digitalWrite(leds[i],LOW);
  }

 delay(delayTime);
}
