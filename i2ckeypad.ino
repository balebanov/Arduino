#include <i2ckeypad.h>
#include <Wire.h>

#define ROWS 4
#define COLS 4

#define PCF8574_ADDR 0x38

i2ckeypad kpd = i2ckeypad(PCF8574_ADDR, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  kpd.init();
  Serial.print("Testing\n\n");
}

void loop() {
  char key = kpd.get_key();
  if(key != '\0'){
    Serial.print(key);
  }
}

