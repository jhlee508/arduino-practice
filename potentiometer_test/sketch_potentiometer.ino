const int RLED=9;
const int LIGHT=0;
const int MIN_LIGHT=200;
const int MAX_LIGHT=900;
int val=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  val = analogRead(LIGHT);
  Serial.println(val);
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0);
  Serial.println(val);
  val = constrain(val, 0, 255);
  Serial.println(val);
  Serial.println();
  delay(1000);
  analogWrite(RLED, val);
  
}
