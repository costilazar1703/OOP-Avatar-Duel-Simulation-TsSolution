import { IAbility } from './types';
import { PowerStrike, DamageReduction, SecondWind, Vampirism } from './abilities';

export class Character {
    public health: number = 100;
    public attack: number = 0;
    public defense: number = 0;
    public ability!: IAbility;

    constructor(public name: string) {
        this.reset();
        this.assignRandomAbility();
    }

    reset() {
        this.health = 100;
        this.attack = Math.floor(Math.random() * (20 - 15 + 1)) + 15;
        this.defense = Math.floor(Math.random() * (15 - 10 + 1)) + 10;
    }

    assignRandomAbility() {
        const abilities = [new PowerStrike(), new DamageReduction(), new SecondWind(), new Vampirism()];
        this.ability = abilities[Math.floor(Math.random() * abilities.length)];
    }
}