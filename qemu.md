
# dev

PREFIX = aarch64-linux-gnu-
AARCH = 64
RASPPI = 3
./configure --qemu

./build/qemu-system-riscv64 -cpu rv64,v=true -M virt -nographic

./configure --target-list=riscv64-linux-user,riscv64-softmmu --enable-debug

riscv64-unknown-elf-gcc -march=rv64gcv -mabi=lp64d test_rvv.c -o test_rvv
riscv64-linux-gnu-gcc -march=rv64gcv -mabi=lp64d test_rvv.c -o test_rvv

./configure --enable-debug --target-list=riscv64-softmmu,riscv64-linux-user --enable-fdt

# inbox

reset_ts+0x9b
fold_tcg_ld_memcopy+0xdd
tcg_optimize+0x602
tcg_gen_code+0x162
setjmp_gen_code+0x135
tb_gen_code+0x281
cpu_exec_loop+0x101
cpu_exec_setjmp+0x5a
cpu_exec+0x98
tcg_cpu_exec+0x5a
mttcg_cpu_thread_fn+0x155
qemu_thread_start+0x12d
start_thread+0x2f2
__clone3+0x2f

~/tannalwork/projects/qemu/build/qemu-system-x86_64 mylinux-core-glibc.iso -m 4G -S -gdb tcp::6666

gdb -ex "target remote :6666" ./linux6.7/vmlinux

sudo perf record --call-graph dwarf -F 99 -p 166955 -g -- sleep 30
sudo perf script > ./graph/out.qemu-system-x86_64-stacks01
./stackcollapse-perf.pl < ./graph/out.qemu-system-x86_64-stacks01 | ./flamegraph.pl > ./graph/out.qemu-system-x86_64-stacks01.svg


# setup

git clone https://gitlab.com/qemu-project/qemu.git

sudo apt install -y --no-install-recommends \
        bison \
        ccache \
        clang  \
        flex \
        git \
        ninja-build \
        python3-pip \
        python3-setuptools \
        python3-tomli \
        python3-venv \
        python3-wheel

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

https://bugs.launchpad.net/bugs/bugtrackers/auto-gitlab.com-qemu-project-qemu--

https://wiki.qemu.org/Contribute

https://lists.nongnu.org/mailman/listinfo/qemu-trivial

http://git.qemu.org/

https://github.com/codyprime/git-scripts/blob/master/git-compile-check

# people

Jeff Cody Red Hat