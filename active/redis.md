# dev



# setup


git clone https://github.com/redis/redis.git
cd redis/
time make -j20

./src/redis-server --protected-mode no


# inbox

Client
  Connection

```c
{type = 0x5555558c16c0 <CT_Socket.lto_priv.0>, state = CONN_STATE_CONNECTED, last_errno = 0, fd = 10, flags = 0, refs = 1, iovcnt = 1024, 
  private_data = 0x7ffff7927700, conn_handler = 0x0, write_handler = 0x0, read_handler = 0x555555610f60 <readQueryFromClient>}
```
src/commands



connSocketSetReadHandler

readQueryFromClient

redisCommand

redisCommandTable

getCommand

# setup

# people

involves:enjoy-binbin
involves:oranagra
involves:soloestoy
involves:sundb
involves:CharlesChen888
involves:madolson
involves:hwware
involves:hpatro
involves:zuiderkwast
involves:lyq2333
involves:guybe7
involves:yossigo
involves:roshkhatri
involves:YaacovHazan
involves:moshekaplan
involves:judeng
involves:meiravgri
involves:MeirShpilraien
involves:panjf2000
involves:slavak
involves:PingXie
involves:sjpotter
involves:moticless
involves:yangbodong22011
involves:tezc
involves:felipou
involves:fadidahanna
involves:ncghost1
involves:DarrenJiang13
involves:pizhenwei
involves:devnexen
involves:yoav-steinberg
involves:itamarhaber
