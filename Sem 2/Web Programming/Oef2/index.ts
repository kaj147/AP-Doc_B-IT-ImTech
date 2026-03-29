interface iDier {
    naam: string,
    woonplaats?: "Antarctica" | "Jungle" | "MIJNHOF",
    leeftijd: number
}

const pinguin : iDier[] = [
    {
    naam: "Joske",
    woonplaats: "Antarctica",
    leeftijd: 38
}];

console.log(pinguin);