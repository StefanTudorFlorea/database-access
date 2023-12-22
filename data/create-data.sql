CREATE TABLE user_(
    id SERIAL PRIMARY KEY,
    name VARCHAR(125),
    age INT
);

INSERT INTO user_(name, age)
VALUES
    ('user-1', 10),
    ('user-2', 20),
    ('user-3', 30),
    ('user-4', 40);