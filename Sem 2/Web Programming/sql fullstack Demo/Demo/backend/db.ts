import { connect } from "./dbConnection.js";
import type { IReis, IKost } from "./types.js";
import { type ResultSetHeader } from "mysql2/promise";

// ALL SQL QUERIES

async function selectAlleReizen(): Promise<IReis[]> {
  try {
    // Because the function is async, they NEED to return promise<Type>, this is not needed. TS does it automatically
    const query = "SELECT * FROM 'reizen';";

    const connection = await connect();

    // [result] = array deconstruction to get first items from an array, it literally means [result] = FIRST item from array IReis[]
    const [result] = await connection.execute<IReis[]>(query);

    return result;
  } catch (e) {
    throw e;
  }
}

async function insertReis(
  bestemming: string,
  jaar: number,
) /* parameters must have :type (jaar: number). */ {
  try {
    const query = "INSERT INTO 'reizen' (bestemming, jaar) VALUES (?, ?);"; // we dont use ${}, but instead we use (?, ?). because in a ${string} we can put sql injection

    const connection = await connect();

    // we also return a <ResultSetHeader> because we are manipulating the database, (INSERT, GET, DELETE, etc)
    const [result] = await connection.execute<ResultSetHeader>(query, [
      bestemming,
      jaar,
    ]); // we fill in the (?, ?) with 'bestemming, jaar'... so ' becomes quote, to avoid sql injection

    return result;
  } catch (e) {
    throw e;
  }
}

async function selectReis(id: number) /* : Promise<IReis[]> */ {
  try {
    // see that the Promise isn't there? typescript does it by itself somehow, but just write it anyway to make sure
    // same as selectAlleReizen(), just different query and parameteres

    const query = "SELECT * FROM 'reizen' WHERE id = ?;";

    const connection = await connect();
    const [result] = await connection.execute<IReis[]>(query, [id]);

    if (result.length == 0) {
      throw new Error("Deze reis bestaat niet.");
    }

    return result;
  } catch (e) {
    throw e;
  }
}

async function insertKost(reisId: number, uitgave: string, prijs: number) {
  try {
    const query = `INSERT INTO 'kosten' (uitgave, prijs), VALUES(?, ?); 
                  INSERT INTO 'reiskosten' (reisId, kostId) VALUES (?, LAST_INSERT_ID())`; // LAST_INSERT_ID() uses last ID? idk im not sure... but it can only happen on 2 sql queries at the same time (not seperate queries, like const query1, query2, etc)

    const connection = await connect();

    const [result] = await connection.execute<ResultSetHeader>(query, [
      uitgave,
      prijs,
      reisId,
    ]);

    return result;
  } catch (e) {
    throw e;
  }
}

async function selectKosten(reisId: number) {
  try {
    const query = `SELECT uitgave, prijs FROM reizen
                  LEFT JOIN reiskosten ON reizen.id = reiskosten.reisid
                  LEFT JOIN kosten ON kosten.id = reiskosten.kostid
                  WHERE reizen.id = ?;`;

    const connection = await connect();
    const [result] = await connection.execute<IReis[]>(query, [reisId]);

    if (result.length == 0) {
      throw new Error("Deze reis bestaat niet.");
    }

    return result;
  } catch (e) {
    throw e;
  }
}

export { selectAlleReizen, insertReis, selectKosten, insertKost, selectReis };
