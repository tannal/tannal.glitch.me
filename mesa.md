


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