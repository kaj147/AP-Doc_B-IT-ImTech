import type { iReis, iKost } from "./types.js";

const database : iReis[] = [];

let idCounter = -1;

function selectAll() : iReis[]{
    return database;
}

function insertReis(bestemming : string, jaar: number) {
    const reis : iReis = {
        id: idCounter++,
        bestemming,
        jaar,
        kosten: []
    }

    database.push(reis);
    return true;
}

function selectReis(id : number) {
    return database.find(r => r.id === id);
}

function insertKost(reisId : number,uitgave : string, prijs: number) {
    const reis = selectReis(reisId);

    if(!reis)
        return false;

    const kost : iKost = {
        uitgave,
        prijs,
    }

    reis.kosten.push(kost);
}

function selectKosten(reisId: number) {
    return selectReis(reisId)?.kosten
}

export {
    selectAll,
    insertReis,
    selectKosten,
    insertKost,
    selectReis
}