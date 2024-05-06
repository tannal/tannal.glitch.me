

# dev



# inbox



# setup

dnf builddep mariadb
cmake -G Ninja -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Debug'

cmake ../server -DCONC_WITH_{UNITTEST,SSL}=OFF -DWITH_UNIT_TESTS=OFF -DCMAKE_BUILD_TYPE=Debug -DWITHOUT_DYNAMIC_PLUGIN=ON -DWITH_SAFEMALLOC=OFF -DWITH_SSL=bundled -DMYSQL_MAINTAINER_MODE=OFF -G Ninja

mysql-test/mtr --parallel=5 --mem --force --max-test-fail=40

./scripts/mariadb-install-db --srcdir=../server --defaults-file=~/mariadb.cnf

sql/mariadbd --defaults-file=~/mariadb.cnf

client/mariadb

# people

involves:dr-m
involves:vuvova
involves:sanja-byelkin
involves:montywi
involves:mariadb-YuchenPei
involves:abarkov
involves:FooBarrior
involves:grooverdan
involves:knielsen
involves:0Thirunarayanan
involves:1vaintroub
involves:2spetrunia
involves:3dmitryshulga
involves:4dbart
involves:5janlindstrom
involves:6bnestere
involves:7an3l
involves:8midenok
involves:9igorbabaev
involves:0sysprg
involves:1mariadb-RuchaDeodhar
involves:2illuusio
involves:3Olernov
involves:4vlad-lesin
involves:5mariadb-RexJohnston
involves:6andrelkin
involves:7cvicentiu
involves:8iangilfillan
involves:9sciascid
involves:0LinuxJedi
involves:1mariadb-lenastartseva
involves:2sjaakola
involves:3ottok
involves:4temeo
involves:59EOR9
involves:6Weijun-H
involves:7brad0
