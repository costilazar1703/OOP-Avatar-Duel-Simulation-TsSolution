#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include "character.hpp"

using namespace std;

int runDuel(Character& c1, Character& c2, bool verbose, bool fixedAbility) {
    c1.reset();
    c2.reset();
    
    int round = 1;
    Character* attacker = (rand() % 2 == 0) ? &c1 : &c2;
    Character* defender = (attacker == &c1) ? &c2 : &c1;

    while (c1.health > 0 && c2.health > 0) {
        if (!fixedAbility) {
            c1.ability = static_cast<AbilityType>(rand() % 4);
            c2.ability = static_cast<AbilityType>(rand() % 4);
        }

        float currentAtk = (float)attacker->attackPower;
        bool abilityActive = (rand() % 100 < 25);

        if (abilityActive) {
            if (attacker->ability == AbilityType::POWER_STRIKE) {
                currentAtk *= 1.5f;
            }
            if (defender->ability == AbilityType::DAMAGE_REDUCTION) {
                currentAtk = (currentAtk + (float)defender->defensePower) / 2.0f;
            }
            if (attacker->ability == AbilityType::VAMPIRISM) {
                attacker->health += 2.0f; 
            }
        }

        float damage = currentAtk - (float)defender->defensePower;
        if (damage < 0) damage = 0;
        defender->health -= damage;

        if (abilityActive && defender->ability == AbilityType::SECOND_WIND && defender->health < 30 && defender->health > 0) {
            defender->health += 5.0f;
        }

        if (defender->health < 0) defender->health = 0;
        
        if (verbose) {
            cout << "Round " << round << ": " << attacker->name << " attacks. " 
                 << defender->name << " HP: " << fixed << setprecision(1) << defender->health << endl;
        }

        Character* temp = attacker;
        attacker = defender;
        defender = temp;
        round++;
    }

    return (c1.health > 0) ? 1 : 2;
}

int main(int argc, char* argv[]) {
    srand(time(0));

    bool fixedMode = true;
    if (argc > 1 && string(argv[1]) == "--per-round") {
        fixedMode = false;
    }

    Character p1("Character 1");
    Character p2("Character 2");

    cout << "--- Single Match Output (Mode: " << (fixedMode ? "Fixed" : "Per-Round") << ") ---\n";
    runDuel(p1, p2, true, fixedMode);

    cout << "\n--- Running 1000 simulations... ---\n";
    int p1Wins = 0, p2Wins = 0;
    for (int i = 0; i < 1000; i++) {
        if (runDuel(p1, p2, false, fixedMode) == 1) p1Wins++;
        else p2Wins++;
    }

    cout << "Character 1 win rate: " << (p1Wins / 10.0f) << "%" << endl;
    cout << "Character 2 win rate: " << (p2Wins / 10.0f) << "%" << endl;

    return 0;
}