CFLAGS = -Wall -Werror -MP -MMD
.PHONY: clean all deposit-calc test

all :
	make bin/deposit-calc

bin/deposit-calc : build/src/main.o build/src/deposit.o
	mkdir bin -p
	gcc  build/src/main.o build/src/deposit.o -o bin/deposit-calc $(CFLAGS)

build/src/main.o : src/main.c src/deposit.h
	mkdir build -p
	gcc -c src/main.c -o build/src/main.o $(CFLAGS)

build/src/deposit.o : src/deposit.c src/deposit.h
	mkdir build -p
	gcc -c src/deposit.c -o build/src/deposit.o $(CFLAGS)

test :
	make bin/deposit-calc-test
	bin/deposit-calc-test

bin/deposit-calc-test : build/test/main.o build/test/deposit-test.o
	@echo "Making binary"
	@gcc build/test/main.o build/test/deposit-test.o build/test/deposit.o -o bin/deposit-calc-test $(CFLAGS)

build/test/main.o : src/deposit.h test/main.c
	@echo "Making main.o"
	@gcc -I thirdparty -c test/main.c -o build/test/main.o $(CFLAGS)
	@gcc -c src/deposit.c -o build/test/deposit.o $(CFLAGS) 

build/test/deposit-test.o : src/deposit.h test/deposit-test.c
	echo "Making deposit-test.o"
	gcc -c -I thirdparty test/deposit-test.c -o build/test/deposit-test.o $(CFLAGS)

build/test/deposit.o : src/deposit.h src/deposit.c
	@echo "Making deposit.o"
	@gcc -c src/deposit.c -o build/test/deposit.o $(CFLAGS)

clean :
	@echo "Cleaning files in build directory"
	@rm -rf build/src/*.d build/test/*.d 
	@rm -rf  build/src/*.o build/test/*.o
	@echo "Cleaning binaries"
	@rm -f bin/deposit-calc bin/deposit-calc-test
	@echo "All files have been cleaned."


-include build/*.d
