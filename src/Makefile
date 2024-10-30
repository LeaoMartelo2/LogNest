CC = gcc
FLAGS = -Wall -Wextra 


lib: lognest.o
	
	ar rcs libLogNest.a $^

lognest.o: lognest.c
	${CC} ${FLAGS} -c $^ -o $@

clear: 
	rm lognest.o libLogNest.a

install:

	\cp -n libLogNest.a /usr/lib/ 

	\mkdir -p /usr/include/lognest/
	\cp -n lognest.h /usr/include/lognest.h

uninstall:
	rm -f /usr/lib/libLogNest.a 

	rm /usr/include/lognest.h
