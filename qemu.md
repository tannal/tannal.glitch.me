
# dev

# inbox

~/tannalwork/projects/qemu/build/qemu-system-x86_64 mylinux-core-glibc.iso -m 4G -S -gdb tcp::6666

gdb -ex "target remote :6666" ./linux6.7/vmlinux

sudo perf record --call-graph dwarf -F 99 -p 166955 -g -- sleep 30
sudo perf script > ./graph/out.qemu-system-x86_64-stacks01
./stackcollapse-perf.pl < ./graph/out.qemu-system-x86_64-stacks01 | ./flamegraph.pl > ./graph/out.qemu-system-x86_64-stacks01.svg


# setup

git clone https://gitlab.com/qemu-project/qemu.git

./configure --enable-debug 

make -j22

./build/qemu-arm
./build/qemu-aarch64


# modules

pci block

Submit patches
Review patches
Documentation
File bug reports

git-bisect

make check
make check-help


git-compile-check

# For example:
git format-patch --subject-prefix="PATCH" -s \
                 --find-renames --thread     \
                 --cover my_branch..


git send-email

git send-email --to=qemu-devel@nongnu.org \
               --cc=kwolf@redhat.com      \
               --cc=stefanha@redhat.com   \
               --suppress-cc=all *.patch


qemu-devel@nongnu.org
https://lists.nongnu.org/mailman/listinfo/qemu-trivial
https://lists.nongnu.org/mailman/listinfo/qemu-devel
http://git.qemu.org/
https://bugs.launchpad.net/qemu/

git://git.qemu.org/qemu.git

http://bugs.launchpad.net/qemu

https://wiki.qemu.org/Contribute

https://lists.nongnu.org/mailman/listinfo/qemu-trivial

http://git.qemu.org/

https://github.com/codyprime/git-scripts/blob/master/git-compile-check

# people

Jeff Cody Red Hat