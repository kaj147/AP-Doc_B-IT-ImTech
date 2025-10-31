-- Toon alle persoonsgegevens van de voorzitters en penningmeesters. Dit omvat alle info die in tabel spelers zit van deze personen, de functie en een 
-- indicatie “Actief” of “Niet actief” afhankelijk van het al dan niet ingevuld zijn van de einddatum

SELECT
	`S`.*
FROM 
	`spelers` AS `S`
    INNER JOIN `bestuursleden` AS `B` ON `B`.`SPELERS` = `S`.`SPELERSNR`