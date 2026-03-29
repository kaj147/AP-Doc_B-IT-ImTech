console.log(sum(5, 6));

function sum(a : number, b : number) : number {
    return a + b;
}

const pinguin = function (voornaam : string, achternaam : string) {
    console.log(`Hallo ${voornaam} ${achternaam}!`);
}

const pinguin2 = (voornaam : string, achternaam : string) => console.log(`Hallo ${voornaam} ${achternaam}!`);

pinguin("tering", "leyer")
pinguin2("tering2", "leyer2")

const mijnArray = [1, 2, 3, 4, 5, 6];
mijnArray[2] = 7;

const array2 = [7, 8, 9];

const finalArray = [...mijnArray, ...array2];
console.log(finalArray);
console.log(finalArray.shift());

const doubleArray = mijnArray.map((a) => a*2);

console.log(doubleArray);


const odd = mijnArray.filter(a => a % 2 === 1);

const result = mijnArray
    .filter(a => a < 5)
    .map(a => a/2);

console.log(odd);
console.log(result);


mijnArray.sort((a, b) => {
    if( a < b) {
        return 1;
    }
    if (a > b) {
        return -1;
    }
    return 0;
});

console.log(mijnArray);

const som = mijnArray
    .map(a=> a * 2)
    .sort((a, b) => {
        if(a < b) { return 1; }
        if (a > b) { return -1; }
        return 0;
    });

console.log(som);


const calcSom = mijnArray.reduce(
    (prev, curr) => prev + curr
);

console.log(`calcSom = ${calcSom}`);