
# dev

r -D data/
./initdb -d data

set follow-fork-mode child

# inbox

pgrep -a postgres

./psql -h 192.168.43.95 -p 5432 -U tannal -d postgres 

sudo perf record -F 99 -p 27184 -g -- sleep 30
sudo perf script > out.postgresstacks01
./stackcollapse-perf.pl < out.postgresstacks01 | ./flamegraph.pl > ./out.postgresstacks01.svg


sudo perf record -F 99 -p 27184 -g -- sleep 30
sudo perf script > out.postgresreadstacks01
./stackcollapse-perf.pl < out.postgresreadstacks01 | ./flamegraph.pl > ./out.postgresreadstacks01.svg


\i ~/tannalwork/cans/ddd.sql

sudo perf record -F 99 -p 27184 -g -- sleep 30


# setup

```bash
git clone https://github.com/postgres/postgres
sudo apt install meson bison flex


./configure --prefix=/home/ubuntu/tannalwork/projects/postgres/_install

meson setup build
meson setup --reconfigure --prefix=/home/tannal/tannalwork/projects/postgres/_install build
meson setup --prefix=/home/ubuntu/tannalwork/projects/postgres/_install build
meson setup --prefix=`pwd`/_install build

ninja -C build
ninja install -C build
ln -sfn ./build/compile_commands.json compile_commands.json 

```

# people

involves:michaelpq
involves:petere
involves:tglsfdc
involves:akorotkov
involves:hlinnaka
involves:bmomjian
involves:danielgustafsson
involves:david-rowley
involves:alvherre
involves:nathan-bossart
involves:robertmhaas
involves:jeff-davis
involves:macdice
involves:anarazel
involves:tvondra
involves:j-naylor
involves:MasahikoSawada
involves:adunstan
involves:nmisch
involves:deanrasheed
involves:petergeoghegan
involves:amitlan
involves:tatsuo-ishii
involves:mhagander
involves:jconway
involves:MasaoFujii
involves:horiguti

involves:petere
involves:bmomjian
involves:anarazel
involves:mhagander


# inbox


./psql -h 192.168.43.246 -p 5432 -U tannal -d postgres 

873 /home/tannal/tannalwork/projects/postgres/_install/bin/postgres -D data
958 postgres: checkpointer 
959 postgres: background writer 
974 postgres: walwriter 
975 postgres: autovacuum launcher 
976 postgres: archiver failed on 000000010000000000000001
977 postgres: logical replication launcher


\list

SELECT
  d.datname as "Name",
  pg_catalog.pg_get_userbyid(d.datdba) as "Owner",
  pg_catalog.pg_encoding_to_char(d.encoding) as "Encoding",
  CASE d.datlocprovider WHEN 'c' THEN 'libc' WHEN 'i' THEN 'icu' END AS "Locale Provider",
  d.datcollate as "Collate",
  d.datctype as "Ctype",
  d.daticulocale as "ICU Locale",
  d.daticurules as "ICU Rules",
  CASE WHEN pg_catalog.cardinality(d.datacl) = 0 THEN '(none)' ELSE pg_catalog.array_to_string(d.datacl, E'\n') END AS "Access privileges"
FROM pg_catalog.pg_database d
ORDER BY 1;

sudo stackcount-bpfcc -i 2 -p 4407 --debug "ext4*"

ext4_llseek
  invoke_syscall
  el0_svc_common.constprop.0
  do_el0_svc
  el0_svc
  el0t_64_sync_handler
  el0t_64_sync
  __GI___lseek
  smgrnblocks
  table_block_relation_size
  RelationGetNumberOfBlocksInFork
  initscan
  heap_beginscan
  SeqNext
  ExecScan
  standard_ExecutorRun
  PortalRunSelect
  PortalRun
  PostgresMain
  ServerLoop.isra.0
  PostmasterMain

