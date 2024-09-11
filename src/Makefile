CC = g++
FLAGS = -O2 -Wall -Wextra -fPIC -lfmt



update: lognest.o
	${CC} -o ../libLogNest.so -shared lognest.o

lognest.o: lognest.cpp
	${CC} ${FLAGS} -c $^ -o $@

clear: 
	rm lognest.o

