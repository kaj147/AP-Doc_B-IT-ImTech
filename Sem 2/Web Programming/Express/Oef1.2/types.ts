export interface iReis {
    id: number;
    bestemming: string;
    jaar: number;
    kosten: iKost[];
}
export interface iKost {
    uitgave: string;
    prijs: number;
}
