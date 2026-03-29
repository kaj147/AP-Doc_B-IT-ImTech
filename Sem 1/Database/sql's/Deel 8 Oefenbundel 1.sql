-- DEEL 8 Oefenbundel 1
-- Toon de verschillende plaatsen in tabel spelers

SELECT 
	DISTINCT `PLAATS`
FROM 
	`SPELERS`;

-- Toon de verschillende boetebedragen die per maand werden betaald.

SELECT
	DISTINCT `BEDRAG`, `DATUM`
FROM
	`BOETES`;
    
-- Toon het aantal verschillende bestuursfuncties.

SELECT
	DISTINCT `FUNCTIE`
FROM 
	`BESTUURSLEDEN`;