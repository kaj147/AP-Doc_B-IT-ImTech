-- vraag 1

CREATE DATABASE IF NOT EXISTS `vogels`;

-- vraag 2

CREATE TABLE IF NOT EXISTS `tblWaarnemingen`
(
	ID INT UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,
    Landcode VARCHAR(2) NOT NULL,
    Locatie VARCHAR(150) NOT NULL,
    Waarnemingsdatum datetime NOT NULL,
    Aantal MEDIUMINT DEFAULT 0,
    VogelSoortID INT UNSIGNED NOT NULL,
    UNIQUE(Locatie, Landcode, Waarnemingsdatum),
	FOREIGN KEY (`VogelSoortID`)
    REFERENCES `tblVogelsoorten`(`ID`)
);

CREATE TABLE IF NOT EXISTS `tblVogelsoorten`
(
	ID SMALLINT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    SoortNaam VARCHAR(120) NOT NULL UNIQUE,
    IsBeschermd TINYINT UNSIGNED,
    GemiddeldeSpanwijdte SMALLINT UNSIGNED NOT NULL
);

-- vraag 3

INSERT INTO `tblVogelsoorten` (`SoortNaam`, `IsBeschermd`, `GemiddeldeSpanwijdte`) VALUES ("Reuzenreiger", 0, 230);

-- vraag 4

SELECT 
	* 
FROM 
	`spelers`
WHERE
	`PLAATS` = "Den Haag" AND
    `BONDSNR` IS NULL;
    
-- vraag 5

-- tekst toevoegen bij gewonnen en verloren + variablen

SELECT
	`WEDSTRIJDNR`,
    CASE
		WHEN `GEWONNEN` = 3 THEN 'Gewonnen '
			ELSE 'Verloren'
	END AS `Resultaat`
FROM 
	`wedstrijden`;

-- vraag 6

SELECT DISTINCT 
	gd.`naam` as 'Game',
	c.`naam` as 'Console',
    DATE(gd.`releasedatum`) as 'Releasedatum game'
FROM 
	`tblgamedefinitions` gd,
	`tbluitgevers` u,
    `tblconsoles` c,
    `tblgames` g
 
 WHERE   
	gd.`uitgever` = 2 AND
    (2000 <= YEAR(gd.`releasedatum`) AND
    YEAR(gd.`releasedatum`) < 2011) AND
    (c.`fabrikant` = "Nintendo" OR 
    c.`fabrikant` = "Sega")
ORDER BY 
	`Game` ASC;
    
-- vraag 7

SELECT
	s.`NAAM`,
    ( 
		SELECT COUNT(*) as cb FROM `boetes` b 
        WHERE b.`SPELERSNR` = s.`SPELERSNR`
    ) as `Aantal boetes`
FROM
	`spelers` s

ORDER BY
		`Aantal boetes` DESC;