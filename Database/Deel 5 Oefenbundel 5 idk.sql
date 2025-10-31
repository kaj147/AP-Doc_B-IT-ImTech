USE tennis;
-- Deel 5 - Oefenbundel 3 
-- Toon de betalingsnummer van elke boete die tussen € 50 en € 100 ligt.
SELECT
	`BETALINGSNR`, `BEDRAG`
FROM
	`boetes`
WHERE
	`BEDRAG`
	BETWEEN
		50 AND 100;

-- Toon de betalingsnummer van elke boete die niet tussen € 50 en € 100 ligt.
SELECT
	`BETALINGSNR`, `BEDRAG`
FROM
	`boetes`
WHERE
	`BEDRAG`
	NOT BETWEEN
		50 AND 100;
        
-- Toon alle informatie van de wedstrijden vanaf wedstrijdnummer 5 tot en met 10 die niet door spelers met spelersnummer 8 en 27 werden gespeeld.
