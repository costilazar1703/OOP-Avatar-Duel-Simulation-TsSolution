import { Character } from './character';
import { DuelResult } from './types';

function runDuel(c1: Character, c2: Character, verbose: boolean = false, fixedAbility: boolean = true): DuelResult {
    c1.reset();
    c2.reset();

    let attacker = Math.random() < 0.5 ? c1 : c2;
    let defender = attacker === c1 ? c2 : c1;
    let round = 1;

    while (c1.isAlive() && c2.isAlive()) {
        if (!fixedAbility) {
            c1.assignRandomAbility();
            c2.assignRandomAbility();
        }

        let damage = attacker.attack;
        const abilityActive = Math.random() < 0.25;

        // Polimorfism: motorul apelează metodele din Ability, iar fiecare abilitate răspunde în felul ei
        if (abilityActive) {
            damage = attacker.ability.onAttack(attacker, damage);
            damage = defender.ability.onDefend(defender, damage);
        }

        defender.takeDamage(damage - defender.defense);

        if (abilityActive) {
            defender.ability.afterHit(defender);
        }

        if (verbose) {
            console.log(`Round ${round}: ${attacker.name} attacks. ${defender.name} HP: ${defender.health.toFixed(1)}`);
        }

        [attacker, defender] = [defender, attacker];
        round++;
    }

    return { winner: c1.isAlive() ? c1.name : c2.name, rounds: round - 1 };
}

const isPerRound = process.argv.includes('--per-round');
const p1 = new Character("Character 1");
const p2 = new Character("Character 2");

console.log(`--- Single Match Output (Mode: ${isPerRound ? "Per-Round" : "Fixed"}) ---`);
console.log(`${p1.name}: ${p1.ability.name} | ${p2.name}: ${p2.ability.name}`);
const result = runDuel(p1, p2, true, !isPerRound);
console.log(`\nWINNER: ${result.winner} after ${result.rounds} rounds\n`);

console.log("--- Running 1000 simulations... ---");
let p1Wins = 0;
for (let i = 0; i < 1000; i++) {
    if (runDuel(p1, p2, false, !isPerRound).winner === p1.name) {
        p1Wins++;
    }
}

console.log(`Character 1 win rate: ${(p1Wins / 10).toFixed(1)}%`);
console.log(`Character 2 win rate: ${((1000 - p1Wins) / 10).toFixed(1)}%`);
