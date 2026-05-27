import { RowDataPacket } from "mysql2/promise";

export interface iAnimals extends RowDataPacket {
    id: number,
    name: string,
    species: string,
    gender: string,
    age: number
}