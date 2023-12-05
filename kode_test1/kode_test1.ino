#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHT_TYPE DHT22
#define DHT_PIN A0
#define FAN_PIN 8
#define LAMP_PIN 7

DHT dht(DHT_PIN, DHT_TYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Sensor Reading");
  dht.begin();
  pinMode(FAN_PIN, OUTPUT);
  pinMode(LAMP_PIN, OUTPUT);
}

void loop() {
  // Membaca suhu dan kelembaban dari sensor DHT22
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Memeriksa apakah pembacaan suhu dan kelembaban berhasil
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Gagal membaca sensor DHT22!");
    return;
  }

  // Menampilkan hasil pembacaan suhu dan kelembaban di Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.print(" C, Kelembaban: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Menampilkan hasil pembacaan suhu dan kelembaban di LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Suhu: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Kelembaban: ");
  lcd.print(humidity);
  lcd.print(" %");
  lcd.setBacklight(1);

  // Menghidupkan kipas jika suhu kurang dari 29 dan suhu tidak lebih dari 31
  if (temperature < 29 && temperature <= 31) {
    digitalWrite(FAN_PIN, HIGH);
  } else {
    digitalWrite(FAN_PIN, LOW);
  }

  // Menghidupkan lampu jika kelembaban kurang dari 90
  if (humidity < 90) {
    digitalWrite(LAMP_PIN, HIGH);
  } else {
    digitalWrite(LAMP_PIN, LOW);
  }

  delay(2000); // Delay untuk memberikan waktu sebelum pembacaan berikutnya
}
