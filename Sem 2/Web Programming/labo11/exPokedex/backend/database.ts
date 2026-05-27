import mysql, { type ConnectionOptions, Connection } from "mysql2/promise";

// U can memorize this file because its always the same (except for options)

const options: ConnectionOptions = {
  host: "localhost",
  port: 3000,
  user: "root",
  password: "DitIsGoed",
  database: "PokemonDB",
};

let connection: Connection | undefined = undefined;
let shutdownHookConnected = false; // to avoid making shutdown happen many times, (just once with bool)

// HANDLE DATABASE CONNECTION
async function connect() {
  if (connection) return connection; // if connection isn't undefined

  try {
    connection = await mysql.createConnection(options); // use predefined options to createConnection

    if (shutdownHookConnected === false) {
      process.once("SIGINT", async () => {
        //idk random shit
        await disconnect();
        process.exit();
      });
      shutdownHookConnected = true;
    }

    return connection;
  } catch (error) {
    throw error;
  }
}

// HANDLE DATABASE DISCONNECTION
async function disconnect() {
  if (!connection) return; // if no connection

  try {
    // disconnect
    await connection.end();
    connection = undefined;
  } catch (error) {
    throw error;
  }
}

export { connect, disconnect };
