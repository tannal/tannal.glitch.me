

# people

gdb --args ./build/node ~/tannalwork/cans/add.js

# inbox

g++ -I. -I/home/tannal/tannalwork/projects/v8/v8/include main.cc -o main -fno-rtti -lv8_monolith -lv8_libbase -lv8_libplatform -ldl -L/home/tannal/tannalwork/projects/v8/v8/out.gn/x64.release.sample/obj/ -pthread -std=c++17 -DV8_COMPRESS_POINTERS -DV8_ENABLE_SANDBOX

g++ -I. -I/home/tannal/tannalwork/projects/v8/v8/include node.cc -o node -fno-rtti -luv -lv8_monolith -lv8_libbase -lv8_libplatform -ldl -L/home/tannal/tannalwork/projects/v8/v8/out.gn/x64.release.sample/obj/ -pthread -std=c++17 -DV8_COMPRESS_POINTERS -DV8_ENABLE_SANDBOX -g3 -O0

cmake -G Ninja -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Debug'

# dev
