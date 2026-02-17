#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Kund-ID
#define HARRY 0
#define ANKA 1
#define PETTER 2
#define LANGBEN 3
#define IOT 4

int lastCustomer = -1;

// Viktning (baserat på betalning)
int weights[] = {5, 3, 2, 4, 1};

// Funktion för att slumpa kund med viktning
int weightedRandom() {
  int total = 0;
  for (int i = 0; i < 5; i++) total += weights[i];

  int r = random(total);
  int sum = 0;

  for (int i = 0; i < 5; i++) {
    sum += weights[i];
    if (r < sum) return i;
  }
  return 0;
}

// Enkel scrollfunktion
void scrollText(String msg) {
  for (int i = 0; i < msg.length(); i++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(msg.substring(i, i + 16));
    delay(300);
  }
}

void showText(String msg) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(msg);
  delay(20000); // 20 sek
}

void setup() {
  lcd.init();
  lcd.backlight();
  randomSeed(analogRead(0));
}

void loop() {

  int customer;

  // Slumpa tills vi får en annan än förra
  do {
    customer = weightedRandom();
  } while (customer == lastCustomer);

  lastCustomer = customer;

  // Visa rätt kunds reklam
  switch (customer) {

    case HARRY: {
      int r = random(3);
      if (r == 0) scrollText("Kop bil hos Harry");
      else if (r == 1) showText("En god bilaffar!");
      else showText("Hederlige Harrys Bilar");
      break;
    }

    case ANKA: {
      int r = random(2);
      if (r == 0) scrollText("Kop paj hos Farmor");
      else showText("Skynda innan Morten ater!");
      break;
    }

    case PETTER: {
      int minute = (millis() / 60000) % 60;
      if (minute % 2 == 0)
        scrollText("Lat Petter bygga at dig");
      else
        showText("Bygga svart? Ring Petter");
      break;
    }

    case LANGBEN: {
      int r = random(2);
      if (r == 0) showText("Mysterier? Ring Langben");
      else showText("Langben fixar biffen");
      break;
    }

    case IOT: {
      showText("Synas har? IOT Reklam");
      break;
    }
  }
}
