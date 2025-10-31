-- Deel 5 - Oefenbundel 4
-- Toon alle info van de consoles die NIET eindeproductie zijn
SELECT 
	*
FROM 
	`tblconsoles`
WHERE
	`eindeproduktie` IS NULL;
    
-- Toon alle info van de consoles die WEL eindeproductie zijn
SELECT 
	*
FROM 
	`tblconsoles`
WHERE
	`eindeproduktie` IS NOT NULL;