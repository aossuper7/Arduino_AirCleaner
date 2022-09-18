#include <pm2008_i2c.h>
#include <PWM.h>

PM2008_I2C pm2008_i2c;
int32_t frequency = 980000;
uint8_t pin = 5;
void setup() {
#ifdef PM2008N
  // wait for PM2008N to be changed to I2C mode
  delay(10000);
#endif
  pm2008_i2c.begin();
  Serial.begin(9600);
  pm2008_i2c.command();
  pinMode(pin, OUTPUT);
  InitTimersSafe();
  SetPinFrequencySafe(pin, frequency);
  delay(1000);
}

void loop() {
  uint8_t ret = pm2008_i2c.read();
  int32_t ultdust = pm2008_i2c.pm1p0_grimm + pm2008_i2c.pm2p5_grimm;
  int32_t dust = pm2008_i2c.pm10_grimm;
  if (ret == 0) {
    if (0 < ultdust && ultdust < 15 && 0 < dust && dust < 31) // 미세먼지 없을 때
      pwmWrite(pin, 0);
    else if (15 < ultdust && ultdust < 36 && 30 < dust && dust < 81) //보통일때
      pwmWrite(pin, 50);
    else if(36 < ultdust && 81 < dust) // 미세먼지 심할 때
      pwmWrite(pin, 80);
  }
  delay(300000); //5분마다 체크
}
