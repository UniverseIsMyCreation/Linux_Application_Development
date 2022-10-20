GENERATES = range *_output_* *.output
CC = gcc
FLAGS = -O0 -g

all:	range

range:	range.c
		$(CC) $(FLAGS) $< -o $@

test:	range
		chmod +x concat.sh
		gdb --batch --quiet --command=gdb_run1 --args ./range | grep '^@@@' | cut -c 9- | tr -d '"' > run1_output_initial
		./concat.sh run1_output_initial run1_output_concat
		gdb --batch --quiet --command=gdb_run2 --args ./range | grep '^@@@' | cut -c 9- | tr -d '"' > run2_output_initial
		./concat.sh run2_output_initial run2_output_concat
		cmp target1 run1_output_concat
		cmp target2 run2_output_concat

clean:	
		rm -rf $(GENERATES)