# inbox

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


sudo apt install libreadline-dev

make -j20

make -j20 install

cd src/bin/initdb



./initdb -d data

pg_ctl -D data -l logfile start

./postgres -D data/

ps -aux | grep postgres

./psql -U tannal -w -d postgres

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/tannal/tannalwork/projects/postgres/_install/lib/

sudo apt install meson

make distclean

meson setup build
meson setup --prefix=/desired/install/path build

ln -sfn ./build/compile_commands.json compile_commands.json 

set follow-fork-mode child

gdb ./_install/bin/postgres
set follow-fork-mode child
attach

b epoll_wait

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