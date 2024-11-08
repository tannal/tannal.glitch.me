# architecture

./tools/lint --fix

Client <---> Webpack Dev Server (9994)
   |
   |         Django (9992)
   +------>  - 处理 HTTP 请求
   |         - 数据库操作
   |         - 业务逻辑
   |
   |         Tornado (9993)
   +------>  - WebSocket 连接
             - 实时消息推送

后台服务：
- 消息队列处理
- 定时任务
- 搜索索引更新

数据存储：
- PostgreSQL（主数据库）
- 全文搜索

# dev

docker pull ubuntu:22.04

./tools/test-js-with-puppeteer settings.test.ts
./tools/test-all
./tools/test-backend --rerun

Zulip使用RabbitMQ作为消息队列系统来处理异步任务和实现组件间通信。以下是Zulip使用RabbitMQ的核心过程和相关源码解析：

1. 配置RabbitMQ

RabbitMQ的配置文件位于`puppet/zulip/files/rabbitmq`目录。初始配置通过`scripts/setup/configure-rabbitmq`脚本完成。

2. 队列客户端封装

Zulip在`zerver/lib/queue.py`中封装了两个RabbitMQ客户端：

```python
# 异步客户端（用于Tornado）
class TornadoQueueClient:
    def __init__(self):
        # 初始化连接和通道
        self.connections = {}
        self.channel = None

    @asyncio.coroutine
    def connect(self):
        # 建立异步连接

    @asyncio.coroutine
    def publish(self, queue_name, body):
        # 异步发布消息

# 通用客户端
class SimpleQueueClient:
    def __init__(self):
        # 初始化连接和通道
        self.connection = None
        self.channel = None

    def connect(self):
        # 建立连接

    def publish(self, queue_name, body):
        # 发布消息
```

3. 定义队列处理器

队列处理器定义在`zerver/worker/`目录下。例如，邮件发送处理器：

```python
# zerver/worker/queue_processors.py

class EmailSendingWorker(queue_processors.QueueProcessingWorker):
    def consume(self, data):
        # 处理邮件发送任务
        send_email(**data)
```

4. 发布消息到队列

在需要异步处理的地方，Zulip会将任务发布到RabbitMQ队列：

```python
# 示例：发送邮件
from zerver.lib.queue import queue_json_publish

def send_email_async(to_user_ids, subject, content):
    event = {
        "type": "email",
        "to_user_ids": to_user_ids,
        "subject": subject,
        "content": content,
    }
    queue_json_publish("email_senders", event)
```

5. 消费队列消息

Supervisor启动的进程会持续从RabbitMQ队列中获取并处理消息：

```python
# zerver/worker/queue_processors.py

class QueueProcessingWorker:
    def start(self):
        while True:
            # 从队列获取消息
            message = self.queue_client.get()

            # 处理消息
            self.consume(message)
```

6. 应用服务器与Tornado推送系统通信

RabbitMQ还用于应用服务器和Tornado推送系统之间的通信：

```python
# 发布事件到推送队列
def send_event(realm, event, users):
    event_queue_data = {
        "event": event,
        "users": users,
    }
    queue_json_publish("tornado_events", event_queue_data)

# Tornado推送系统消费事件
class TornadoEventHandler(AsyncQueueConsumer):
    async def consume(self, event):
        # 处理事件并推送给相关用户
        await self.process_event(event)
```

7. 队列监控和管理

Zulip可能还实现了队列监控和管理功能，以确保队列系统的健康运行：

```python
def get_queue_stats():
    # 获取队列统计信息
    stats = rabbitmq_client.get_queue_stats()
    return stats

def purge_queue(queue_name):
    # 清空特定队列
    rabbitmq_client.purge_queue(queue_name)
```

总结：
Zulip使用RabbitMQ主要用于以下几个方面：
1. 异步处理耗时任务，如发送邮件和推送通知。
2. 实现应用服务器和Tornado推送系统之间的通信。
3. 处理需要可靠传递的任务。
4. 分散工作负载，提高系统整体性能和响应速度。

通过这种方式，Zulip能够高效地处理大量并发任务，同时保持主应用线程的响应性。RabbitMQ的使用使得Zulip的架构更加灵活和可扩展。

在生产环境中，PostgreSQL使用默认配置安装。
puppet/zulip/files/postgresql目录主要包含一个实用脚本和PostgreSQL扩展使用的自定义停用词列表。

tools/postgresql-init-dev-db脚本负责设置开发环境中的PostgreSQL扩展配置和创建开发用户。
tools/rebuild-dev-database脚本用于创建实际的数据库及其架构。

数据模型
Zulip使用Django ORM来定义和管理数据模型，这些模型会被映射到PostgreSQL的表结构中。

client flutter https://github.com/zulip/zulip-flutter

server python flask

client desktop electron
https://github.com/zulip/zulip-desktop.git

# server

https://zulip.readthedocs.io/en/latest/production/authentication-methods.html

https://zulip.readthedocs.io/en/latest/production/modify.html

Webhook是一种HTTP回调:一个HTTP POST请求,当某些事情发生时会被发送到特定的URL。它允许一个应用程序向另一个应用程序提供实时信息。

