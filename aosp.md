



# dev

PATH=~/bin:$PATH
curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
chmod a+x ~/bin/repo
git config --global user.name "tannal"
git config --global user.email "tannal2409@gmail.com"

repo init -u https://android.googlesource.com/platform/manifest

mkdir aosp

repo sync

source build/envsetup.sh

lunch
make -j 20



build completed successfully (01:58:12 (hh:mm:ss))