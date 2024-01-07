


```bash

sudo apt-get install gccgo
sudo snap install go --classic

GOROOT_BOOTSTRAP=/usr ./make.bash
GOOS=linux GOARCH=amd64 curl -sSL https://go.dev/src/bootstrap.bash | bash



git clone https://go.googlesource.com/go

cd go/src

export PATH=/home/tannal/tannalwork/projects/go/bin:$PATH

./make.bash

```



# docs

```bash

git clone https://github.com/golang/website.git golang-website

```