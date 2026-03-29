console.log("Hello world");

import * as readline from 'readline-sync'

let name: string = readline.question("Give me your name: ");

console.log(`Hello ${name}`);