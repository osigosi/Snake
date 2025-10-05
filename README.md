# Snake


Detta är ett Snake-spel skrivet i C för ett rutnätsbaserat grafiskt gränssnitt, anpassat för DE10-Lite FPGA och dess VGA-buffer. Projektet hanterar även interrupts för spelkontroll och logik.

## Projektstruktur

- **main.c**: Startpunkt för programmet.
- **game.c/h**: Spel-logik, hantering av poäng, äpple, kollisioner och game over.
- **snake.c/h**: Funktioner och datastrukturer för ormen (rörelse, tillväxt, riktning).
- **graphics.c/h**: Funktioner för att rita rutnät, ormen och äpplet på skärmen.
- **config.h**: Konfigurationskonstanter (t.ex. rutnätsstorlek, skärmstorlek).


## Hårdvarukrav

- DE10-Lite FPGA-utvecklingskort
- VGA-skärm ansluten till DE10-Lite


## Interrupt-hantering

Spelet använder interrupts för att hantera t.ex. användarinput och speluppdateringar. Detta möjliggör responsiv styrning och korrekt spelhastighet på DE10-Lite.

Du kan kompilera projektet med GCC:

```bash
gcc main.c game.c snake.c graphics.c -o snake
```

## Köra spelet

Kör det kompilerade programmet:

```bash
./snake
```


## Beroenden

- Standard C-kompilator (t.ex. GCC)
- Ingen extern grafikmotor krävs. Koden är anpassad för DE10-Lite och använder direktminnesåtkomst till VGA-buffer (se `graphics.c`).


## Tekniska detaljer

- Interrupts används för att hantera spelhändelser och input.
- VGA-buffer används för grafik.

- Styr ormen för att äta äpplen och växa.
- Undvik att krocka med väggar eller dig själv.

## Kontakt

För frågor, kontakta projektägaren.