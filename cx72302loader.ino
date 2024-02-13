#include <SPI.h>
//Register loader for Skyworks CX7230x Fractional PLL chips
//Pin 10 CS, PIN 11 DATA, PIN 13 CLK
//CAUTION!!! THE CHIP USES 3V3 LOGIC SIGNALS, ARDUINO IS 5V!!!
void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  Serial.begin(9600);

  digitalWrite(10,HIGH);
  SPI.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  SPI.transfer(1);

  CXwrite(0x0027); //Main Divider
  CXwrite(0x13d1); //Main Dividend MSB
  CXwrite(0x20ec); //Main Dividend LSB
  CXwrite(0x5021); //Ref Divider
  CXwrite(0x67cf); //PhDet/Chrg
  CXwrite(0x7010); //PD/MuxOut

  delay(50000);

}

void CXwrite(uint16_t regval){

  digitalWrite(10,LOW);
  SPI.transfer16(regval);
  digitalWrite(10,HIGH);
  delayMicroseconds(800);

}
