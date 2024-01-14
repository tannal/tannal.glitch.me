kyber/bfq io sch

```bash

sudo sh -c 'echo "deb https://apt.postgresql.org/pub/repos/apt $(lsb_release -cs)-pgdg main" > /etc/apt/sources.list.d/pgdg.list'
wget --quiet -O - https://www.postgresql.org/media/keys/ACCC4CF8.asc | sudo apt-key add -
sudo apt-get update
sudo apt-get -y install postgresql

sudo -i -u postgres
psql

CREATE TABLE my_table (
    id serial PRIMARY KEY,
    data text
);

BEGIN;
DO $$ 
DECLARE
    i integer := 1;
BEGIN
    WHILE i <= 1000000 LOOP
        INSERT INTO my_table (data) VALUES ('Row ' || i);
        i := i + 1;
    END LOOP;
END $$;

SELECT count(*) FROM my_table;


sudo ./funccount '*vfs*'
sudo ./funccount '*ext4*'
sudo ./funccount '*blk_mq*'
sudo ./funccount '*nvme*'

sudo ./kprobe -s 'p:blk_mq_init_sched'


createdb mydb
psql -d mydb


psql -U postgres -d postgres -h localhost -d mydb



\password postgres
\conninfo


sudo perf record  --call-graph=fp target/debug/deno info zzazz.comd

/usr/lib/postgresql/15/bin/postgres -D /var/lib/postgresql/15/main -c config_file=/etc/postgresql/15/main/postgresql.conf

/usr/lib/postgresql/15/bin/postgres -D /home/tannal/tannalwork/projects/data -c config_file=/etc/postgresql/15/main/postgresql.conf

```

postgres


sudo snap install postgresql


```bash

git clone https://github.com/postgres/postgres

initdb -d data

./postgres -D data/

ps -aux | grep postgres

./psql -U a48 -w -d postgres


```