ext4_llseek
  invoke_syscall
  el0_svc_common.constprop.0
  do_el0_svc
  el0_svc
  el0t_64_sync_handler
  el0t_64_sync
  __GI___lseek
  smgrnblocks
  table_block_relation_size
  RelationGetNumberOfBlocksInFork
  table_block_relation_estimate_size
  get_relation_info
  build_simple_rel
  add_base_rels_to_query
  query_planner
  grouping_planner
  subquery_planner
  standard_planner
  pg_plan_query
  pg_plan_queries
  BuildCachedPlan
  GetCachedPlan
  PostgresMain
  ServerLoop.isra.0
  PostmasterMain
  main

accessmtd (*accessMtd)(node) node.Seqscan.c SeqNext

ScanState
ProcState

ExecScan(accessmtd, )
ExecScanFech(node, accessmtd, recheckMtd)

b XLog

b PageAddItemExtended





meson setup --prefix=C:/Users/tannal/tannalwork/projects/postgres/_install build


https://github.com/RustMagazine
https://github.com/hlinnaka

https://github.com/postgres/postgres/commits?author=hlinnaka
https://github.com/postgres/postgres/commits?author=anarazel

https://paquier.xyz/

# run 

```bash
./initdb -d data

./pg_ctl -D data -l logfile start

./postgres -D data/

ps -aux | grep postgres

./psql -U tannal -w -d postgres
./psql -U ubuntu -w -d postgres
./psql -U codespace -w -d postgres

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/tannal/tannalwork/projects/postgres/_install/lib/
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/tannalwork/projects/postgres/_install/lib/

```

# postgresql

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


# inbox

TableScanDesc

vacuum garbage collection reorder page sweep clean up

heapam heap access method

```c
void
heap_insert(Relation relation, HeapTuple tup, CommandId cid,
			int options, BulkInsertState bistate)

```

pg_wal

pidfile.h

ls data/pg_wal/ -lash


postmaster.pid

git lfs install
git lfs track "*.iso"
git lfs track "*.tar.gz"

```bash

#!/bin/bash

BRANCH="$1"

if [ -z "$BRANCH" ]; then
    echo "Usage: $0 <branch>"
    exit 1
fi

# change path to your source code!!

SOURCE="/home/postgres/git/pg/dev/$BRANCH"
BUILD="/home/postgres/git/pg/dev/build/$BRANCH"
INSTALL="/home/postgres/git/pg/dev/install/$BRANCH"

if [ -d "$BUILD" ]; then
        rm -r "$BUILD"
fi

mkdir -p "$BUILD"

if [ -d "$INSTALL" ]; then
        rm -r "$INSTALL"/*
else
  mkdir "$INSTALL"
fi

(cd "$BUILD" && \
 CFLAGS="-pg -I/usr/include/mit-krb5 -I/usr/include/python3.8/ -fuse-ld=gold -ggdb -Og -g3 -fno-omit-frame-pointer -U HAVE_POSIX_FADVISE" LDFLAGS=-L/usr/lib/x86_64-linux-gnu/mit-krb5 "$SOURCE"/configure --silent --prefix="$INSTALL" --with-openssl --with-tcl --with-tclconfig=/usr/lib/tcl8.6 --with-perl --w
ith-libxml --with-libxslt --with-python --with-gssapi --with-systemd --with-ldap --enable-nls --enable
-debug --enable-cassert --enable-tap-tests --enable-depend && \
 # CFLAGS="-I/usr/include/mit-krb5 -fuse-ld=gold -ggdb -Og -g3 -fno-omit-frame-pointer -U HAVE_POSIX_F
ADVISE" LDFLAGS=-L/usr/lib/x86_64-linux-gnu/mit-krb5 "$SOURCE"/configure --silent --prefix="$INSTALL"
--with-ssl=nss --with-tcl --with-tclconfig=/usr/lib/tcl8.6 --with-perl --with-libxml --with-libxslt --with-python --with-gssapi --with-systemd --with-ldap --enable-nls --enable-debug --enable-cassert --enable-tap-tests --enable-depend && \
 make -s -j4 PG_TEST_EXTRA='kerberos ssl' && \
 make -s -j4 install PG_TEST_EXTRA='kerberos ssl' && \
 make -s -j4 check PG_TEST_EXTRA='kerberos ssl' && \
 make -s -j4 world PG_TEST_EXTRA='kerberos ssl' && \
 make -s -j4 install-world PG_TEST_EXTRA='kerberos ssl' && \
 make -s -j4 check-world PG_TEST_EXTRA='kerberos ssl' -O PROVE_FLAGS=-j4 \
)

echo
echo "Branch: $BRANCH run completed."


```

