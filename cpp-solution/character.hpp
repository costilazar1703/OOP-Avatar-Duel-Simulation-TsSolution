#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <memory>
#include <string>
#include "ability.hpp"

// Încapsulare: toate datele sunt private; din afară se citesc prin getteri
// și se schimbă doar prin metode care păstrează valorile valide.
class Character {
private:
    std::string name;
    float health;
    int attackPower;
    int defensePower;
    std::unique_ptr<Ability> ability;   // abilitatea e deținută de personaj și eliberată automat

    static std::unique_ptr<Ability> randomAbility();

public:
    explicit Character(const std::string& n);

    void reset();
    void assignRandomAbility();
    void takeDamage(float amount);
    void heal(float amount);
    bool isAlive() const;

    const std::string& getName() const;
    float getHealth() const;
    int getAttack() const;
    int getDefense() const;
    const Ability& getAbility() const;
};

#endif
