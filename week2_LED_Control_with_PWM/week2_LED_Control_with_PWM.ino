const int RLED = 9;
const int GLED = 10;
const int BLED = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 100; i >= 20; i -= 20) {
    int val = (i/100.0 * 255 + 0.5); // 반올림
    
    for (int j = 300; j >= 100; j -= 100) {
      analogWrite(RLED, val);
      analogWrite(GLED, 0);
      analogWrite(BLED, 0);

      delay(j);

      analogWrite(RLED, 0);
      analogWrite(GLED, val);
      analogWrite(BLED, 0);

      delay(j);

      analogWrite(RLED, 0);
      analogWrite(GLED, 0);
      analogWrite(BLED, val);

      delay(j);
    }
  }
}