git worktree list

git cherry-pick master, stable

pg_uprade

cfbot.cputube.org

kyber/bfq io sch

mailing lists

pgsql-hackers pgsql-bugs pgsql-docs postgresql.org/list/

```bash

sudo sh -c 'echo "deb https://apt.postgresql.org/pub/repos/apt $(lsb_release -cs)-pgdg main" > /etc/apt/sources.list.d/pgdg.list'
wget --quiet -O - https://www.postgresql.org/media/keys/ACCC4CF8.asc | sudo apt-key add -
sudo apt-get update
sudo apt-get -y install postgresql

sudo -i -u postgres
psql

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


/usr/lib/postgresql/15/bin/postgres -D /var/lib/postgresql/15/main -c config_file=/etc/postgresql/15/main/postgresql.conf

/usr/lib/postgresql/15/bin/postgres -D /home/tannal/tannalwork/projects/data -c config_file=/etc/postgresql/15/main/postgresql.conf

```

sudo snap install postgresql

# compliation

-DENFORCE_REGRESSION_TEST_NAME_RESTRICTIONS

-DWRITE_READ_PARSE_PLAN_TREES

-DCOPY_PARSE_PLAN_TREES

-DRAW_EXPRESSION_COVERAGE_TEST

-Og -ggdb -g3, for gdb

-fno-omit-frame-pointer, for perf profiles

-DCLOBBER_CACHE_ALWAYS
-DRELCACHE_FORCE_RELEASE -DCATCACHE_FORCE_RELEASE

# reference

https://peter.eisentraut.org/blog/2024/01/03/using-clangd-for-postgresql-development

https://wiki.postgresql.org/wiki/Developer_FAQ#What_debugging_features_are_available.3F

# appendix

```sql

-- Generate and insert sample data into Products table
DO $$
DECLARE
    i INT := 1;
BEGIN
    WHILE i <= 1000000 LOOP
        INSERT INTO Products (ProductID, ProductName, Price)
        VALUES 
            (i, 'Product ' || i, RANDOM() * 1000);
        i := i + 1;
    END LOOP;
END $$;

-- Generate and insert sample data into Customers table
DO $$
DECLARE
    i INT := 1;
BEGIN
    WHILE i <= 1000000 LOOP
        INSERT INTO Customers (CustomerID, FirstName, LastName, Email)
        VALUES 
            (i, 'FirstName ' || i, 'LastName ' || i, 'email' || i || '@example.com');
        i := i + 1;
    END LOOP;
END $$;

-- Generate and insert sample data into Orders table
DO $$
DECLARE
    i INT := 1;
BEGIN
    WHILE i <= 1000000 LOOP
        INSERT INTO Orders (OrderID, CustomerID, OrderDate)
        VALUES 
            (i, (i % 1000) + 1, CURRENT_DATE - (i % 100));
        i := i + 1;
    END LOOP;
END $$;

-- Generate and insert sample data into OrderDetails table
DO $$
DECLARE
    i INT := 1;
BEGIN
    WHILE i <= 1000000 LOOP
        INSERT INTO OrderDetails (OrderDetailID, OrderID, ProductID, Quantity)
        VALUES 
            (i, (i % 100000) + 1, (i % 1000) + 1, (i % 10) + 1);
        i := i + 1;
    END LOOP;
END $$;


```