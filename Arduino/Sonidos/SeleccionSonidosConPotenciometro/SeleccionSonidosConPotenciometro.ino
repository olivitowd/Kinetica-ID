/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 */

int led = 9;
int potenciometer = A1;

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(potenciometer, INPUT);
  Serial.begin(9600);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  int valor = analogRead(potenciometer);
  int espera = map(valor, 0, 1023, 0, 20);
  digitalWrite(led, HIGH);
  delay(espera);
  digitalWrite(led, LOW);
}

