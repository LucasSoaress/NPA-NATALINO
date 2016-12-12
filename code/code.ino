int botao = 2;
int ledA = 3;
int ledB = 4;
int ledC = 5;
int ledD = 6;
int posicaoSequencia;

void setup() 
{
  posicaoSequencia = 0;
  pinMode(botao,INPUT);

  pinMode(botao, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(botao), MudaSequencia, RISING);
    
  pinMode(ledA,OUTPUT);
  pinMode(ledB,OUTPUT);
  pinMode(ledC,OUTPUT);
  pinMode(ledD,OUTPUT);
}

void MudaSequencia()
{
	if (posicaoSequencia > 5)
	{
	  posicaoSequencia = 0; 
	}
	else
	{
	  posicaoSequencia += 1; 
	}
