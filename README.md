# OOP Avatar Duel Simulation

A command-line simulation of a turn-based duel between two avatars. It is solved twice, once in C++ and once in TypeScript, to show the same OOP design in two languages.

## How the duel works
- Each avatar has health, attack and defense, plus one random special ability.
- The avatars attack in turns; damage is the attack minus the defender's defense.
- Abilities change the fight: Power Strike, Damage Reduction, Second Wind and Vampirism.
- The duel ends when one avatar reaches 0 health.

## OOP concepts
- **Classes and objects:** a `Character` class with its data and methods (`reset`, ability handling).
- **Polymorphism (TypeScript):** every ability is its own class implementing the `IAbility` interface, so the duel calls `applyEffect` without knowing which ability it is.
- **C++ version:** the abilities are an `enum class`, and their effects are handled in the duel loop.

## Structure
- `cpp-solution/`: `character.hpp`, `character.cpp`, `main.cpp`
- `typescript-solution/`: `src/character.ts`, `src/abilities.ts`, `src/types.ts`, `src/index.ts`

## How to run
- **C++:** in `cpp-solution/`, run `g++ main.cpp character.cpp -o duel`, then `./duel`.
- **TypeScript:** in `typescript-solution/`, run `npm install`, then `npm start`.
