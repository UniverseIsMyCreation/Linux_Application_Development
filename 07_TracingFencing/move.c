#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define incorrect_parameters_amount 1
#define open_input_file_error 2
#define open_out_file_error 3
#define read_write_error 4
#define deleting_error 5


int main(int argc, char ** argv){
    if (argc != 3){
        fprintf(stderr, "There aren't exactly 2 parameters\n");
        exit(incorrect_parameters_amount);
    }

    if (!strcmp(argv[1], argv[2])){
        return 0;
    }

    int fin = open(argv[1], O_RDONLY, 0);
    if (fin == -1){
        perror("Problem fopen() with infile: ");
        exit(open_input_file_error);
    }
    int fout = open(argv[2], O_WRONLY, 0);
    if (fout == -1){
        perror("Problem fopen() with outfile: ");
        close(fin);
        exit(open_out_file_error);
    }

    char symbol;
    int result;
    size_t amount = sizeof(char);
    while (1){
        result = read(fin,&symbol,amount);
        if (result == 0){
            break;
        }
        else if (result == -1){
            fprintf(stderr, "Problem with read or write\n");
            close(fin);
            remove(argv[2]);
            exit(read_write_error);
        }
        result = write(fout,&symbol,amount);
        if (result == -1){
            fprintf(stderr, "Problem with read or write\n");
            close(fin);
            remove(argv[2]);
            exit(read_write_error);
        }
    }

    close(fout);

    if (remove(argv[1])){
        fprintf(stderr, "Problem with deleting infile\n");
        remove(argv[2]);
        exit(deleting_error);
    }

    return 0;
}