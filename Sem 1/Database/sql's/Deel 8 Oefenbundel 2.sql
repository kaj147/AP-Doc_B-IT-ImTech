-- Deel 8 Oefenbundel 2
-- Toon alle info van alle spelers. Sorteer dit resultaat op naam van Z naar A

SELECT 
	*
FROM 
	`SPELERS`
ORDER BY `NAAM` DESC;

-- Toon alle info van alle spelers. Sorteer dit resultaat op jaar van toetreden zodat de spelers die het langst aangesloten zijn eerst getoond worden. In geval spelers in
-- hetzelfde jaar zijn toegetreden wordt gesorteerd op plaats van A naar Z. Als ook de plaats gelijk is sorteer je nog op naam van Z naar A.

SELECT
	*
FROM 
	`SPELERS`
ORDER BY `JAARTOE` ASC, `PLAATS`, `NAAM` DESC;

-- Toon voor alle spelers de naam, voorletters en de spelersnummer. Sorteer dit resultaat op de laatste letter van de naam van Z naar A

SELECT
	*
FROM
	`SPELERS`
ORDER BY RIGHT(NAAM, 1) DESC	-- nog niet juist moet sorteren op laatste letter van de naam en aangezien het voorzetsel als laatste staat kan dit niet