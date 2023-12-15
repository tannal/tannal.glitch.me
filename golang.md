


```sh

sudo apt-get install gccgo
GOROOT_BOOTSTRAP=/usr ./make.bash

GOOS=linux GOARCH=amd64 curl -sSL https://go.dev/src/bootstrap.bash | bash

```