export type AbilityName = 'Damage Reduction' | 'Power Strike' | 'Second Wind' | 'Vampirism';

export interface DuelResult {
    winner: string;
    rounds: number;
}

// Interfata pentru abilitati - permite adaugarea de noi puteri fara a modifica motorul de joc
export interface IAbility {
    name: AbilityName;
    applyEffect(attacker: any, defender: any, damage: number): number;
    applyPostDamageEffect?(character: any): void;
}