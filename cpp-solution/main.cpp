#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "character.hpp"

using namespace std;

int runDuel(Character& c1, Character& c2, bool verbose, bool fixedAbility) {
    c1.reset();
    c2.reset();

    int round = 1;
    Character* attacker = (rand() % 2 == 0) ? &c1 : &c2;
    Character* defender = (attacker == &c1) ? &c2 : &c1;

    while (c1.isAlive() && c2.isAlive()) {
        if (!fixedAbility) {
            c1.assignRandomAbility();
            c2.assignRandomAbility();
        }

        float damage = (float)attacker->getAttack();
        bool abilityActive = (rand() % 100 < 25);

        // Polimorfism: aceleași apeluri, comportament diferit după abilitatea reală
        if (abilityActive) {
            damage = attacker->getAbility().onAttack(*attacker, damage);
            damage = defender->getAbility().onDefend(*defender, damage);
        }

        defender->takeDamage(damage - (float)defender->getDefense());

        if (abilityActive) {
            defender->getAbility().afterHit(*defender);
        }

        if (verbose) {
            cout << "Round " << round << ": " << attacker->getName() << " attacks. "
                 << defender->getName() << " HP: " << fixed << setprecision(1) << defender->getHealth() << endl;
        }

        Character* temp = attacker;
        attacker = defender;
        defender = temp;
        round++;
    }

    return c1.isAlive() ? 1 : 2;
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
    cout << p1.getName() << ": " << p1.getAbility().getName() << " | "
         << p2.getName() << ": " << p2.getAbility().getName() << "\n";
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
