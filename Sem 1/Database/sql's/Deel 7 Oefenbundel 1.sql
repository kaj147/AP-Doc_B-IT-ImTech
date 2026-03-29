-- Schrijf de SQL-instructie die in de volgende informatiebehoefte voorziet. Maak daarbij gebruik van een subquery in de SELECT component.
-- Toon de divisie voor team 1 en team 2 naast elkaar in 2 aparte kolommen. Gebruik Divisie_t1 als kolomhoofding voor de divisie van team 1, Divisie_t2 voor de divisie van
-- team 2.

SELECT
	(SELECT `DIVISIE` FROM `TEAMS` WHERE `TEAMS`.`TEAMNR` = 1) AS 'Divisie_T1',
    (SELECT `DIVISIE` FROM `TEAMS` WHERE `TEAMS`.`TEAMNR` = 2) AS 'Divisie_T2';
    
-- Toon de spelersnummer en het aantal gespeelde wedstrijden voor elke speler. Gebruik Aantal als kolomhoofding voor het aantal gespeelde wedstrijden

SELECT
	S.`SPELERSNR`,
    COUNT(W.`WEDSTRIJDNR`) AS `AANTAL`
FROM
	`Spelers` S
    LEFT JOIN `WEDSTRIJDEN` W ON S.`SPELERSNR` = W.`SPELERSNR`
GROUP BY S.`SPELERSNR`;