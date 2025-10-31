-- Deel 5 - Oefenbundel 2 
-- Toon alle info van alle consoles van de fabrikanten Sony en Nintendo
SELECT 
	*
FROM 
	`tblconsoles`
WHERE
	`fabrikant` = 'Sony'
    OR
    `fabrikant` = 'Nintendo';
    
-- Toon alle info van alle consoles van de fabrikanten Sony en Nintendo
SELECT 
	*
FROM 
	`tblconsoles`
WHERE
	`fabrikant` IN ('Sony', 'Nintendo', 'Sega');