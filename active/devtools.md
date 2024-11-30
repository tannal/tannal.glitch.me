

# people



# inbox


# dev

mkdir devtools
cd devtools
fetch devtools-frontend


cd devtools-frontend
gclient sync
gn gen out/Default
autoninja -C out/Default

