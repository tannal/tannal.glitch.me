
# dev 

client flutter https://github.com/zulip/zulip-flutter

server python flask

client desktop electron 
https://github.com/zulip/zulip-desktop.git

# server

```bash
git clone https://github.com/zulip/zulip

sudo apt install python3-virtualenv vagrant

vagrant up --provider=docker

vim ~/.zulip-vagrant-config
HTTP_PROXY http://10.106.146.44:8890
HTTPS_PROXY http://10.106.146.44:8890
NO_PROXY localhost,127.0.0.1,.example.com,.zulipdev.com
HOST_IP_ADDR 0.0.0.0

vagrant reload

vagrant ssh
./tools/run-dev

(zulip-py3-venv) vagrant@3d18211a3ebb:/srv$ pgrep python -a
14087 python3 ./tools/run-dev
14089 python3 ./tools/webpack --watch --port=9994 --disable-host-check --host=0.0.0.0
14090 python3 ./manage.py rundjangoserver --settings=zproject.settings 127.0.0.1:9992
14091 python3 -m tornado.autoreload --until-success ./manage.py runtornado --autoreload --immediate-reloads --settings=zproject.settings 127.0.0.1:9993
14092 python3 ./manage.py process_queue --all --settings=zproject.settings
14093 python3 ./puppet/zulip/files/postgresql/process_fts_updates --quiet
14094 python3 ./manage.py deliver_scheduled_messages
14111 /srv/zulip-py3-venv/bin/python3 ./manage.py rundjangoserver --settings=zproject.settings 127.0.0.1:9992 --traceback
14123 /srv/zulip-py3-venv/bin/python3 ./manage.py process_queue --all --settings=zproject.settings --traceback


~                   
```
Web应用程序
Zulip的Web应用程序是使用Python的Django Web框架开发的。它处理HTTP请求、渲染页面以及与其他后端服务进行交互。
Tornado服务器
Zulip使用Tornado作为其实时推送服务器,用于向客户端推送新消息、事件和数据更新。Tornado服务器使用Python编写,利用其高效的异步网络框架来处理大量长期连接。
Redis
Redis被用作Zulip的内存中数据结构存储。它缓存在线用户、站点统计信息、推送通知队列等数据,以提高性能和减轻PostgreSQL的负载。
PostgreSQL
PostgreSQL是Zulip的主要数据存储。它存储用户数据、消息历史记录、文件上传等核心数据。Zulip利用PostgreSQL的全文搜索功能来实现强大的搜索功能。
RabbitMQ
RabbitMQ是Zulip使用的消息队列系统。它用于在Zulip的不同服务器组件之间传递异步任务,如发送电子邮件、生成消息通知等。
Nginx
Nginx作为反向代理服务器,负责接受传入的HTTP请求并将它们路由到Django应用程序或Tornado服务器。它还可以处理静态文件服务和SSL终止。
认证和授权
Zulip使用Django的认证系统来管理用户认证,并实现了基于角色的访问控制(RBAC)模型来管理用户权限和数据访问。
实时协作
Zulip利用Tornado实时推送服务器和React/Webpack构建的现代Web客户端,实现了实时消息传递、在线状态跟踪等协作功能。
扩展性和可靠性
Zulip的架构设计考虑了水平扩展和高可用性,可以通过添加更多服务器实例来扩展系统容量。它还支持备份和恢复等功能,以确保数据安全。

# Web App

https://github.com/zulip/zulip-flutter/issues/984

# flutter

https://chat.zulip.org/#narrow/stream/48-mobile/topic/flutter.3A.20double-tap.20to.20thumbs.20up.3F/near/1890047
