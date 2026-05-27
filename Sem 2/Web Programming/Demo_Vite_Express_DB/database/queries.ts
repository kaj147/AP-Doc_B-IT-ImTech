import { Connection } from "mysql2/promise";
import type { iAnimals } from "../types.js";
import { connect } from "./db.js";

export async function getAnimals(): Promise<iAnimals[]> {
    const conn : Connection = await connect();

    try {
        const [results] = await conn.query<iAnimals[]>("SELECT * FROM animals");
        return results;
    }
    catch (error) {
        throw error;
    }
    finally {
        await conn.end();
    }
}

export async function createAnimal(animal: iAnimals) {
    const conn : Connection = await connect();
    try {
        await conn.query(" INSERT INTO animals(name, species, gender, age) VALUES(?,?,?,?)", [animal.name, animal.species, animal.gender, animal.age]);
        return;
    }
    catch (error) {
        throw error;
    }
    finally {
        await conn.end();
    }
}