#include <ESP32Encoder.h>

// Motor pins (update according to ESP32 GPIO numbers)
#define m1 13
#define m2 12
#define en 14
#define SampleTimeMs 20
#define StepSize 5
#define SpeedTimeMs 500
#define PPR 2000

ESP32Encoder enc;

// Encoder pins
#define enc_a 27
#define enc_b 26

double rpm;
unsigned long lastms;
unsigned long last_count = 0;
int direction = true;  // Direction flag, true for forward, false for reverse

// PWM Configuration
int PWM = 20;

void setup() {
  ESP32Encoder::useInternalWeakPullResistors = puType::up;

  // Configure motor pins
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  enc.attachFullQuad(enc_a, enc_b);

  // Initialize serial communication
  Serial.begin(115200);

  // Initialize PWM and motor direction
  analogWrite(en, PWM);  // Use analogWrite for ESP32 PWM
  setDirection(direction);

  lastms = millis();
  sweepMotor();
  enc.clearCount();
}

void loop() {
  if (Serial.available()) {
    sweepMotor();
    while (Serial.available()) Serial.read();
  }
  // The sweepMotor function handles everything for now

  //Serial.println(enc.getCount());
  //delay(20);
}

void sweepMotor() {
  for (PWM = 20; PWM <= 240; PWM += 20) {
    for (direction = 0; direction < 2; direction++) {
      setDirection(direction);
      analogWrite(en, PWM);

      for (int j = 0; j < 25; j++) {
        RPM_calc();
        unsigned long currentTime = millis();
        Serial.print((float)currentTime / 1000.);  // Print the timestamp
        Serial.print(", ");
        Serial.print(rpm);  // Print RPM (negative for reverse)
        Serial.print(",");
        Serial.println(direction ? ((PWM * 12.0) / 255) : -((PWM * 12.0) / 255));  // Print Volt value
        while (millis() - lastms < SampleTimeMs) {
          delay(1);  // Small delay to prevent busy-waiting
        }
        lastms += SampleTimeMs;
      }
    }
    direction = 0;
  }
  analogWrite(en, 0);
}

void setDirection(bool dir) {
  if (dir) {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
  } else {
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
  }
}

void RPM_calc() {
  long long Pulses = enc.getCount();
  rpm = (((double)(Pulses - last_count) / PPR) / (SampleTimeMs / 1000.0)) * 60.0;
  enc.clearCount();
}
