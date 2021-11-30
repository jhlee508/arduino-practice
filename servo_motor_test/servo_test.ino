#include <Servo.h>    // 서보모터 라이브러리
 
Servo servo;    // 서보모터 사용을 위한 객체 생성
 
int motor = 2;  // 서보모터의 핀 
int angle = 90; // 서보모터 초기 각도 값

void setup() {
  servo.attach(motor);  // 서보모터 연결
  Serial.begin(9600);  // 시리얼 모니터 시작
    
  Serial.println("Enter the u or d"); // u 또는 d키 입력하기
  Serial.println("u = angle + 15");   // u를 누른다면 현재 각도값에서 +15도
  Serial.println("d = angle - 15\n");   // d를 누른다면 현재 각도값에서 -15도
}
 
void loop() {
  servo.write(300);
  delay(1000);
  servo.write(0);
  delay(1000);
}
