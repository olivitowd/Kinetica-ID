const int btnPin = 13;
const int sec1Pin = 3;
const int sec2Pin = 4;
const int sec4Pin = 5;
const int sec8Pin = 6;
const int sec16Pin = 7;
const int sec32Pin = 8;

const int min1Pin = 9;
const int min2Pin = 10;
const int min4Pin = 11;
const int min8Pin = 12;

int seconds = 0;
int minutes = 0;
int hours = 0;
int activated = HIGH;         
int buttonState;             
int lastButtonState = LOW;

long lastDebounceTime = 0;
long debounceDelay = 200;

void (* funcs[])() = {OnEachSecond, CheckForButton};
long lastExecuted[] = {0, 0};

void setup() {
  pinMode(btnPin, INPUT);
  pinMode(sec1Pin, OUTPUT);
  pinMode(sec2Pin, OUTPUT);
  pinMode(sec4Pin, OUTPUT);
  pinMode(sec8Pin, OUTPUT);
  pinMode(sec16Pin, OUTPUT);
  pinMode(sec32Pin, OUTPUT);
  pinMode(min1Pin, OUTPUT);
  pinMode(min2Pin, OUTPUT);
  pinMode(min4Pin, OUTPUT);
  pinMode(min8Pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  DebounceRead(btnPin, &lastButtonState, &buttonState);
  
  ExecuteEvery(3,1);

  if (activated == HIGH){
    ExecuteEvery(10,0);
  }
}

void CheckForButton()
{
  Serial.print("ButtonState: ");
  Serial.println(buttonState);
  if (buttonState) {
    if (activated)
    {
      activated = HIGH;
    }else
    {
      activated = LOW;
    }
  }
}

void OnEachSecond()
{
  if (AddWithLimit(&seconds, 60)){
    if(AddWithLimit(&minutes, 60)){
      AddWithLimit(&hours, 24);
      OnEachHour();
    }
    OnEachMinute();
  }
  digitalWrite(sec1Pin, HIGH && (seconds & B00000001));
  digitalWrite(sec2Pin, HIGH && (seconds & B00000010));
  digitalWrite(sec4Pin, HIGH && (seconds & B00000100));
  digitalWrite(sec8Pin, HIGH && (seconds & B00001000));
  digitalWrite(sec16Pin, HIGH && (seconds & B00010000));
  digitalWrite(sec32Pin, HIGH && (seconds & B00100000));
}

void OnEachMinute()
{
  digitalWrite(min1Pin, HIGH && (minutes & B00000001));
  digitalWrite(min2Pin, HIGH && (minutes & B00000010));
  digitalWrite(min4Pin, HIGH && (minutes & B00000100));
  digitalWrite(min8Pin, HIGH && (minutes & B00001000)); 
}

void OnEachHour()
{
  
}

byte AddWithLimit(int *number, int limit)
{
  *number = *number + 1;
  if (*number == limit)
  {
    *number = 0;
    return true;
  }
  return false;
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


void ExecuteEvery(int secondsDecimal, int funcNumber)
{
  long secsDec = millis()/100;
  long lastSec = lastExecuted[funcNumber];
  if ((lastSec + secondsDecimal) == secsDec)
  {
    funcs[funcNumber]();
    lastExecuted[funcNumber] = secsDec;
  }
}
