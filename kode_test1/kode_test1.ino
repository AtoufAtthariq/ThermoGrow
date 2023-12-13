#include <DHT.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHT_TYPE DHT22
#define DHT_PIN A0
#define LIGHT_PIN 8
#define SERVO_PIN 3
#define EXHAUST_PIN 9 // Misalkan pin 9 digunakan untuk exhaust fan

DHT dht(DHT_PIN, DHT_TYPE);
Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Ganti alamat sesuai dengan alamat modul LCD Anda

void setup() {
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(SERVO_PIN, OUTPUT);
  pinMode(EXHAUST_PIN, OUTPUT);

  Serial.begin(9600);
  dht.begin();
  servo.attach(SERVO_PIN);

  lcd.begin(16, 2);
  lcd.backlight(); // Menyalakan backlight LCD
  lcd.print("Suhu: ");
  lcd.setCursor(0, 1);
  lcd.print("Kelembaban: ");
}

void loop() {
  while (true) {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("Gagal membaca sensor DHT!");
      return;
    }

    Serial.print("Suhu: ");
    Serial.print(temperature);
    Serial.print(" C, Kelembaban: ");
    Serial.print(humidity);
    Serial.println("%");

    // Tampilkan suhu di LCD
    lcd.setCursor(6, 0);
    lcd.print(temperature);
    lcd.print(" C");

    // Tampilkan kelembaban di LCD
    lcd.setCursor(12, 1);
    lcd.print(humidity);
    lcd.print("%");

    // Kontrol lampu berdasarkan suhu
    if (temperature < 24) {
      digitalWrite(LIGHT_PIN, HIGH); // Hidupkan lampu
      servo.write(0); // Kembalikan servo ke posisi awal (0 derajat) saat suhu di bawah 28 derajat
    } else {
      digitalWrite(LIGHT_PIN, LOW); // Matikan lampu
      servo.write(100); // Putar servo ke posisi 100 saat suhu di atas 28 derajat
    }

    // Kontrol exhaust fan berdasarkan kelembaban
    if (humidity > 90) {
      digitalWrite(EXHAUST_PIN, HIGH); // Hidupkan exhaust fan
    } else {
      digitalWrite(EXHAUST_PIN, LOW); // Matikan exhaust fan
    }

    delay(2000); // Delay untuk memberikan waktu sebelum pembacaan berikutnya
  }
}
