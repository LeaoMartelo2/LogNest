CC = g++
FLAGS = -O2 -Wall -Wextra -fPIC -lfmt


update: lognest.o
	${CC} -o libLogNest.so -shared lognest.o

lognest.o: lognest.cpp
	${CC} ${FLAGS} -c $^ -o $@

clear: 
	rm lognest.o libLogNest.so

install: update
	cp -n libLogNest.so /usr/lib/


	mkdir -p /usr/include/lognest/
	cp -n lognest.hpp /usr/include/lognest/lognest.hpp

uninstall:
	rm -f /usr/lib/libLogNest.so

	rm -rf /usr/include/lognest/

