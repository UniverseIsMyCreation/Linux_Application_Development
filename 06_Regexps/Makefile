GENERATES = esub *.txt 
CFLAGS = -Wall -O0 -g 
CC = gcc


esub:	esub.c
		$(CC) $(CFLAGS) $< -o $@

test:	esub
		echo '123456' | sed -E 's/[1-2][1-2]/a\\b/' >> regex_initial_result.txt
		./esub '[1-2][1-2]' 'a\\b' '123456' >> prog_result.txt

		echo '123a456abc' | sed -E 's/([a-z])+/here/' >> regex_initial_result.txt
		./esub '([a-z])+' 'here' '123a456abc' >> prog_result.txt

		echo 'aaabbb' | sed -E 's/(a*(b*))/\2\1/' >> regex_initial_result.txt
		./esub '(a*(b*))' '\2\1' 'aaabbb' >> prog_result.txt

		echo '123a456b789' | sed -E 's/([0-9]*.[0-9]*)([0-9]*.[0-9]*)/\2<->\1/' >> regex_initial_result.txt
		./esub '([0-9]*.[0-9]*)([0-9]*.[0-9]*)' '\2<->\1' '123a456b789' >> prog_result.txt

		echo 'abc123abc' | sed -E 's/^([a-z]{3})/.../' >> regex_initial_result.txt
		./esub '^([a-z]{3})' '...' 'abc123abc' >> prog_result.txt

		./esub '[1-2][1-2]' 'a\\\v' '123456' 2>> test_with_error.txt

		./esub '[1-2][1-2]' 'a\3\t' '123456' 2>> test_with_error.txt

		./esub '[1-2][1-2]' 'a\\\' '123456' 2>> test_with_error.txt

		cat regex_initial_result.txt
		cat prog_result.txt
		cmp regex_initial_result.txt prog_result.txt
		cat test_with_error.txt

clean:
		rm -rf $(GENERATES)