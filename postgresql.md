# run 

```bash
./initdb -d data

pg_ctl -D data -l logfile start

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

```bash
#0  heapgetpage (sscan=0x555555ffa8c0, block=0) at heapam.c:378
#1  0x0000555555690c9e in heapgettup_pagemode (scan=0x555555ffa8c0, 
    dir=ForwardScanDirection, nkeys=1, key=0x555555ffa2f0)
    at heapam.c:879
#2  0x0000555555691ab1 in heap_getnextslot (sscan=0x555555ffa8c0, 
    direction=<optimized out>, slot=0x555555ffa500) at heapam.c:1142
#3  0x00005555556a86ce in table_scan_getnextslot (slot=<optimized out>, 
    direction=ForwardScanDirection, sscan=<optimized out>)
    at ../../../../src/include/access/tableam.h:1066
#4  systable_getnext (sysscan=sysscan@entry=0x555555ff9e60)
    at genam.c:533
#5  0x0000555555baa772 in SearchCatCacheMiss (
    cache=cache@entry=0x555555fc5b00, nkeys=nkeys@entry=1, 
    hashValue=hashValue@entry=3830081846, hashIndex=hashIndex@entry=2, 
--Type <RET> for more, q to quit, c to continue without paging--
    v1@entry=403, v2=v2@entry=0, v3=0, v4=0) at catcache.c:1431
#6  0x0000555555bab7d8 in SearchCatCacheInternal (v4=0, v3=0, v2=0, 
    v1=403, nkeys=1, cache=0x555555fc5b00) at catcache.c:1351
#7  SearchCatCache1 (cache=0x555555fc5b00, v1=403) at catcache.c:1219
#8  0x0000555555bc0779 in SearchSysCache1 (cacheId=cacheId@entry=2, 
    key1=<optimized out>) at syscache.c:225
#9  0x0000555555bbbbe5 in RelationInitIndexAccessInfo (
    relation=relation@entry=0x7fffec5cae88)
    at ../../../../src/include/postgres.h:254
#10 0x0000555555bbc463 in RelationBuildDesc (targetRelId=2965, 
    insertIt=insertIt@entry=true) at relcache.c:1208
#11 0x0000555555bbd733 in RelationIdGetRelation (
    relationId=<optimized out>, relationId@entry=2965) at relcache.c:2109
#12 0x000055555563ec96 in relation_open (
    relationId=relationId@entry=2965, lockmode=lockmode@entry=1)
    at relation.c:59
#13 0x00005555556a8e2e in index_open (relationId=relationId@entry=2965, 
    lockmode=lockmode@entry=1) at indexam.c:137
#14 0x00005555556a840c in systable_beginscan (
    heapRelation=heapRelation@entry=0x7fffec5c9918, 
    indexId=indexId@entry=2965, indexOK=indexOK@entry=true, 
    snapshot=snapshot@entry=0x555555ffa0c0, nkeys=nkeys@entry=2, 
    key=key@entry=0x7fffffffc720) at genam.c:399
#15 0x0000555555757402 in ApplySetting (
    snapshot=snapshot@entry=0x555555ffa0c0, 
    databaseid=databaseid@entry=5, roleid=roleid@entry=10, 
    relsetting=relsetting@entry=0x7fffec5c9918, 
    source=source@entry=PGC_S_DATABASE_USER) at pg_db_role_setting.c:238
#16 0x0000555555bd986d in process_settings (databaseid=5, roleid=10)
    at postinit.c:1330
#17 0x0000555555bd9feb in InitPostgres (in_dbname=in_dbname@entry=0x0, 
    dboid=<optimized out>, dboid@entry=5, username=username@entry=0x0, 
    useroid=useroid@entry=0, flags=flags@entry=0, 
    out_dbname=out_dbname@entry=0x7fffffffc9c0 "postgres")
    at postinit.c:1207
#18 0x00005555559b3850 in AutoVacWorkerMain (argc=argc@entry=0, 
    argv=argv@entry=0x0) at autovacuum.c:1683
#19 0x00005555559b39ca in StartAutoVacWorker () at autovacuum.c:1478
#20 0x00005555559bc233 in StartAutovacuumWorker () at postmaster.c:5443
#21 0x00005555559bc646 in process_pm_pmsignal () at postmaster.c:5150
#22 0x00005555559bc97c in ServerLoop () at postmaster.c:1767
--Type <RET> for more, q to quit, c to continue without paging--
#23 0x00005555559bdf8b in PostmasterMain (argc=3, argv=<optimized out>)
    at postmaster.c:1475
#24 0x00005555558d36cd in main (argc=3, argv=0x555555f65050)
    at main.c:198
```

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

postgres


sudo snap install postgresql


```bash

git clone https://github.com/postgres/postgres

./configure



mkdir _install

./configure --prefix="/home/tannal/tannalwork/projects/postgres/_install"  --enable-debug 

./configure --enable-cassert --enable-debug CFLAGS="-ggdb -Og -g3 -fno-omit-frame-pointer" --prefix="/home/tannal/tannalwork/projects/postgres/_install" 


sudo apt install bison

./configure --enable-cassert --enable-debug CFLAGS="-ggdb -Og -g3 -fno-omit-frame-pointer" --prefix=`pwd`/_install

sudo apt install libreadline-dev

make -j20

make -j20 install

cd src/bin/initdb

sudo apt install meson bison flex

make distclean

meson setup build
meson setup --prefix=/home/ubuntu/tannalwork/projects/postgres/_install build
meson setup --prefix=`pwd`/_install build

ln -sfn ./build/compile_commands.json compile_commands.json 

set follow-fork-mode child

gdb ./_install/bin/postgres
set follow-fork-mode child
attach

b epoll_wait

ls -lash /proc/3666998/fd


src/backend/storage/buffer/bufmgr.c


tar -czvf postgresql_x86-64_linux.tar.gz _install

tar -czvf ../build/postgresql_x86-64_linux_debug_$(date +%Y%m%d-%H%M%S)_$(git rev-parse --short HEAD).tar.gz _install/

```

# internals

caller knows more than callee

buf_table.c
bufmgr.c

nbtpage.c
nbtsearch.c
nbtree.c
indexam.c

genam.c general Index Access Methods
catcache.c  System Catalog Cache
syscache.c
miscinit.c
postinit.c

postmaster.c postmaster ServerLoop

parallel.c
bgworker.c
main.c

# compliation

-DENFORCE_REGRESSION_TEST_NAME_RESTRICTIONS

-DWRITE_READ_PARSE_PLAN_TREES

-DCOPY_PARSE_PLAN_TREES

-DRAW_EXPRESSION_COVERAGE_TEST

-Og -ggdb -g3, for gdb

-fno-omit-frame-pointer, for perf profiles

use with care

-DCLOBBER_CACHE_ALWAYS
-DRELCACHE_FORCE_RELEASE -DCATCACHE_FORCE_RELEASE

menson/ninja




# reference

https://peter.eisentraut.org/blog/2024/01/03/using-clangd-for-postgresql-development

https://wiki.postgresql.org/wiki/Developer_FAQ#What_debugging_features_are_available.3F