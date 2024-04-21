# people

# inbox

git clone https://gitlab.freedesktop.org/mesa/mesa.git
sudo apt install glslang-tools libclc-17-dev libdrm-dev libllvmspirvlib-16-dev libclang-dev libwayland-dev libwayland-egl-backend-dev libx11-dev libxext-dev libxfixes-dev

sudo apt install libx11-dev libxext-dev libxfixes-dev libx11-xcb-dev libxcb-keysyms1-dev libxcb-glx0-dev libxcb-dri2-0-dev libxcb-dri3-dev libxcb-present-dev libxcb-sync-dev libxcb-xfixes0-dev libxshmfence-dev libxxf86vm-dev libxrandr-dev

sudo apt install zypper
sudo zypper source-install --build-deps-only Mesa

glxinfo
glxgears

glxinfo | grep "OpenGL renderer"

# dev

```bash
sudo apt-get install qtwayland5 libwayland-egl-backend-dev libx11-xcb-dev libxcb-glx0-dev libxcb-dri2-0-dev libxcb-dri3-dev
git clone https://github.com/Mesa3D/mesa.git

git config --global http.sslverify false 
git config --global imap.sslverify false

git clone https://github.com/Mesa3D/mesa.git
cd mesa/
meson setup build
sudo apt install glslang-tools
meson setup build 
sudo apt install llvm
meson setup build
```

