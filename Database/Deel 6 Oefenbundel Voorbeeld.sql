/*
Toon:
-betalingsnummer
- boetebedrag
- naam van de speler
- woonplaats van de speler
voor de spelers die in Den Haag wonen
*/
-- Impliciete join
SELECT
	`BETALINGSNR`,
    `BEDRAG`,
    `NAAM`,
    `PLAATS`
FROM
	`BOETES` AS `B`,
    `SPELERS` AS `S`
WHERE
	`B`.`SPELERSNR` = `S`.`SPELERSNR` 
    AND
	`PLAATS` = "Den Haag";
    
-- Expliciete join
SELECT
	`BETALINGSNR`,
    `BEDRAG`,
    `NAAM`,
    `PLAATS`
FROM
	`BOETES` AS `B`
    INNER JOIN `SPELERS` AS `S` ON `B`.`SPELERSNR` = `S`.`SPELERSNR`

WHERE
	`PLAATS` = "Den Haag";
    
-- Toon voor alle spelers de naam en woonplaats van de speler en voor elke boete van de spelers het betalingsnummer en boetebedrag
SELECT
	`BETALINGSNR`,
    `PLAATS`,
    `NAAM`,
    `BEDRAG`
FROM
	`SPELERS` AS `S`
    LEFT JOIN `BOETES` AS `B` ON `B`.`SPELERSNR` = `S`.`SPELERSNR`

WHERE
	`PLAATS` = "Den Haag";