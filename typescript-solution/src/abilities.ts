import { IAbility, AbilityName } from './types';

export class PowerStrike implements IAbility {
    name: AbilityName = 'Power Strike';
    applyEffect(attacker: any, defender: any, damage: number): number {
        return damage * 1.5; 
    }
}

export class DamageReduction implements IAbility {
    name: AbilityName = 'Damage Reduction';
    applyEffect(attacker: any, defender: any, damage: number): number {
        return damage * 0.5; 
    }
}

export class SecondWind implements IAbility {
    name: AbilityName = 'Second Wind';
    applyEffect(attacker: any, defender: any, damage: number): number { return damage; }
    applyPostDamageEffect(character: any): void {
        if (character.health < 30 && character.health > 0) {
            character.health += 5;
        }
    }
}

export class Vampirism implements IAbility {
    name: AbilityName = 'Vampirism';
    applyEffect(attacker: any, defender: any, damage: number): number {
        attacker.health += 2;
        return damage;
    }
}