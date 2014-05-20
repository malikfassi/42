CREATE TABLE ft_table(
id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
login VARCHAR(8) NOT NULL COLLATE utf8_unicode_ci DEFAULT 'toto',
groupe ENUM('staff', 'student', 'other'),
date_de_creation DATE NOT NULL);
