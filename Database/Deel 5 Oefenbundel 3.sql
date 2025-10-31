-- Deel 5 - Oefenbundel 3 
-- Toon alle info van alle consoles waarvan de releasedatum ligt tussen 2010 en de datum van opvraging.
SELECT 
	*
FROM 
	`tblconsoles`
WHERE
	YEAR(`releasedatum`) 
		BETWEEN 
			2010 AND YEAR(CURDATE());

-- Toon alle info van de consoles waarvan de naam begint met XBOX
SELECT 
	*
FROM 
	`tblconsoles`
WHERE
	`naam` LIKE 'xbox%';