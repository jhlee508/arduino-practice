#include <SoftwareSerial.h> // 블루투스 시리얼 통신을 위한 라이브러리

// TX, RX 핀 지정
#define BT_TXD 2
#define BT_RXD 3

// 블루투스 모듈 선언
SoftwareSerial bluetooth(BT_TXD, BT_RXD);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Bluetooth START");
}

void loop() {
  // 블루투스로 값이 들어오면
  if (bluetooth.available()) {
    // 값 출력
    Serial.write(bluetooth.read());
  }

  // 시리얼 모니터로 값이 입력되면
  if (Serial.available()) {
    // 값 출력
    bluetooth.write(Serial.read());
  }
}
