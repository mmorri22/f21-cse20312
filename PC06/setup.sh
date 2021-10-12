mkdir include src
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC06/JK_test_1.txt
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC06/JK_test_2.txt
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC06/JK_test_3.txt
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC06/JK_test_4.txt
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC06/BDC_test_1.txt
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC06/BDC_test_2.txt
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC06/BDC_test_3.txt
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC06/BDC_test_4.txt
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC06/test.sh
wget https://raw.githubusercontent.com/mmorri22/f21-cse20312/main/PC06/grade_sample.out
touch Makefile
touch include/JKFF.h
touch include/BDC.h
touch src/JKFF.cpp
touch src/BDC.cpp
touch src/JK_Test.cpp
touch src/BDC_Test.cpp
chmod a+rx test.sh
rm setup.sh