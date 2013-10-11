int pinLed1 = 3;
int pinLed2 = 4;
int pinLed3 = 5;
int pinLed4 = 6;
int pinLed5 = 7;
int pinLed6 = 8;
int pinLed7 = 2;

int selector1 = 12;
int selector2 = 13;



void setup() {
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
  pinMode(pinLed5, OUTPUT);
  pinMode(pinLed6, OUTPUT);
  pinMode(pinLed7, OUTPUT);
  pinMode(selector1, OUTPUT);
  pinMode(selector2, OUTPUT);
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);
  digitalWrite(pinLed4, LOW);
  digitalWrite(pinLed5, OUTPUT);
  digitalWrite(pinLed6, OUTPUT);
  digitalWrite(pinLed7, OUTPUT);
}

void loop() {
  delay(10);
  imprimirNumero(3, 1);
  delay(10);
  imprimirNumero(1,2);
}

void imprimirNumero(byte numero, int selector)
{
  switch(numero)
  {
    case 1:
      ImprimirUno();
      break;
    case 2:
      ImprimirDos();
      break;
    case 3:
      ImprimirTres();
      break;
  }
  if (selector == 1)
  {
    digitalWrite(selector1, HIGH);
    digitalWrite(selector2, LOW);
  }else
  {
    digitalWrite(selector1, LOW);
    digitalWrite(selector2, HIGH);
  }
  
}


void ImprimirUno()
{
  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);
  digitalWrite(pinLed4, HIGH);
  digitalWrite(pinLed5, HIGH);
  digitalWrite(pinLed6, HIGH);
  digitalWrite(pinLed7, HIGH);
}

void ImprimirDos()
{
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, HIGH);
  digitalWrite(pinLed3, LOW);
  digitalWrite(pinLed4, LOW);
  digitalWrite(pinLed5, HIGH);
  digitalWrite(pinLed6, LOW);
  digitalWrite(pinLed7, LOW);
}

void ImprimirTres()
{
  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, HIGH);
  digitalWrite(pinLed4, HIGH);
  digitalWrite(pinLed5, HIGH);
  digitalWrite(pinLed6, HIGH);
  digitalWrite(pinLed7, HIGH);
}
