const int trigPin1 = 7;  // Birinci Ultrasonik sensörün tetik pini
const int echoPin1 = 6;  // Birinci Ultrasonik sensörün echo pini

const int trigPin2 = 5;  // İkinci Ultrasonik sensörün tetik pini
const int echoPin2 = 4;  // İkinci Ultrasonik sensörün echo pini

long oncekiUzaklik1 = 0;  // Birinci sensörün bir önceki uzaklık değeri
long oncekiUzaklik2 = 0;  // İkinci sensörün bir önceki uzaklık değeri

const int MESAFE_FARKI_LIMITI = 3;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

long mesafeOlc(int trigPin, int echoPin, long &oncekiUzaklik) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long sure = pulseIn(echoPin, HIGH);
  long uzaklik = sure / 58.2;

  return uzaklik;
}

void loop() {
  long simdikiUzaklik1 = mesafeOlc(trigPin1, echoPin1, oncekiUzaklik1);
  long simdikiUzaklik2 = mesafeOlc(trigPin2, echoPin2, oncekiUzaklik2);

  // Birinci sensörün bilgilerini yazdır
  if (abs(simdikiUzaklik1 - oncekiUzaklik1) > MESAFE_FARKI_LIMITI) {
    if (simdikiUzaklik1 > oncekiUzaklik1) {
      Serial.println("11");
    } else if (simdikiUzaklik1 < oncekiUzaklik1) {
      Serial.println("10");
    }
  }

  // İkinci sensörün bilgilerini yazdır
  if (abs(simdikiUzaklik2 - oncekiUzaklik2) > MESAFE_FARKI_LIMITI) {
    if (simdikiUzaklik2 > oncekiUzaklik2) {
      Serial.println("21");
    } else if (simdikiUzaklik2 < oncekiUzaklik2) {
      Serial.println("20");
    }
  }

  oncekiUzaklik1 = simdikiUzaklik1;
  oncekiUzaklik2 = simdikiUzaklik2;

  delay(100);  // 0.1 saniye bekleyin
}
