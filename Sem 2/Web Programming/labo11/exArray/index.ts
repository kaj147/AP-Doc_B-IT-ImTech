interface Pokemon {
  name: string;
  type: string;
  level: number;
  caughtDate: Date | null;
}

const pokemons: Pokemon[] = [
  { name: 'Charmander', type: 'Fire', level: 12, caughtDate: new Date('2024-01-10') },
  { name: 'Squirtle', type: 'Water', level: 10, caughtDate: new Date('2024-02-15') },
  { name: 'Pikachu', type: 'Electric', level: 18, caughtDate: null },
  { name: 'Vulpix', type: 'Fire', level: 15, caughtDate: new Date('2024-03-05') },
  { name: 'Bulbasaur', type: 'Grass', level: 14, caughtDate: new Date('2024-04-01') },
  { name: 'Growlithe', type: 'Fire', level: 22, caughtDate: null },
  { name: 'Pidgey', type: 'Normal', level: 8, caughtDate: new Date('2024-01-10') },
  { name: 'Magmar', type: 'Fire', level: 30, caughtDate: new Date('2024-01-25') },
  { name: 'Jigglypuff', type: 'Fairy', level: 11, caughtDate: null },
  { name: 'Psyduck', type: 'Water', level: 16, caughtDate: new Date('2024-03-20') }
];


// 1. Toon enkel gevangen Pokémon

console.log(pokemons.filter(pokemon => pokemon.caughtDate !== null));

// 2. Toon enkel niet-gevangen Pokémon

console.log(pokemons.filter(pokemon => pokemon.caughtDate === null));

// 3. Lijst van namen van niet-gevangen Pokémon

console.log(pokemons
    .filter(pokemons => pokemons.caughtDate !== null)
    .map(pokemons => pokemons.name)
);

// 4. Aantal gevangen Pokémon

console.log("Aantal gevangen: " + pokemons.filter(pokemon => pokemon.caughtDate !== null).length);

/*
console.log(pokemons
    .filter(pokemons => pokemons.caughtDate !== null)
    .reduce((result, curr) => result++, 0)
);
*/

// 5. Zijn er nog ongevangen Fire-types?

console.log("Aantal fire-types not caught: " + pokemons
    .filter(pokemons => pokemons.caughtDate !== null && pokemons.type === "Fire")
    .map(pokemons => pokemons.name).length
);

// 6. Zijn alle Water-types gevangen?

console.log("All water-types caught: " + pokemons
    .filter(pokemons => pokemons.type === "Water")
    .every(pokemons => pokemons.caughtDate !== null)
);

// 7. Som van levels van alle gevangen Pokémon

console.log("Sum all levels: " + pokemons
    .filter(pokemons => pokemons.caughtDate !== null)
    .reduce((sum, pokemons) => sum += pokemons.level, 0)
);

// 8. Gemiddeld level van niet-gevangen Pokémon

console.log("Avg levels not caught pokemon: " + pokemons
    .filter(pokemons => pokemons.caughtDate === null)
    .reduce((sum, pokemons, _, arr) => sum + (pokemons.level / arr.length), 0)    
);

// 9. Sorteer gevangen Pokémon van oud naar recent (op caughtDate)

const res = pokemons
    .filter(pokemons => pokemons.caughtDate !== null)
    .sort((a, b) => {
            if (a.caughtDate!.getTime() - b.caughtDate!.getTime() > 0)
                return 1;
            if (a.caughtDate!.getTime() - b.caughtDate!.getTime() < 0)
                return -1;
            if (a.level - b.level > 0)
                return 1;
            if (a.level - b.level < 0)
                return -1;
            return 0;
        }
);

console.log("Sorted: ", res);
