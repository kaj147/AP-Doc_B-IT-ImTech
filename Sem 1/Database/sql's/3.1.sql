CREATE DATABASE  IF NOT EXISTS `Learning` DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;
USE `Learning`;

CREATE TABLE IF NOT EXISTS `tblLanguages` 
(
	`id` INT UNSIGNED PRIMARY KEY,
	`name` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL
);

CREATE TABLE IF NOT EXISTS `tblCourseDefinitions`
(
	`id` MEDIUMINT PRIMARY KEY,
    `LanguageID` varchar(255) COLLATE utf8mb3_bin,
    FOREIGN KEY `tblLanguages` REFERENCES  
);