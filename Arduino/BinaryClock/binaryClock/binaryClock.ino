int btnPin = 13;
int sec1Pin = 3;
int sec2Pin = 4;
int sec4Pin = 5;
int sec8Pin = 6;
int sec16Pin = 7;
int sec32Pin = 8;

long lastSec = 0;
int seconds = 0;
int activated = HIGH;         
int buttonState;             
int lastButtonState = LOW;

long lastDebounceTime = 0;
long debounceDelay = 100;

void (* funcs[])() = {ShowTime};

void setup() {
  pinMode(btnPin, INPUT);
  pinMode(sec1Pin, OUTPUT);
  pinMode(sec2Pin, OUTPUT);
  pinMode(sec4Pin, OUTPUT);
  pinMode(sec8Pin, OUTPUT);
  pinMode(sec16Pin, OUTPUT);
  pinMode(sec32Pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  DebounceRead(btnPin, &lastButtonState, &buttonState);
  if (buttonState == HIGH) {
    activated = !activated;
  }
  if (activated){
    ExecuteEvery(1,0);
  }
}

void ShowTime()
{
  seconds++;
  if (seconds == 60)
  {
     seconds = 0;
  }
  digitalWrite(sec1Pin, HIGH && (seconds & B00000001));
  digitalWrite(sec2Pin, HIGH && (seconds & B00000010));
  digitalWrite(sec4Pin, HIGH && (seconds & B00000100));
  digitalWrite(sec8Pin, HIGH && (seconds & B00001000));
  digitalWrite(sec16Pin, HIGH && (seconds & B00010000));
  digitalWrite(sec32Pin, HIGH && (seconds & B00100000));
}

void DebounceRead(int btn, int *lastState, int *destination)
{
  int reading = digitalRead(btn);
  if (reading != *lastState) {
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != *destination) {
      *destination = reading;
    }
  }
  
  *lastState = reading;
}


void ExecuteEvery(int seconds, int funcNumber)
{
  long secs = millis()/1000;
  if ((lastSec + seconds) == secs)
  {
    funcs[funcNumber]();
    lastSec = secs;
  }
}
