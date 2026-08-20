#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

enum class AbilityType {
    DAMAGE_REDUCTION,
    POWER_STRIKE,
    SECOND_WIND,
    VAMPIRISM
};

class Character {
public:
    std::string name;
    float health;
    int attackPower;
    int defensePower;
    AbilityType ability;

    Character(std::string n);
    void reset();
    std::string getAbilityName();
};

#endif