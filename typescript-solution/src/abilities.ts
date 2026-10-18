import { Ability } from './ability';
import type { Character } from './character';

// Fiecare abilitate moștenește Ability și suprascrie (override) un singur comportament.

export class PowerStrike extends Ability {
    readonly name = 'Power Strike' as const;

    override onAttack(attacker: Character, damage: number): number {
        return damage * 1.5;
    }
}

export class DamageReduction extends Ability {
    readonly name = 'Damage Reduction' as const;

    override onDefend(defender: Character, damage: number): number {
        return damage * 0.5;
    }
}

export class SecondWind extends Ability {
    readonly name = 'Second Wind' as const;

    override afterHit(defender: Character): void {
        if (defender.health < 30 && defender.isAlive()) {
            defender.heal(5);
        }
    }
}

export class Vampirism extends Ability {
    readonly name = 'Vampirism' as const;

    override onAttack(attacker: Character, damage: number): number {
        attacker.heal(2);
        return damage;
    }
}
