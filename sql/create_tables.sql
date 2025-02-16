CREATE TABLE IF NOT EXISTS student(
    id SERIAL PRIMARY KEY,
    name VARCHAR(255)
);

CREATE TABLE IF NOT EXISTS student_task(
    id SERIAL PRIMARY KEY,
    task VARCHAR(255),
    student_id INTEGER REFERENCES student(id)
);
