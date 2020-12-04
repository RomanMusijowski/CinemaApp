--sqlite3 mydatabase.db




CREATE TABLE  USERS (
    userId INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    email VARCHAR(64) NOT NULL,
    username VARCHAR(64) NOT NULL,
    password VARCHAR(64) NOT NULL
);

CREATE TABLE  MOVIES (
    movieId INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    name VARCHAR(64) NOT NULL,
    date TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,   
    roomId INTEGER,
    FOREIGN KEY(roomId) REFERENCES ROOMS(roomId)
);


CREATE TABLE  ROOMS (
    roomId INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    placesCount INTEGER NOT NULL
);





INSERT INTO USERS
    (`email`, `username`, `password`)
VALUES
    ("user1@gmail.com", "user1", "user"),
    ("user2@gmail.com", "user2", "user"),
    ("user3@gmail.com", "user3", "user");

INSERT INTO ROOMS
    ('placesCount')
VALUES
    (50),
    (50),
    (50),
    (50);

INSERT INTO MOVIES
    (`name`, `roomId`)
VALUES
    ("Film1" , 1),
    ("Film2" , 2),
    ("Film3", 3);






