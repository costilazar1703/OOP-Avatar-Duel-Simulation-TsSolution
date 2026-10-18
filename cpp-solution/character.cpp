#include "character.hpp"
#include <cstdlib>

Character::Character(const std::string& n) : name(n), health(100.0f), attackPower(0), defensePower(0) {
    reset();
    ability = randomAbility();
}

std::unique_ptr<Ability> Character::randomAbility() {
    switch (std::rand() % 4) {
        case 0:  return std::make_unique<DamageReduction>();
        case 1:  return std::make_unique<PowerStrike>();
        case 2:  return std::make_unique<SecondWind>();
        default: return std::make_unique<Vampirism>();
    }
}

void Character::reset() {
    health = 100.0f;
    attackPower = std::rand() % (20 - 15 + 1) + 15;
    defensePower = std::rand() % (15 - 10 + 1) + 10;
}

void Character::assignRandomAbility() {
    ability = randomAbility();
}

void Character::takeDamage(float amount) {
    if (amount < 0) amount = 0;
    health -= amount;
    if (health < 0) health = 0;
}

void Character::heal(float amount) {
    if (isAlive()) health += amount;
}

bool Character::isAlive() const { return health > 0; }

const std::string& Character::getName() const { return name; }
float Character::getHealth() const { return health; }
int Character::getAttack() const { return attackPower; }
int Character::getDefense() const { return defensePower; }
const Ability& Character::getAbility() const { return *ability; }
