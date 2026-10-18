#include "ability.hpp"
#include "character.hpp"

float Ability::onAttack(Character&, float damage) const { return damage; }
float Ability::onDefend(const Character&, float damage) const { return damage; }
void Ability::afterHit(Character&) const {}

std::string PowerStrike::getName() const { return "Power Strike"; }
float PowerStrike::onAttack(Character&, float damage) const {
    return damage * 1.5f;
}

std::string DamageReduction::getName() const { return "Damage Reduction"; }
float DamageReduction::onDefend(const Character& defender, float damage) const {
    return (damage + (float)defender.getDefense()) / 2.0f;
}

std::string SecondWind::getName() const { return "Second Wind"; }
void SecondWind::afterHit(Character& defender) const {
    if (defender.getHealth() < 30 && defender.isAlive()) {
        defender.heal(5.0f);
    }
}

std::string Vampirism::getName() const { return "Vampirism"; }
float Vampirism::onAttack(Character& attacker, float damage) const {
    attacker.heal(2.0f);
    return damage;
}
