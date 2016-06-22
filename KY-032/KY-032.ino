int lees  = A0;
int counter = 0;
int detect = 20;
int lastValue;
int button = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(lees, INPUT);
  pinMode(button, INPUT);
  digitalWrite(button, HIGH); //enable the pull-up resistor.
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(lees);
  int buttonState = digitalRead(button);
  Serial.print("pin 1 = ");
  Serial.print(a);
   Serial.print(" |        ButtonState = ");
  Serial.print(buttonState);

  if(a < detect && lastValue > 900){
    Serial.print("|      NEW OBJECT DETECTED!!!!!! Counter = ");
    counter ++;
    Serial.print(counter);
  }
  if(buttonState == 0){
    resetCounter();
  }

  lastValue = a;
  delay(200);
  Serial.println();

}
void resetCounter(){
  counter = 0 ;
  Serial.println(" |       Counter = 0");
  delay(1000);
  }

