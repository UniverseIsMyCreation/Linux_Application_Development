CC = gcc
FLAGS = -Wall -O0 -g
GENERATES = move *.txt *.so
PRELOAD_FLAGS = -shared -fPIC

move:	move.c
		$(CC) $(FLAGS) $< -o $@

injection_remove.so:	injection_remove.c
		$(CC) $(PRELOAD_FLAGS) $^ -o $@ -ldl

test:	move injection_remove.so
		
		chmod +x without_strace_tests.sh
		./without_strace_tests.sh

		chmod +x with_strace_tests.sh
		./with_strace_tests.sh

clean:	
		rm -rf $(GENERATES)