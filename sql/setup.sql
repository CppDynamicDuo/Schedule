CREATE USER schedule_admin WITH PASSWORD 'test';
CREATE DATABASE schedule_db WITH OWNER schedule_admin;
GRANT ALL PRIVILEGES ON DATABASE schedule_db TO schedule_admin;
