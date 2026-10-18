#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <string>

class Character;

// Clasă de bază abstractă: are o metodă pur virtuală (= 0), deci nu poate fi instanțiată.
// Motorul de joc folosește doar Ability&, iar apelul ajunge la abilitatea reală (polimorfism).
class Ability {
public:
    virtual ~Ability() = default;   // destructor virtual: obiectul derivat se distruge corect prin pointer la bază

    virtual std::string getName() const = 0;

    // implicit nu schimbă nimic; abilitățile suprascriu doar ce le privește
    virtual float onAttack(Character& attacker, float damage) const;
    virtual float onDefend(const Character& defender, float damage) const;
    virtual void afterHit(Character& defender) const;
};

// Moștenire: fiecare abilitate derivă din Ability
class PowerStrike : public Ability {
public:
    std::string getName() const override;
    float onAttack(Character& attacker, float damage) const override;
};

class DamageReduction : public Ability {
public:
    std::string getName() const override;
    float onDefend(const Character& defender, float damage) const override;
};

class SecondWind : public Ability {
public:
    std::string getName() const override;
    void afterHit(Character& defender) const override;
};

class Vampirism : public Ability {
public:
    std::string getName() const override;
    float onAttack(Character& attacker, float damage) const override;
};

#endif
