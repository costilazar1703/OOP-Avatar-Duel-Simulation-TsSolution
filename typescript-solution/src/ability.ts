import type { Character } from './character';
import { AbilityName } from './types';

// Clasa de bază abstractă pentru abilități. Nu poate fi instanțiată direct;
// fiecare abilitate concretă suprascrie doar metodele care o privesc.
// Motorul de joc lucrează doar cu Ability, deci o abilitate nouă nu schimbă motorul.
export abstract class Ability {
    abstract readonly name: AbilityName;

    // modifică lovitura dată de atacator
    onAttack(attacker: Character, damage: number): number {
        return damage;
    }

    // modifică lovitura primită de apărător
    onDefend(defender: Character, damage: number): number {
        return damage;
    }

    // efect după ce apărătorul a fost lovit
    afterHit(defender: Character): void {}
}
