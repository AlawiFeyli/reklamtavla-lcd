Reklamtavla – IOT25 (Programmering för inbyggda system)

Detta projekt är en lösning på inlämningsuppgiften "Reklamtavlan" i kursen *Programmering för inbyggda system* på Stockholms Tekniska Institut.

Projektet simulerar en reklamskylt som visar olika kunders reklammeddelanden på en LCD‑display. Varje kund har betalat olika mycket, vilket påverkar hur ofta deras reklam visas. Systemet slumpmässigt väljer nästa kund, men **samma kund får aldrig visas två gånger i rad**. Varje visning varar i 20 sekunder.

Projektet körs på en Arduino Uno med en LCD 1602 I2C‑display och är helt simulerat i Wokwi.

---

**Funktioner**

- Viktad slumpning baserat på kundens betalning.
- Aldrig samma kund två gånger i rad.
- Scrollande text för vissa meddelanden.
- Statiska textmeddelanden för andra.
- Specialregel för Svarte Petter:
  - Jämna minuter → scroll‑meddelande
  - Ojämna minuter → statiskt meddelande
- Varje visning varar i 20 sekunder.
- LCD 1602 I2C‑display används för att visa reklamen.

---

**Kunder och viktning**

| Kund | Betalat | Vikt |
|------|---------|------|
| Hederlige Harrys Bilar | 5000 kr | 5 |
| Farmor Ankas Pajer AB | 3000 kr | 3 |
| Svarte Petters Svartbyggen | 1500 kr | 2 |
| Långbens Detektivbyrå | 4000 kr | 4 |
| IOT Reklambyrå (vi själva) | 1000 kr | 1 |

Vikterna används för att slumpa fram kunder med olika sannolikhet.

---

**Hur slumpningen fungerar**

Slumpningen görs genom att summera alla vikter och välja ett slumpvärde inom totalen.  
Därefter avgörs vilken kund som motsvarar det slumpvärdet.

Dessutom säkerställs att **den slumpade kunden inte är samma som den förra**.

---

**Hårdvara**

- Arduino Uno
- LCD 1602 I2C (adress 0x27)

Kopplingar:

| LCD | Arduino |
|-----|---------|
| GND | GND |
| VCC | 5V |
| SDA | A4 |
| SCL | A5 |

---

**Wokwi‑projekt**

Här är den färdiga simulerade kretsen i Wokwi:

(https://wokwi.com/projects/456216561675626497)

---

**Kod**

All kod finns i `sketch.ino` i detta repo.

Koden är skriven i C++ och följer kursens krav för G‑nivå:  
tydlig struktur, enkel logik och fungerande implementation av alla regler i uppgiften.

---

**Hur du kör projektet**

1. Öppna Wokwi‑länken ovan.  
2. Tryck på **Play**.  
3. LCD‑displayen börjar visa reklammeddelanden enligt reglerna.

---
