import { question } from "readline-sync";
import * as sloth from "sloth-log";

while (true) {
    let input = question('>');
    let amount = Math.floor(Math.random() * 5) + 1;
    await repeatWords("Meow", amount, " ");
}

async function repeatWords(word : string, times : number, seperator : string) {
    let sentence : string = "";

    for(let x : number = 0; x < times; x++){
        sentence += "Meow" + seperator;
    }

    await sloth.logAsync(sentence, { speed: 1000, maxWordsAtOnce: 2});
}