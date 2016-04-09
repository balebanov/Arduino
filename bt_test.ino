#include <SoftwareSerial.h>

int val;
int LED = 8;

SoftwareSerial BT(15,14);

void setup() {
  BT.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (BT.available()) {
    val = BT.read();

    // При символе "W" включаем светодиод
   if (val == 'W') {
    digitalWrite(LED, HIGH);
   }

   // При символе "S" выключаем светодиод
   if ( val == 'S') {
    digitalWrite(LED, LOW);
   }
  }
}

