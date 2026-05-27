export interface iReis {
    id: string;
    bestemming: string;
    jaar: number;
    kosten: iKost[];
}

export interface iKost {
    uitgave: string;
    prijs: number;
}
