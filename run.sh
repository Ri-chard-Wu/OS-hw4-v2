
# Target=test2

# rm ${Target}

# g++ -o ${Target} ${Target}.cpp -lpthread -TEST_MACRO

# ./${Target}


#=--------------------------------

clear

make clean
make
./main
python3 verify.py
















