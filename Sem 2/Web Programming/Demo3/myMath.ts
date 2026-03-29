/*export*/ function berekenSom(a : number, b : number) {
    return a + b;
}

/*export*/ function berekenProduct(a : number, b : number) {
    return product(a, b);
}

function product(a : number, b : number) {  //berekenProduct en product zijn volledig onnodig maar dit voor te laten zien dat product niet gebruikt kan worden in index.ts maar wel de andere
    return a * b;
}

/*export*/ const myPi = 3.14;

export { berekenSom, berekenProduct, myPi as pie}