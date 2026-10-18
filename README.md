# OOP Avatar Duel Simulation

A command-line simulation of a turn-based duel between two avatars. It is solved twice, in TypeScript and in C++, with the same class design in both.

## How the duel works
- Each avatar has health, attack and defense, plus one random special ability.
- The avatars attack in turns; damage is the attack minus the defender's defense.
- Abilities change the fight: Power Strike, Damage Reduction, Second Wind and Vampirism.
- The duel ends when one avatar reaches 0 health. The program then runs 1000 duels and prints the win rates.

## OOP concepts
- **Encapsulation:** the `Character` data (health, attack, defense, ability) is private. It is read through getters and changed only through `takeDamage()` and `heal()`, which keep the values valid (health never goes below 0).
- **Abstraction:** `Ability` is an abstract base class (pure virtual `getName()` in C++, `abstract` in TypeScript), so it cannot be created on its own.
- **Inheritance:** `PowerStrike`, `DamageReduction`, `SecondWind` and `Vampirism` all inherit from `Ability`, and each overrides only the hook it needs (`onAttack`, `onDefend` or `afterHit`).
- **Polymorphism:** the duel loop only calls methods on `Ability`; the real ability decides what happens. Adding a new ability does not change the duel code. In C++ this goes through virtual functions, with a virtual destructor and `std::unique_ptr` for ownership.

## Structure
- `typescript-solution/src/`: `ability.ts` (base class), `abilities.ts` (the four abilities), `character.ts`, `types.ts`, `index.ts` (duel loop)
- `cpp-solution/`: `ability.hpp` / `ability.cpp`, `character.hpp` / `character.cpp`, `main.cpp`

## How to run
- **TypeScript:** in `typescript-solution/`, run `npm install`, then `npm start` (add `-- --per-round` to change abilities every round).
- **C++:** in `cpp-solution/`, run `g++ -std=c++17 main.cpp character.cpp ability.cpp -o duel`, then `./duel` (or `./duel --per-round`).