Webhook如何工作:

    用户配置一个webhook URL在接收应用(这里是Zulip)中。
    当发送应用中发生特定事件时,它会向这个URL发送HTTP POST请求。
    接收应用(Zulip)接收到这个请求,处理其中的数据,并执行相应的操作。

在Zulip中的应用:

    外部服务(如GitHub, JIRA等)可以配置webhook来向Zulip发送通知。
    当这些服务中发生特定事件(如新的代码提交,新的issue等),它们会自动向Zulip发送消息。
    Zulip接收这些消息,并在适当的频道中显示。

zerver/webhooks/目录的内容:

    每个集成可能有自己的子目录。
    包含处理来自不同服务的webhook请求的视图函数。
    包含测试这些集成的代码。
    可能还包含文档和配置文件。

优势:

    实时性:信息几乎是即时传递的。
    效率:减少了轮询的需要。
    自动化:可以触发自动化工作流。

使用webhook,Zulip可以成为团队所有工具和服务的中心枢纽,大大提高了团队的协作效率和信息流通。

zerver/actions/*.py

这里包含了大多数对用户可见的数据库表进行写操作的代码
遵循一个重要原则:所有调用send_event_on_commit来触发向客户端推送数据的代码必须放在这里
这样做可以集中管理数据修改和事件触发的逻辑,便于维护和优化

zerver/views/*.py

包含大多数Django视图函数
处理HTTP请求,实现各种API接口和页面渲染逻辑

zerver/webhooks/

包含Zulip的入站webhook集成的视图函数和测试
允许外部服务向Zulip发送消息和通知

zerver/tornado/views.py

包含Tornado框架的视图函数
处理WebSocket长连接,用于实时更新等功能

zerver/worker/

包含队列worker的代码
用于处理异步任务,如发送邮件、推送通知等

zerver/lib/markdown/

后端Markdown处理器
负责将Markdown格式转换为HTML,并进行自定义扩展

zproject/backends.py

包含身份验证后端的代码
实现各种登录方式,如LDAP、OAuth等

```bash
git clone https://github.com/zulip/zulip

sudo apt install python3-virtualenv vagrant

vagrant up --provider=docker

vim ~/.zulip-vagrant-config
HTTP_PROXY http://10.106.146.44:7890
HTTPS_PROXY http://10.106.146.44:7890
NO_PROXY localhost,127.0.0.1,.example.com,.zulipdev.com
HOST_IP_ADDR 0.0.0.0
ARG VAGRANT_UID=1000
vagrant reload

vagrant ssh
./tools/run-dev

tools/test-js-with-node


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



```bash
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

(zulip-py3-venv) vagrant@3d18211a3ebb:/srv$ pgrep rabbitmq -a
7979 /bin/sh /usr/sbin/rabbitmq-server
7987 /bin/sh /usr/lib/rabbitmq/bin/rabbitmq-server

(zulip-py3-venv) vagrant@3d18211a3ebb:/srv$ pgrep redis -a
5986 /usr/bin/redis-server 127.0.0.1:6379
(zulip-py3-venv) vagrant@3d18211a3ebb:/srv$ pgrep memcached -a
6716 /usr/bin/memcached -m 64 -p 11211 -u memcache -l 127.0.0.1 -P /var/run/memcached/memcached.pid
(zulip-py3-venv) vagrant@3d18211a3ebb:/srv$ pgrep postgres -a
7737 /usr/lib/postgresql/14/bin/postgres -D /var/lib/postgresql/14/main -c config_file=/etc/postgresql/14/main/postgresql.conf
7739 postgres: 14/main: checkpointer
7740 postgres: 14/main: background writer
7741 postgres: 14/main: walwriter
7742 postgres: 14/main: autovacuum launcher

(zulip-py3-venv) vagrant@3d18211a3ebb:/srv$ pgrep nginx -a

```


# networking problem

```bash
+RUN sed -i 's/archive.ubuntu.com/mirrors.aliyun.com/g' /etc/apt/sources.list && \
+    sed -i 's/security.ubuntu.com/mirrors.aliyun.com/g' /etc/apt/sources.list
+
+
+ENV HTTP_PROXY="http://10.106.146.44:8890"
+ENV HTTPS_PROXY="http://10.106.146.44:8890"
```


# zulip

从 inspect 的输出中，可以看到关键的挂载配置在 Mounts 部分：
这表明：
挂载类型：使用了 bind mount（绑定挂载）
源路径：主机上的 /home/a13/tannalwork/projects/zulip 目录
目标路径：容器内的 /srv/zulip 目录
权限：
RW: true 表示可读可写
Mode: "z" 是 SELinux 标签，允许容器访问共享内容
传播模式：rprivate 表示挂载点的私有传播
这个挂载配置可能是通过以下命令实现的：
Bash
这就是为什么你在主机上修改代码时，容器内立即可见的原因 —— 它们实际上是指向同一个文件系统位置的硬链接。这不是复制或同步，而是直接共享同一块磁盘空间。

"Mounts": [
    {
        "Type": "bind",
        "Source": "/home/a13/tannalwork/projects/zulip",
        "Destination": "/srv/zulip",
        "Mode": "z",
        "RW": true,
        "Propagation": "rprivate"
    }
]
docker run -v /home/a13/tannalwork/projects/zulip:/srv/zulip:z ...
