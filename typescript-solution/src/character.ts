import { Ability } from './ability';
import { PowerStrike, DamageReduction, SecondWind, Vampirism } from './abilities';

// Încapsulare: datele sunt private și se citesc doar prin getteri.
// Viața se modifică numai prin takeDamage() și heal(), care țin valorile corecte.
export class Character {
    private _health = 100;
    private _attack = 0;
    private _defense = 0;
    private _ability: Ability;

    constructor(private readonly _name: string) {
        this._ability = Character.randomAbility();
        this.reset();
    }

    get name(): string { return this._name; }
    get health(): number { return this._health; }
    get attack(): number { return this._attack; }
    get defense(): number { return this._defense; }
    get ability(): Ability { return this._ability; }

    reset(): void {
        this._health = 100;
        this._attack = Character.randomInt(15, 20);
        this._defense = Character.randomInt(10, 15);
    }

    assignRandomAbility(): void {
        this._ability = Character.randomAbility();
    }

    takeDamage(amount: number): void {
        this._health = Math.max(0, this._health - Math.max(0, amount));
    }

    heal(amount: number): void {
        if (this.isAlive()) {
            this._health += amount;
        }
    }

    isAlive(): boolean {
        return this._health > 0;
    }

    private static randomAbility(): Ability {
        const abilities: Ability[] = [new PowerStrike(), new DamageReduction(), new SecondWind(), new Vampirism()];
        return abilities[Math.floor(Math.random() * abilities.length)];
    }

    private static randomInt(min: number, max: number): number {
        return Math.floor(Math.random() * (max - min + 1)) + min;
    }
}
