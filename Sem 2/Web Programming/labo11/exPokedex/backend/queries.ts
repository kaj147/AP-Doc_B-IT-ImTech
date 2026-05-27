import { RowDataPacket } from "mysql2";
import { connect } from "./database"

interface iPokemonId extends RowDataPacket { 
    id: number,

}

async function SelectAllPokemon()
{
    const conn = await connect();

    const query = "SELECCT * FROM caught_pokemon;";
    const [result] = await conn.execute<iPokemonId[]>(query); 
    return result;
}

function CatchPokemon(id : number)
{

}

function ReleasePokemon(id : number)
{

}

export { SelectAllPokemon, CatchPokemon, ReleasePokemon}