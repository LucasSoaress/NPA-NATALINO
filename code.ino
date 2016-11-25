int botao = 6;
int leds[]{2,3,4,5};
int posicaoSequencia;

void setup() 
{
  posicaoSequencia = 0;
  pinMode(botao,INPUT);
  Serial.begin(9600);
 
  for(int i = 0; i<4; i++)
  {
    pinMode(leds[i],OUTPUT);
  } 
}


void loop() 
{  
  VerificarSequencia();
  
  if(posicaoSequencia > 5){
    Serial.println(posicaoSequencia);
    posicaoSequencia -= posicaoSequencia;
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


void SequenciaDois(int SecondDelay)
{
  for(int i = 0; i<4; i++)
  {
   digitalWrite(leds[i],HIGH);
   delay(SecondDelay); 
  }

  for(int i = 0; i<4; i++)
  {
    digitalWrite(leds[i],LOW);
    delay(SecondDelay);
  }
}


void VerificarSequencia()
{
  if(digitalRead(botao) == HIGH)
  {
    posicaoSequencia += 1;

    if(posicaoSequencia == 6)
    {
      posicaoSequencia = 0;
    }
    
    Serial.println(posicaoSequencia);
  }


   switch(posicaoSequencia)
  {
    case 1:
    Sequencia(200);
    break;
    
    case 2:
    Sequencia(100);
    break;

    case 3:
    SequenciaDois(50);
    break;

    case 4:
    SequenciaDois(200);
    break;

    case 5:
    SequenciaDois(500);
    break;
  }
}
