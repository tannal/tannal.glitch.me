```bash
# Add LLVM GPG signing key
sudo wget -O /usr/share/keyrings/llvm-snapshot.gpg.key https://apt.llvm.org/llvm-snapshot.gpg.key

# Optional: Verify the GPG key manually

# Use the key to authorize an entry for apt.llvm.org in apt sources list
echo "deb [signed-by=/usr/share/keyrings/llvm-snapshot.gpg.key] https://apt.llvm.org/$(lsb_release -sc)/ llvm-toolchain-$(lsb_release -sc)-18 main" | sudo tee -a /etc/apt/sources.list.d/llvm.list

# Update apt package list and install clang and associated packages
sudo apt update -y && sudo apt install clang-18 clangd-18 clang-format-18 clang-tidy-18 lld-18 -y
```
sudo apt update
sudo apt install apt-transport-https ca-certificates gnupg software-properties-common wget
wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | sudo tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null
sudo apt-add-repository "deb https://apt.kitware.com/ubuntu/ $(lsb_release -cs) main"
sudo apt update
sudo apt install cmake


wget https://github.com/ninja-build/ninja/releases/latest/download/ninja-linux.zip
unzip ninja-linux.zip
sudo mv ninja /usr/local/bin/


git clone https://github.com/LadybirdBrowser/ladybird/
./Meta/ladybird.sh run ladybird

export CC=clang-18
export CXX=clang++-18

CC=$CC=clang-18 CXX=clang++-18 ./Meta/ladybird.sh run