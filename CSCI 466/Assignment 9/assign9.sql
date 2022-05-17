--	assign9.sql
--	Isabelle Coletti
--	z1900409
--	CSCI 466-1

-- delete the tables before creating them
DROP TABLE IF EXISTS SP, S, P;	

-- create S table
CREATE TABLE S(
	S CHAR(4) NOT NULL,
	SNAME CHAR(25) NOT NULL,
	STATUS INT NOT NULL,
	CITY CHAR(25) NOT NULL,

	PRIMARY KEY (S)
);

-- create P table
CREATE TABLE P(
	P CHAR(4) NOT NULL,
	PNAME CHAR(25) NOT NULL,
	COLOR CHAR(10) NOT NULL,
	WEIGHT INT NOT NULL,

	PRIMARY KEY (P)
);

-- create SP table
CREATE TABLE SP(
	S CHAR(4) NOT NULL,
	P CHAR(4) NOT NULL,
	QTY INT NOT NULL,

	PRIMARY KEY (S,P),
	FOREIGN KEY (S) REFERENCES S(S),
	FOREIGN KEY (P) REFERENCES P(P)
);

-- add in the existing data from the slides to S
INSERT INTO S
	(S, SNAME, STATUS, CITY)
	VALUES('S1', 'Smith', '20', 'London');

INSERT INTO S
	(S, SNAME, STATUS, CITY)
	VALUES('S2', 'Jones', '10', 'Paris');

INSERT INTO S
	(S, SNAME, STATUS, CITY)
	VALUES('S3', 'Blake', '30', 'Paris');

INSERT INTO S
	(S, SNAME, STATUS, CITY)
	VALUES('S4', 'Clark', '20', 'London');

INSERT INTO S
	(S, SNAME, STATUS, CITY)
	VALUES('S5', 'Adams', '30', 'Athens');

-- **********************************************************

-- add in the existing data from the slides to P
INSERT INTO P
	(P, PNAME, COLOR, WEIGHT)
	VALUES('P1', 'Nut', 'Red', '12');

INSERT INTO P
	(P, PNAME, COLOR, WEIGHT)
	VALUES('P2', 'Bolt', 'Green', '17');

INSERT INTO P
	(P, PNAME, COLOR, WEIGHT)
	VALUES('P3', 'Screw', 'Blue', '17');

INSERT INTO P
	(P, PNAME, COLOR, WEIGHT)
	VALUES('P4', 'Screw', 'Red', '14');

INSERT INTO P
	(P, PNAME, COLOR, WEIGHT)
	VALUES('P5', 'Cam', 'Blue', '12');

INSERT INTO P
	(P, PNAME, COLOR, WEIGHT)
	VALUES('P6', 'Cog', 'Red', '19');

-- **********************************************************

-- add in the existing data from the slides to SP
INSERT INTO SP
	(S, P, QTY)
	VALUES('S1', 'P1', '300');

INSERT INTO SP
	(S, P, QTY)
	VALUES('S1', 'P2', '200');

INSERT INTO SP
	(S, P, QTY)
	VALUES('S1', 'P3', '400');

INSERT INTO SP
	(S, P, QTY)
	VALUES('S1', 'P4', '200');

INSERT INTO SP
	(S, P, QTY)
	VALUES('S1', 'P5', '100');

INSERT INTO SP
	(S, P, QTY)
	VALUES('S1', 'P6', '100');

INSERT INTO SP
	(S, P, QTY)
	VALUES('S2', 'P1', '300');

INSERT INTO SP
	(S, P, QTY)
	VALUES('S2', 'P2', '400');

INSERT INTO SP
	(S, P, QTY)
	VALUES('S3', 'P2', '200');

INSERT INTO SP
	(S, P, QTY)
	VALUES('S4', 'P2', '200');

INSERT INTO SP
	(S, P, QTY)
	VALUES('S4', 'P4', '300');

INSERT INTO SP
	(S, P, QTY)
	VALUES('S4', 'P5', '400');