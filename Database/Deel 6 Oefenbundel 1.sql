-- Toon de betalingsnummer, het boetebedrag en de naam van de speler voor alle boetes

SELECT
	`BETALINGSNR`,
    `BEDRAG`,
    `NAAM`
FROM
	`boetes` AS `B`,
    `spelers` AS `S`
WHERE
	`B`.`SPELERSNR` = `S`.`SPELERSNR`;
    
-- Toon de spelersnummer, de spelersnaam en alle informatie van de wedstrijden voor de spelers die wedstrijden hebben gespeeld
SELECT
	`S`.`SPELERSNR`,
    `NAAM`,
    `WEDSTRIJDNR`,
    `TEAMNR`,
    `W`.`SPELERSNR`,
    `GEWONNEN`,
    `VERLOREN`
FROM
	`spelers` AS `S`,
    `wedstrijden` AS `W`
WHERE
	`S`.`SPELERSNR` = `W`.`SPELERSNR`;
    
-- Toon de betalingsnummer, het boetebedrag, de naam en de woonplaats van de speler voor spelers die in Den Haag wonen.

SELECT
	`BETALINGSNR`,
    `BEDRAG`,
    `NAAM`,
    `PLAATS`,
	`S`.`SPELERSNR`
FROM
	`boetes` AS `B`,
    `spelers` AS `S`
WHERE
	`S`.`SPELERSNR` = `B`.`SPELERSNR`
    AND
    `PLAATS` = "Den Haag";
    
-- 	Toon de wedstrijdnummer, de naam van de speler die de wedstrijd heeft gespeeld, de divisie van het team waarvoor de wedstrijd werd gespeeld en een indicatie
-- “Gewonnen” of “Verloren” in functie van het resultaat van de wedstrijd. Je toont deze info enkel voor de wedstrijden waarvan de wedstrijdnummer kleiner dan of 
-- gelijk aan 10 is

SELECT 
    `WEDSTRIJDNR`,
    `NAAM`,
    `DIVISIE`,
    CASE WHEN `GEWONNEN` > `VERLOREN` THEN 'Gewonnen'
        ELSE 'Verloren'
    END AS `Resultaat`
FROM
    `spelers` AS `S`,
    `wedstrijden` AS `W`,
    `teams` AS `T`
WHERE
    `W`.`SPELERSNR` = `S`.`SPELERSNR`
	AND `T`.`TEAMNR` = `W`.`TEAMNR`
	AND `WEDSTRIJDNR` <= 10;