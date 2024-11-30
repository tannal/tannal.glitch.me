

git clone https://github.com/mltframework/mlt.git

cmake -G Ninja -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Release'


sudo apt install build-essential cmake extra-cmake-modules pkg-config libkf5archive-dev libkf5bookmarks-dev libkf5coreaddons-dev libkf5config-dev libkf5configwidgets-dev libkf5dbusaddons-dev libkf5kio-dev libkf5widgetsaddons-dev libkf5newstuff-dev libkf5xmlgui-dev libkf5declarative-dev libkf5networkmanagerqt-dev libkf5filemetadata-dev libkf5purpose-dev kio kinit qtbase5-dev qtdeclarative5-dev qtquickcontrols2-5-dev qtmultimedia5-dev qtwebengine5-dev qml-module-qtquick-controls qml-module-org-kde-newstuff libqt5svg5-dev breeze-icon-theme oxygen-icon-theme libv4l-dev libavcodec-dev libavdevice-dev libavformat-dev libavutil-dev libswscale-dev libdvdread-dev libebml-dev libmatroska-dev liblist-moreutils-perl libjsoncpp-dev librttr-dev


git clone https://invent.kde.org/multimedia/kdenlive.git
cd kdenlive

cmake -G Ninja -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE='Release' -DCMAKE_INSTALL_PREFIX=/opt/kdenlive -DCMAKE_BUILD_TYPE=Release -DKDE_INSTALL_USE_QT_=ON