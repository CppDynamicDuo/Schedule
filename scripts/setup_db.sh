psql -U postgres -f sql/setup.sql -W
psql -U schedule_admin -d schedule_db -f sql/create_tables.sql -W
