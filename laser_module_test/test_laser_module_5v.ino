// 레이저 모듈 제어 소스
int Laser_pin = 7;      // 레이저 제어 핀
 
void setup() {
  pinMode(Laser_pin, OUTPUT);        // 출력보드
}
 
void loop() {                        // 1초마다 레이저 on/off 동작을 반복
 
  digitalWrite(Laser_pin, HIGH);
  delay(1000);
  digitalWrite(Laser_pin, LOW);
  delay(1000);
 
}
