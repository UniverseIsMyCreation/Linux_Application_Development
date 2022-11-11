CFLAGS = -Wall -O0 -g

bin_PROGRAMS=rhasher
rhasher_SOURCES=rhasher.c

GENERATES = *.in configure depcomp *.status *.h stamp-h1 missing *.log compile install-sh *.cache *.m4 Makefile configure~ rhasher *.o

test:
		chmod +x simple_test.sh
		./simple_test.sh
clean:
		rm -rf $(GENERATES)