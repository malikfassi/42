DROP DATABASE IF EXISTS game;

CREATE DATABASE game;

CREATE TABLE game.party
(
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `player_1_login` varchar(255) NOT NULL,
  `player_1_obj` text NOT NULL,
  `player_2_login` varchar(255) NOT NULL,
  `player_2_obj` text NOT NULL,
  `player_3_login` varchar(255) NOT NULL,
  `player_3_obj` text NOT NULL,
  `player_4_login` varchar(255) NOT NULL,
  `player_4_obj` text NOT NULL,
  `board` text NOT NULL,
  `asteroid` text NOT NULL,
  `running` tinyint(1) NOT NULL,
  `turn` int(11) NOT NULL,
  `player` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=14 ;

CREATE TABLE game.t_chat
(
  `id` int(11) NOT NULL  AUTO_INCREMENT,
  `login` VARCHAR(255) NOT NULL,
  `date` datetime NOT NULL,
  `text` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

