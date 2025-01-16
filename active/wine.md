
# people


# inbox

box64

git clone https://github.com/ptitSeb/box64
cd box64
cmake -B build -G Ninja -DCMAKE_INSTALL_PREFIX:PATH=/opt/box64 -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Debug'

ninja -C build
ln -sfn ./build/compile_commands.json compile_commands.json

cmake --install build
set follow-fork-mode child

install wine mono c sharp

# dev

git clone https://gitlab.winehq.org/wine/wine.git

sudo apt install libx11-dev:i386 libfreetype6-dev:i386

./configure -q -C --enable-archs=i386,x86_64,aarch64 --prefix=/opt/wine --enable-win64

git clone git://source.winehq.org/git/wine.git

time make -j22

make install

export WINE_DIR=/opt/wine/
