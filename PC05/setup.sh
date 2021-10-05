wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC05/Makefile
make initialize
mkdir include src
cd src
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC05/src/max_prod_sub.cpp
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC05/src/max_sub_brute.cpp
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC05/src/max_sub_dyn.cpp
cd ..
rm setup.sh