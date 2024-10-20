

```bash
git clone https://github.com/rui314/mold.git
../install-build-deps.sh
cmake -G Ninja -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/opt/mold
n2 -C build

sudo cmake --install .

```