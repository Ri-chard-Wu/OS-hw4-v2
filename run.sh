
# Target=test

# rm ${Target}

# g++ -o ${Target} ${Target}.cpp -lpthread

# ./${Target}


#=--------------------------------

clear

make clean
make
./main
python3 verify.py
















