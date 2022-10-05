OUT = prog prog-a prog-so
LIBRARIES = liboutput_static.a liboutput.so
OBJECTS = *.o
FILES = *_tmp *1 *2 *3
CFLAGS = -fPIC -Wall -Werror
CC = cc

all:	prog prog-a prog-so

prog:	const.o fun.o prog.o

liboutput_static.a:	const.o fun.o
	ar -rcs $@ $^

liboutput.so:	const.o fun.o
	$(CC) -shared $^ -o $@

prog-a:	prog.o liboutput_static.a
	$(CC) -L. $< -loutput_static -o $@

prog-so: prog.o liboutput.so
	$(CC) -L. $< -loutput -o $@

%.o:	%.c
	$(CC) $(CFLAGS) $< -c -o $@

test:	compare_files all
	@ echo
	@ echo
	@ echo
	@ echo comparing files completed 

compare_files:	run_programms
	cmp prog1 prog-a1
	cmp prog1 prog-so1

	cmp prog2 prog-a2
	cmp prog2 prog-so2

	cmp prog3 prog-a3
	cmp prog3 prog-so3

run_programms:	prog prog-a prog-so
	./prog 2>> trash_tmp > prog1
	./prog-a 2>> trash_tmp > prog-a1
	LD_LIBRARY_PATH=$(PWD) ./prog-so 2>> trash_tmp > prog-so1
	
	./prog parameter_1 2>> trash_tmp > prog2
	./prog-a parameter_1 2>> trash_tmp > prog-a2
	LD_LIBRARY_PATH=$(PWD) ./prog-so parameter_1 2>> trash_tmp > prog-so2
	
	./prog parameter_1 parameter_2 2>> trash_tmp > prog3
	./prog-a parameter_1 parameter_2 2>> trash_tmp > prog-a3
	LD_LIBRARY_PATH=$(PWD) ./prog-so parameter_1 parameter_2 2>> trash_tmp > prog-so3

clean:
	rm -rf $(OUT) $(FILES) $(OBJECTS) $(LIBRARIES)