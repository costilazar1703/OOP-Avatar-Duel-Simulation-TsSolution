## Duel Game Simulation - Proiect Recrutare

Salutare! Acest proiect conține rezolvarea pentru problema duelului turn-based, realizată pentru procesul de selecție la stagiul de practică Colete-Online.

## Despre abordare
Am ales să trimit două variante ale soluției: una în **TypeScript** și una în **C++**. 

Fiind student la Automatică, în ultimii ani am lucrat cel mai mult în C++, așa că am început prin a scrie logica acolo pentru a asigura corectitudinea algoritmilor. Totuși, am portat întreaga soluție și în TypeScript, adaptând-o la cerințele tehnice ale echipei voastre. Ambele variante respectă aceeași logică de business, dar profită de avantajele specifice fiecărui limbaj (interfețe și modularitate în TS, structură de headere și performanță în C++).

## Extensii implementate
Pe lângă cerințele de bază, am adăugat următoarele funcționalități:
*   **Simulare extinsă**: Posibilitatea de a rula 1000 de dueluri automate pentru a genera statistici de win rate.
*   **A patra abilitate (Vampirism)**: Atacatorul își recapătă 2 HP dacă atacul are succes și abilitatea este activă.
*   **Configurare CLI**: Suport pentru flag-ul `--per-round` care permite schimbarea abilităților personajelor la fiecare rundă, în loc să rămână fixe.

---

## 1. Soluția TypeScript (Node.js)
Codul este organizat modular în folderul `src/`:
*   *types.ts*: Definește interfețele pentru abilități și structura rezultatelor pentru a asigura un tipaj strict.
*   *abilities.ts*: Conține implementările individuale ale fiecărei abilități (folosind *Strategy Pattern*). Această abordare permite adăugarea de noi abilități fără a modifica motorul principal de luptă.
*   *character.ts*: Gestionează clasa personajului, generarea random a atributelor conform limitelor impuse (15-20 Atac, 10-15 Apărare) și logica de resetare între meciuri.
*   *index.ts*: Punctul central al aplicației. Gestionează desfășurarea rundelor, afișarea detaliată a meciului vizual, execuția celor 1000 de simulări și procesarea argumentelor din linia de comandă.

*Instrucțiuni de rulare:*
```bash
cd typescript-solution
npm install
npm start
npm start -- --per-round
```

## 2. Soluția C++
Implementare modulară realizată conform bunelor practici de programare orientată pe obiect:

*   *character.hpp*: Header-ul care conține definiția clasei Character, constantele pentru limitele de atribute și tipurile de abilități (enum class).

*   *character.cpp*: Implementarea metodelor clasei, ocupându-se de logica de randomizare a atributelor și gestionarea stării personajului.

*   *main.cpp*: Conține logica principală de simulare a duelului, gestionarea atacurilor și bucla statistică pentru cele 1000 de simulări.

*Instrucțiuni de rulare:*
```bash
cd cpp-solution
g++ main.cpp character.cpp -o duel
./duel                          
./duel --per-round