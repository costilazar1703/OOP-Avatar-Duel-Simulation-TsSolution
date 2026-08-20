#include "character.hpp"
#include <cstdlib>

Character::Character(std::string n) : name(n) {
    reset();
    ability = static_cast<AbilityType>(std::rand() % 4);
}

void Character::reset() {
    health = 100.0f;
    attackPower = std::rand() % (20 - 15 + 1) + 15;
    defensePower = std::rand() % (15 - 10 + 1) + 10;
}

std::string Character::getAbilityName() {
    switch (ability) {
        case AbilityType::DAMAGE_REDUCTION: return "Damage Reduction";
        case AbilityType::POWER_STRIKE: return "Power Strike";
        case AbilityType::SECOND_WIND: return "Second Wind";
        case AbilityType::VAMPIRISM: return "Vampirism";
        default: return "None";
    }
}