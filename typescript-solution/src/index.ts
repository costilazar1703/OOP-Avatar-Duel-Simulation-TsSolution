import { Character } from './character';
import { PowerStrike, DamageReduction, SecondWind, Vampirism } from './abilities';

function runDuel(c1: Character, c2: Character, verbose: boolean = false, fixedAbility: boolean = true): Character {
    c1.reset();
    c2.reset();
    
    const possibleAbilities = [new PowerStrike(), new DamageReduction(), new SecondWind(), new Vampirism()];

    let attacker = Math.random() < 0.5 ? c1 : c2;
    let defender = attacker === c1 ? c2 : c1;
    let round = 1;

    while (c1.health > 0 && c2.health > 0) {
        if (!fixedAbility) {
            c1.assignRandomAbility();
            c2.assignRandomAbility();
        }

        let damage = attacker.attack;
        const abilityActive = Math.random() < 0.25;

        if (abilityActive) {
            damage = attacker.ability.applyEffect(attacker, defender, damage);
            damage = defender.ability.applyEffect(attacker, defender, damage);
        }

        const netDamage = Math.max(0, damage - defender.defense);
        defender.health -= netDamage;

        if (abilityActive && defender.ability.applyPostDamageEffect) {
            defender.ability.applyPostDamageEffect(defender);
        }

        if (defender.health < 0) defender.health = 0;

        if (verbose) {
            console.log(`Round ${round}: ${attacker.name} attacks. ${defender.name} HP: ${defender.health.toFixed(1)}`);
        }

        [attacker, defender] = [defender, attacker];
        round++;
    }

    return c1.health > 0 ? c1 : c2;
}

const isPerRound = (process as any).argv.includes('--per-round');
const p1 = new Character("Character 1");
const p2 = new Character("Character 2");

console.log(`--- Single Match Output (Mode: ${isPerRound ? "Per-Round" : "Fixed"}) ---`);
const winner = runDuel(p1, p2, true, !isPerRound);
console.log(`\nWINNER: ${winner.name}\n`);

console.log("--- Running 1000 simulations... ---");
let p1Wins = 0;
for (let i = 0; i < 1000; i++) {
    if (runDuel(p1, p2, false, !isPerRound).name === "Character 1") {
        p1Wins++;
    }
}

console.log(`Character 1 win rate: ${(p1Wins / 10).toFixed(1)}%`);
console.log(`Character 2 win rate: ${((1000 - p1Wins) / 10).toFixed(1)}%`);