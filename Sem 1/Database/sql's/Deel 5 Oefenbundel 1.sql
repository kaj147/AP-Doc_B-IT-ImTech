-- Deel 5 - Oefenbundel 1
-- Toon alle info van de consoles waarvan de fabrikant Sony is.
USE `gamemania2`;

SELECT 
	*
FROM 
	`tblconsoles`
WHERE
		`fabrikant` = 'Sony';
        
-- Toon alle info van de consoles waarvan de fabrikant NIET Sony is.
SELECT 
	*
FROM 
	`tblconsoles`
WHERE
		`fabrikant` <> 'Sony';
        
-- Toon alle info van de consoles waarvan de prijs minstens €300 bedraaft.
SELECT 
	*
FROM 
	`tblconsoles`
WHERE
		`prijs` >= 300;
        
-- Toon alle info van de consoles van Sony die zijn uitgebracht vanaf 2012.
SELECT 
	*
FROM 
	`tblconsoles`
WHERE
	`fabrikant` = 'Sony' 
    AND
	YEAR(`releasedatum`) >= '2012';