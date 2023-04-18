DROP DATABASE IF EXISTS sensor_db;
CREATE DATABASE IF NOT EXISTS sensor_db;

use sensor_db;

CREATE TABLE IF NOT EXISTS sensors_tb (
    sensor INTEGER,
    value DOUBLE,
    registry DATETIME
);

DROP TABLE IF EXISTS sensors_report_tb;

CREATE TABLE IF NOT EXISTS sensors_report_tb (
    id INTEGER AUTO_INCREMENT,
    sensor INTEGER,
    value DOUBLE,
    registry DATETIME,
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS sensors_type_tb (
    type INTEGER NOT NULL,
    name VARCHAR (50) NOT NULL
);

insert into sensors_type_tb (type, name) values
     (1, "Temperature"),
     (2, "Humidty"),
     (3, "Barometry");
