class Dier {
    naam: string = "";
    woonplaats: string = "";
    private leeftijd: number = 0;

    constructor(naam: string, leeftijd: number) {
        this.naam = naam;
        this.Leeftijd = leeftijd;
    }

    get Leeftijd() {
        return this.leeftijd;
    }

    set Leeftijd(newValue: number) {
        if (newValue < 0)
            throw new Error ("Leeftijd kan niet kleiner dan 0");
        this.leeftijd = newValue;
    }
}

class Vogel extends Dier {
    private aantalPluimen: number = 0;
}



const pinguin = new Dier("Joske", 30);

console.log(pinguin.Leeftijd)