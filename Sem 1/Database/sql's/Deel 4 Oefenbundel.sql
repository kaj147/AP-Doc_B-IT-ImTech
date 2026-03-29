-- Deel 4 - Oefenbundel 1
-- Toon alle informatie van alle consoles
SELECT 
	*
FROM 
	`tblconsoles`;
    
-- Toon voor alle consoles de naam en de prijs verhoogd met 2%

SELECT 
	`naam`, 
    `prijs` * 1.02 AS `nieuwe prijs`
FROM
	`tblconsoles`;

-- Deel 4 - oefenbundel 2
-- Toon voor elke console de naam en een kolom 'status'
-- Toon in kolom `status` de waarde 'Nieuwste' wanneer de console in het jaar 2020 is uitgebracht
-- Toon in alle andere gevallen de waarde 'Niet Nieuwst'

SELECT 
	`naam`,
    CASE YEAR(`releasedatum`)
		WHEN 2020 THEN 'Nieuwste'
		ELSE 'Niet Nieuwste'
    END AS `status`
FROM
	`tblconsoles`;

-- Herwerk de vorige opgave zodanig dat:
-- Consoles vanaf 2020 moeten de aanduiding 'Nieuwste' krijgen.
-- Consoles na 2010 maar voor 2020 moeten de aanduiding 'Ouder' krijgen.
-- De overige consoles moeten de aanduiding 'Verouderd' krijgen

SELECT 
	`naam`,
    CASE
		WHEN YEAR(`releasedatum`) >= 2020 THEN 'Nieuwste'
        WHEN YEAR(`releasedatum`) > 2010 THEN 'Ouder'
		ELSE 'Verouderd'
    END AS `status`
FROM
	`tblconsoles`;

-- Consoles vanaf 2020 moeten de aanduiding 'Nieuwste' krijgen.
-- Consoles voor 2020 maar na 2012 moeten de aanduiding 'Modern' krijgen.
-- Console na 2010 maar voor 2013 moeten de aanduiding 'Ouder' krijgen.
-- De overige consoles moeten de aanduiding 'Verouderd' krijgen.

SELECT 
	`naam`,
    `releasedatum`,
    
    CASE
		WHEN YEAR(`releasedatum`) >= 2020 THEN 'Nieuwste'
        WHEN YEAR(`releasedatum`) > 2010 THEN
			CASE
				WHEN YEAR(`releasedatum`) > 2012 THEN 'Modern'
				ELSE 'Ouder'
            END
		ELSE 'Verouderd'
    END AS `status`
FROM
	`tblconsoles`;

-- Deel 4 - oefenbundel 3
-- Toon de naam van de console, gevolgd door een spatie en de naam van de fabrikant tussen ronde haken als 1 waarde
-- Gebruik kolomnaam 'console' 
-- Bv. PS5 (Sony)

SELECT
	LCASE(CONCAT(`naam`,' (',`fabrikant`,')')) AS 'Console'
FROM
	`tblconsoles`;

-- Deel 4 - oefenbundel 4
-- Tel het aantal consoles. Gebruik als kolomhoofding 'Aantal'.

SELECT 
    COUNT(*) AS 'Aantal'
FROM
    `tblconsoles`;
    
-- Tel het aantal consoles dat niet meer geproduceerd wordt. Gebruik als kolomhoofding 'Aantal'

SELECT 
    COUNT(`eindeproduktie`) AS 'Aantal'
FROM
    `tblconsoles`;
-- Dit kun je enkel doen als de je de volledig datum toevoegd nu 
-- kan dat zijn dat die pas in het midden van het jaar stopt maar je bent nog maar het begin waar die niet mee telt
-- WHERE	
--    YEAR(`eindeproduktie`) < YEAR(CURDATE());
