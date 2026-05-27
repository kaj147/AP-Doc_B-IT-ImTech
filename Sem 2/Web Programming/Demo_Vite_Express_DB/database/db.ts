import { Connection, type ConnectionOptions } from "mysql2/promise"
import mysql from "mysql2/promise";

const options : ConnectionOptions = {
    host: "localhost",
    port: 3306,
    user: "root",
    password: "DitIsGoed",
    database: "animaldb",
}

let connection : Connection;

export async function connect() : Promise<Connection> {
    try {
        connection = await mysql.createConnection(options);
        return connection
    }
    catch (error) {
        throw error;
    }

}