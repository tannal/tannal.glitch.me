
确实有数据库使用了 Z-order curve (Z序曲线)！

PostgreSQL 的 BRIN (Block Range INdex) 索引：
R-trees
KD-trees
Geohash
其他专门的空间索引结构




# setup

cmake -G Ninja -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Debug' -DCOMPILER_CACHE=disabled -DCMAKE_CONFIGURATION_TYPES=''
