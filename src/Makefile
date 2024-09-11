CC = g++
FLAGS = -O2 -Wall -Wextra -fPIC -lfmt

PREFIX = /usr/local/



update: lognest.o
	${CC} -o ../libLogNest.so -shared lognest.o

lognest.o: lognest.cpp
	${CC} ${FLAGS} -c $^ -o $@

clear: 
	rm lognest.o

install:
	cp ../libLogNest.so ${PREFIX}lib

	mkdir -p ${PREFIX}include/lognest
	cp lognest.hpp ${PREFIX}include/lognest/lognest.hpp
