// ouder manier
//
// function longRunner() :Promise<boolean> {
//     console.log("3")
//     return new Promise(
//         resolve => (
//             setTimeout (
//                 () => {
//                     console.log("2");
//                     resolve(true);
//                 }
//             ))
//     );
// }

// async function callLongRunner() {
//     console.log("4");
//     await longRunner();
//     console.log("5");
// }

// callLongRunner();
// console.log("1");

interface iPokemon {
    name: string,
    id: number,
    weight: number,
    sprites: {
        front_default: string,
    }
}

async function fetchPokemon() {
    const pokemon = [
        "ditto",
        "charmander",
        "bulbasaur",
        "piplup",
        "snorlax"
    ];

    const promises = pokemon.map(pkm => fetch(`https://pokeapi.co/api/v2/pokemon/${pkm}`));
    const responses = await Promise.all(promises);

    const jsonPromises = responses.map(r => r.json());
    const data : iPokemon[] = await Promise.all(jsonPromises);
    
    console.log(data[0]);
}

fetchPokemon();
console.log("ondertussen");