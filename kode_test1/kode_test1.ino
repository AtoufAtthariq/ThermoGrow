#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define DHT_TYPE DHT22
#define DHT_PIN A0
#define FAN_PIN 8
#define LAMP_PIN 9
#define SERVO_PIN 10  // Pilih pin yang sesuai untuk servo
#define SERVO_THRESHOLD 31  // Ambang batas suhu untuk mengaktifkan servo

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Sensor Reading");
  dht.begin();
  pinMode(FAN_PIN, OUTPUT);
  pinMode(LAMP_PIN, OUTPUT);
  myservo.attach(SERVO_PIN);
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

  // Menggerakkan servo jika suhu di atas 31 derajat
  if (temperature > SERVO_THRESHOLD) {
    myservo.write(90);  // Posisi tengah servo (sesuaikan dengan kebutuhan)
  } else {
    myservo.write(0);   // Posisi awal servo (sesuaikan dengan kebutuhan)
  }

  delay(2000); // Delay untuk memberikan waktu sebelum pembacaan berikutnya
}#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define DHT_TYPE DHT22
#define DHT_PIN A0
#define FAN_PIN 8
#define LAMP_PIN 9
#define SERVO_PIN 10  // Pilih pin yang sesuai untuk servo
#define SERVO_THRESHOLD 31  // Ambang batas suhu untuk mengaktifkan servo

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Sensor Reading");
  dht.begin();
  pinMode(FAN_PIN, OUTPUT);
  pinMode(LAMP_PIN, OUTPUT);
  myservo.attach(SERVO_PIN);
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

  // Menggerakkan servo jika suhu di atas 31 derajat
  if (temperature > SERVO_THRESHOLD) {
    myservo.write(90);  // Posisi tengah servo (sesuaikan dengan kebutuhan)
  } else {
    myservo.write(0);   // Posisi awal servo (sesuaikan dengan kebutuhan)
  }

  delay(2000); // Delay untuk memberikan waktu sebelum pembacaan berikutnya
}#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define DHT_TYPE DHT22
#define DHT_PIN A0
#define FAN_PIN 8
#define LAMP_PIN 9
#define SERVO_PIN 10  // Pilih pin yang sesuai untuk servo
#define SERVO_THRESHOLD 31  // Ambang batas suhu untuk mengaktifkan servo

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Sensor Reading");
  dht.begin();
  pinMode(FAN_PIN, OUTPUT);
  pinMode(LAMP_PIN, OUTPUT);
  myservo.attach(SERVO_PIN);
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

  // Menggerakkan servo jika suhu di atas 31 derajat
  if (temperature > SERVO_THRESHOLD) {
    myservo.write(90);  // Posisi tengah servo (sesuaikan dengan kebutuhan)
  } else {
    myservo.write(0);   // Posisi awal servo (sesuaikan dengan kebutuhan)
  }

  delay(2000); // Delay untuk memberikan waktu sebelum pembacaan berikutnya
}#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define DHT_TYPE DHT22
#define DHT_PIN A0
#define FAN_PIN 8
#define LAMP_PIN 9
#define SERVO_PIN 10  // Pilih pin yang sesuai untuk servo
#define SERVO_THRESHOLD 31  // Ambang batas suhu untuk mengaktifkan servo

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Sensor Reading");
  dht.begin();
  pinMode(FAN_PIN, OUTPUT);
  pinMode(LAMP_PIN, OUTPUT);
  myservo.attach(SERVO_PIN);
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

  // Menggerakkan servo jika suhu di atas 31 derajat
  if (temperature > SERVO_THRESHOLD) {
    myservo.write(90);  // Posisi tengah servo (sesuaikan dengan kebutuhan)
  } else {
    myservo.write(0);   // Posisi awal servo (sesuaikan dengan kebutuhan)
  }

  delay(2000); // Delay untuk memberikan waktu sebelum pembacaan berikutnya
}
