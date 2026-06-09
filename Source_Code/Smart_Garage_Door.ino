#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9

// =====================
// COMPONENT PINS
// =====================
const int servoPin = 6;
const int buttonPin = 2;
const int ledPin = 7;
const int buzzerPin = 8;

// 🔥 Fire emergency signal from Eshan
const int fireEmergencyPin = A2;

// =====================
// RFID SETUP
// =====================
MFRC522 rfid(SS_PIN, RST_PIN);
Servo gateServo;

// =====================
// AUTHORIZED RFID UID
// =====================
byte authorizedUID[] = {0x73, 0xC2, 0x5F, 0x2D};
const byte uidLength = 4;

// =====================
// GATE OPEN TIME
// =====================
const unsigned long gateOpenTime = 5000;

// =====================
// SETUP
// =====================
void setup() {

  Serial.begin(9600);

  SPI.begin();
  rfid.PCD_Init();

  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  pinMode(fireEmergencyPin, INPUT);

  gateServo.attach(servoPin);

  // Gate starts closed
  gateServo.write(0);

  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);

  Serial.println("Smart Home Parking Gate Access System");
  Serial.println("Scan RFID card or press manual button.");
}

// =====================
// MAIN LOOP
// =====================
void loop() {

  // =========================================
  // 🔥 FIRE EMERGENCY MODE
  // =========================================
  if (digitalRead(fireEmergencyPin) == HIGH) {

    gateServo.write(90);

    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, LOW);

    Serial.println("FIRE EMERGENCY - GATE OPEN");

    return;
  }

  // =========================================
  // MANUAL OVERRIDE BUTTON
  // =========================================
  if (digitalRead(buttonPin) == LOW) {

    Serial.println("Manual button pressed - Gate opening");

    grantAccess();

    delay(300);

    return;
  }

  // =========================================
  // CHECK RFID CARD
  // =========================================
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  // =========================================
  // PRINT CARD UID
  // =========================================
  Serial.print("Card UID:");

  for (byte i = 0; i < rfid.uid.size; i++) {

    Serial.print(" ");

    if (rfid.uid.uidByte[i] < 0x10) {
      Serial.print("0");
    }

    Serial.print(rfid.uid.uidByte[i], HEX);
  }

  Serial.println();

  // =========================================
  // CHECK AUTHORIZATION
  // =========================================
  if (isAuthorized(rfid.uid.uidByte, rfid.uid.size)) {

    Serial.println("Access Granted - Gate opening");

    grantAccess();

  } else {

    Serial.println("Access Denied");

    denyAccess();
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

// =====================
// RFID AUTHORIZATION
// =====================
bool isAuthorized(byte *uid, byte size) {

  if (size != uidLength) {
    return false;
  }

  for (byte i = 0; i < uidLength; i++) {

    if (uid[i] != authorizedUID[i]) {
      return false;
    }
  }

  return true;
}

// =====================
// ACCESS GRANTED
// =====================
void grantAccess() {

  digitalWrite(ledPin, HIGH);

  // Success beep
  digitalWrite(buzzerPin, HIGH);

  delay(200);

  digitalWrite(buzzerPin, LOW);

  // Open gate
  gateServo.write(90);

  Serial.println("Gate is OPEN");

  // Keep gate open
  delay(gateOpenTime);

  // Close gate
  gateServo.write(0);

  digitalWrite(ledPin, LOW);

  Serial.println("Gate is CLOSED");
}

// =====================
// ACCESS DENIED
// =====================
void denyAccess() {

  digitalWrite(ledPin, LOW);

  gateServo.write(0);

  // Warning beep pattern
  for (int i = 0; i < 3; i++) {

    digitalWrite(buzzerPin, HIGH);

    delay(150);

    digitalWrite(buzzerPin, LOW);

    delay(150);
  }
}
