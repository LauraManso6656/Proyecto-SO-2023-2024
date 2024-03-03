DROP DATABASE IF EXISTS juego;
CREATE DATABASE juego;
USE juego;

CREATE TABLE jugadores(
id INT PRIMARY KEY NOT NULL,
usuario VARCHAR(20) NOT NULL,
pass VARCHAR(20) NOT NULL,
) ENGINE InnoDB;

CREATE TABLE partidas(
idP INT PRIMARY KEY NOT NULL,
duracion FLOAT NOT NULL,
ganador VARCHAR(20) NOT NULL,
) ENGINE InnoDB;

CREATE TABLE participaciones(
idJ INT NOT NULL,
id_P INT NOT NULL,
puntos INT NOT NULL,
FOREIGN KEY (idJ) REFERENCES jugadores (id),
FOREIGN KEY (id_P) REFERENCES jugadores (idP),
) ENGINE InnoDB;

INSERT INTO jugadores VALUES (1, 'user1', 1234);

INSERT INTO jugadores VALUES (2, 'user2', 1111);

INSERT INTO jugadores VALUES (3, 'user3', 2222);

INSERT INTO partidas VALUES (1,20, 'user1');
INSERT INTO partidas VALUES (2,16, 'user2');

INSERT INTO participaciones VALUES (1,1,15);



