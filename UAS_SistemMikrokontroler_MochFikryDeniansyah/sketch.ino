#define BLYNK_TEMPLATE_ID "TMPL6Y4JByvHr"
#define BLYNK_TEMPLATE_NAME "Kamera Dummy"
#define BLYNK_AUTH_TOKEN "WY5G3bSoKQcg7iB-WHVYDpk6PWsey0Kf"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Redmi Note 10";     // Ganti dengan WiFi kamu
char pass[] = "abcdefgh"; // Ganti dengan password WiFi kamu

const int pirPin = 13;         // Pin input sensor PIR
const int ledPin = 2;          // Pin output untuk LED indikator

BlynkTimer timer;

void checkMotion() {
  int motionDetected = digitalRead(pirPin);

  if (motionDetected == HIGH) {
    digitalWrite(ledPin, HIGH);
    Blynk.virtualWrite(V0, "Gerakan Terdeteksi!");
  } else {
    digitalWrite(ledPin, LOW);
    Blynk.virtualWrite(V0, "Tidak ada gerakan");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, checkMotion); // periksa setiap 1 detik
}

void loop() {
  Blynk.run();
  timer.run();
}
