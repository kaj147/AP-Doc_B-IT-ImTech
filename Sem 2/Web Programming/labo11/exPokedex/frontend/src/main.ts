import './style.css'

interface iPokemon {
  name : string,
  url: string,
}

interface iResult {
  results : iPokemon
}

async function GetAllPoke()
{
  const response = await fetch("https://pokeapi.co/api/v2/pokemon?limit=100000&offset=0");
  const pokemon : iResult = await response.json();
  return pokemon.results;
}