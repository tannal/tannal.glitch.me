
# dev
```
应用程序
    ↓
libGL.so (Mesa的实现)
    ↓
libGLX.so (GLX 抽象层)
    ↓
libGLX_nvidia.so (NVIDIA的GLX实现) 或 libGLX_mesa.so (Mesa的GLX实现)
    ↓
显卡驱动 (NVIDIA kernel driver)
```



# people

# inbox

Graphics:
  Device-1: bcm2712-hdmi0 driver: vc4_hdmi v: N/A bus-ID: N/A
    chip-ID: brcm:107c701400 class-ID: hdmi
  Device-2: bcm2712-hdmi1 driver: vc4_hdmi v: N/A bus-ID: N/A
    chip-ID: brcm:107c706400 class-ID: hdmi
  Display: wayland server: X.org v: 1.21.1.7 with: Xwayland v: 23.2.0
    compositor: gnome-shell v: 45.0 driver: X: loaded: fbdev
    gpu: vc4-drm,vc4_crtc,vc4_dpi,vc4_dsi,vc4_firmware_kms,vc4_hdmi,vc4_hvs,vc4_txp,vc4_v3d,vc4_vec
    display-ID: 0
  Monitor-1: HDMI-A-1 model: Philips PHL 271V8 serial: 27916 built: 2023
    res: 1920x1080 dpi: 82 gamma: 1.2 size: 598x336mm (23.54x13.23")
    diag: 686mm (27") ratio: 16:9 modes: max: 1920x1080 min: 720x400
  API: OpenGL v: 3.1 Mesa 24.1.0-devel (git-e1afffe7fa) renderer: V3D 7.1.7
    direct-render: Yes

tannal@raspi:~/tannalwork/projects/Vulkan$ inxi -Gay
Graphics:
  Device-1: bcm2712-hdmi0 driver: vc4_hdmi v: N/A bus-ID: N/A
    chip-ID: brcm:107c701400 class-ID: hdmi
  Device-2: bcm2712-hdmi1 driver: vc4_hdmi v: N/A bus-ID: N/A
    chip-ID: brcm:107c706400 class-ID: hdmi
  Display: wayland server: X.org v: 1.21.1.7 with: Xwayland v: 23.2.0
    compositor: gnome-shell v: 45.0 driver: X: loaded: fbdev
    gpu: vc4-drm,vc4_crtc,vc4_dpi,vc4_dsi,vc4_firmware_kms,vc4_hdmi,vc4_hvs,vc4_txp,vc4_v3d,vc4_vec
    display-ID: 0
  Monitor-1: HDMI-A-1 model: Philips PHL 271V8 serial: 27916 built: 2023
    res: 1920x1080 dpi: 82 gamma: 1.2 size: 598x336mm (23.54x13.23")
    diag: 686mm (27") ratio: 16:9 modes: max: 1920x1080 min: 720x400
  API: OpenGL v: 3.1 Mesa 23.2.1-1ubuntu3.1 renderer: V3D 7.1
    direct-render: Yes

git clone https://gitlab.freedesktop.org/mesa/mesa.git
sudo apt install glslang-tools libclc-17-dev libdrm-dev libllvmspirvlib-16-dev libclang-dev libwayland-dev libwayland-egl-backend-dev libx11-dev libxext-dev libxfixes-dev

sudo apt install libx11-dev libxext-dev libxfixes-dev libx11-xcb-dev libxcb-keysyms1-dev libxcb-glx0-dev libxcb-dri2-0-dev libxcb-dri3-dev libxcb-present-dev libxcb-sync-dev libxcb-xfixes0-dev libxshmfence-dev libxxf86vm-dev libxrandr-dev

sudo apt install zypper
sudo zypper source-install --build-deps-only Mesa

glxinfo
glxgears

meson setup --reconfigure build/ -Dplatforms=x11,wayland -Dgallium-drivers=v3d,vc4 -Dvulkan-drivers=broadcom -Dgbm=enabled -Degl=enabled -Dopengl=true

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

ninja install -C build
ninja uninstall -C build

```
