int readPin = A1;
int readValue;
int LEDPin = 3;
int darkMeter = 850;
int dayNumb = 1;

void setup() {
  // put your setup code here, to run once:
pinMode(readPin, INPUT);
pinMode(LEDPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
readValue = analogRead(readPin);
if (readValue > darkMeter){
  Serial.println("The sky is dark so light on");
  Serial.print("Day: ");
  Serial.println(dayNumb);
  Serial.println();
  dayNumb = dayNumb + 1;
  if (dayNumb % 366 == 0){
  Serial.println("CONGRATS-- It's a The End of YEAR");
  dayNumb = 1;
  Serial.println();
}
}
while (readValue > darkMeter){
  readValue = analogRead(readPin);
  digitalWrite(LEDPin, HIGH);
}
digitalWrite(LEDPin, LOW);


delay(150);
}
