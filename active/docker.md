


# inbox

[Service]
Environment="HTTP_PROXY=http://127.0.0.1:8890"
Environment="HTTPS_PROXY=http://127.0.0.1:8890"
Environment="NO_PROXY=localhost,127.0.0.1

(base) a17@17:~/tannalwork/projects$ sudo mkdir -p /etc/systemd/system/docker.service.d
sudo nano /etc/systemd/system/docker.service.d/http-proxy.conf
(base) a17@17:~/tannalwork/projects$ 
(base) a17@17:~/tannalwork/projects$ sudo systemctl daemon-reload
(base) a17@17:~/tannalwork/projects$ sudo systemctl restart docker
(base) a17@17:~/tannalwork/projects$ sudo systemctl show --property=Environment docker
Environment=HTTP_PROXY=http://127.0.0.1:8890 HTTPS_PROXY=http://127.0.0.1:8890 NO_PROXY=localhost,127.0.0.1
(base) a17@17:~/tannalwork/projects$ docker run hello-world
Unable to find image 'hello-world:latest' locally
latest: Pulling from library/hello-world
c1ec31eb5944: Pull complete 
Digest: sha256:91fb4b041da273d5a3273b6d587d62d518300a6ad268b28628f74997b93171b2
Status: Downloaded newer image for hello-world:latest

Hello from Docker!
This message shows that your installation appears to be working correctly.

To generate this message, Docker took the following steps:
 1. The Docker client contacted the Docker daemon.
 2. The Docker daemon pulled the "hello-world" image from the Docker Hub.
    (amd64)
 3. The Docker daemon created a new container from that image which runs the
    executable that produces the output you are currently reading.
 4. The Docker daemon streamed that output to the Docker client, which sent it
    to your terminal.

To try something more ambitious, you can run an Ubuntu container with:
 $ docker run -it ubuntu bash

Share images, automate workflows, and more with a free Docker ID:
 https://hub.docker.com/

For more examples and ideas, visit:
 https://docs.docker.com/get-started/

(base) a17@17:~/tannalwork/projects$ 


https://github.com/opencontainers
https://github.com/moby/moby/


# dev

docker image rm

docker login git.tanmeng.org

docker build . -f Dockerfile_ubuntu_apt -t llvm-tutor-ubuntu-apt


# people

involves:thaJeztah
involves:dvdksn
involves:vvoland
involves:laurazard
involves:akerouanton
involves:krissetto
involves:Benehiko
involves:neersighted
involves:cpuguy83
involves:jsternberg
involves:crazy-max
involves:ndeloof
involves:AkihiroSuda
involves:tonistiigi
involves:rumpl
involves:tianon


compose
involves:ndeloof
involves:milas
involves:dependabot[bot]
involves:glours
involves:thaJeztah
involves:jhrotko
involves:laurazard
involves:aevesdocker
involves:jsoriano
involves:g0t4
involves:dvdksn
involves:mattwalo32
involves:BenjaminGuzman
involves:neersighted
involves:kimdcottrell
involves:koooge
involves:ulyssessouza
involves:felixfontein
involves:TP-O
involves:temenuzhka-thede
involves:silvin-lubecki
involves:relrelb
involves:crazy-max
involves:nicksieger
involves:horus
involves:cpuguy83
involves:1arp
involves:PiotrDabrowskey
involves:oandrew
involves:sebastian-correa
involves:delath
involves:racequite
involves:jfly
involves:robbert-ef
involves:callthingsoff
involves:ezradiniz
involves:cuishuang
involves:shantanoo-desai
involves:prafgup
involves:ibilalkayy
involves:kumarlokesh
involves:akerouanton
involves:rumpl



involves:thaJeztah
involves:vvoland
involves:corhere
involves:neersighted
involves:akerouanton
involves:robmry
involves:crazy-max
involves:cpuguy83
involves:AkihiroSuda
involves:rumpl
involves:tianon
involves:tonistiigi
involves:dmcgowan
involves:samuelkarp
involves:ndeloof
involves:coolljt0725
involves:kolyshkin
involves:dperny
involves:tiborvass
involves:tao12345666333
involves:justincormack
involves:cyphar