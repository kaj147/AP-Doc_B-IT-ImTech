CREATE TABLE IF NOT EXISTS `reizen` (
    `id` INT NOT NULL AUTO_INCREMENT,
    `bestemming` VARCHAR(63) NOT NULL,
    `jaar` DECIMAL(4,0) NOT NULL,
    PRIMARY KEY (`id`)
);


CREATE TABLE IF NOT EXISTS `kosten` (
    `id` INT NOT NULL AUTO_INCREMENT,
    `uitgave` VARCHAR(63) NOT NULL,	
    `prijs` DECIMAL(6,2) NOT NULL,
    PRIMARY KEY (`id`)
);

CREATE TABLE IF NOT EXISTS `reiskosten` (
    `reisid` INT NOT NULL,
    `kostid` INT NOT NULL,
    PRIMARY KEY (`reisid`, `kostid`),
    FOREIGN KEY (`reisid`) REFERENCES `reizen` (`id`),
    FOREIGN KEY (`kostid`) REFERENCES `kosten` (`id`)
);

INSERT INTO `reizen`(bestemming, jaar) values
('China', 2027),
('Italie', 2019),
('Maldives', 2026),
('Finland', 2029);

INSERT INTO `kosten`(uitgave, prijs) values
('vliegtuig', 400),
('hotel', 500),
('restaurant', 60),
('auto', 450);

INSERT INTO `reiskosten`(reisid, kostid) values
(1, 1),
(1, 2),
(1, 3),
(2, 2), 
(3, 1),
(4, 4);