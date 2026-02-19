📘 README – Reklamtavla i AVR‑C
Detta projekt implementerar en reklamtavla i ren C för ATmega328P, utan Arduino‑bibliotek.
LCD‑displayen styrs direkt via PORTD med en egen 4‑bitars HD44780‑drivrutin.
Projektet kompileras med avr-gcc via en Makefile och körs i Wokwi genom att ladda upp en .hex‑fil.

GitHub Repo: https://github.com/AlawiFeyli/reklamtavla-lcd
Wokwi Project: https://wokwi.com/projects/456397236646087681


🔌 Hårdvara (Wokwi‑koppling)
LCD1602 (parallell) kopplas så här:

LCD‑pin	Arduino‑pin
RS	D0
EN	D1
D4	D4
D5	D5
D6	D6
D7	D7
RW	GND
VSS	GND
VDD	5V
VO	GND
LCD‑drivern i lcd.c är skriven för exakt denna koppling.

🛠 Kompilering
I projektmappen:

bash
make clean
make
Detta genererar:

Kod
program.hex
▶️ Kör i Wokwi
Skapa nytt Arduino UNO‑projekt

Lägg till LCD1602 (parallell)

Koppla enligt tabellen ovan

Tryck F1 → Upload HEX

Välj program.hex

🎯 Funktioner
Viktad slumpning av fem kunder

Aldrig samma kund två gånger i rad

Slumpat meddelande inom varje kund

Mjukvaru‑scroll för långa texter

Svarte Petter‑regel:

Jämn minut → scroll

Ojämn minut → statiskt

Varje meddelande visas i 20 sekunder

📂 Filstruktur
Kod
main.c      // Reklamtavlans logik
lcd.c       // LCD-driver (4-bit mode)
lcd.h
Makefile    // Kompilering till ELF + HEX