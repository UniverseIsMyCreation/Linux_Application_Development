GENERATES = esub 
CFLAGS = -Wall -O0 -g
CC = gcc


esub:	esub.c
		$(CC) $(CFLAGS) $< -o $@

test:	check_regex.sh
		chmod +x $<
		./$<

clean:
		rm -rf $(GENERATES)

see:	check_regex.sh
		cat check_regex.sh