
# Target=test2

# rm ${Target}

# g++ -o ${Target} ${Target}.cpp -lpthread -TEST_MACRO

# ./${Target}


#=--------------------------------

clear

make clean
rm *.log
make
./main
python3 verify.py
















