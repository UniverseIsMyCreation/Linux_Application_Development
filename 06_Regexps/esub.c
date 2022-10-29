#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 100
#define MAXGR 100


int main(int argc, char ** argv){

    if (argc < 4){
        fprintf(stderr, "Not enough parameters to run regex expression\n");
        exit(1);
    }
    else if (argc > 4){
        fprintf(stderr, "Too many parameters\n");
        exit(1);
    }

    int64_t counter;
    regex_t regex;
    regmatch_t pmatch[MAXGR];
    size_t nmatch = 100;
    int64_t regex_res;
    char * regexp = argv[1];
    char * string = argv[3];
    char * substitution = argv[2];
    char buffer[LEN];

    if (0 != (regex_res = regcomp(&regex, regexp, REG_EXTENDED))){
        regerror(regex_res, &regex, buffer, LEN);
        fprintf(stderr, "regcomp() has returned %s\n", buffer);
        regfree(&regex);
        exit(1);
    }

    regex_res = regexec(&regex, string, nmatch, pmatch, 0);
    if (REG_NOMATCH == regex_res){
        fprintf(stdout, "There are no matchings in the string\n");
        fprintf(stdout, "Result: %s\n", string);
        regfree(&regex);
        exit(1);
    }
    else if (regex_res){
        regerror(regex_res, &regex, buffer, LEN);
        fprintf(stderr, "regexec() has returned %s\n", buffer);
        regfree(&regex);
        exit(1);
    }

    counter = 0;
    int64_t backslash_found = 0;
    int64_t sub_begin = pmatch[0].rm_so;
    int64_t sub_end = pmatch[0].rm_eo;
    size_t length = 0;
    while (pmatch[counter].rm_so != -1){
        length += (pmatch[counter].rm_eo - pmatch[counter].rm_so);
        counter++;
    }
    char * sub_string = (char *)malloc(sizeof(char)*(length+strlen(string)));
    if (sub_string == NULL){
        fprintf(stderr, "Memory allocation error\n");
        regfree(&regex);
        exit(1);
    }
    counter = 0;
    while (counter < sub_begin){
        sub_string[counter] = string[counter];
        counter++;
    }
    int64_t sub_string_counter = counter;
    counter = 0;
    while (substitution[counter] != '\0'){
        if (substitution[counter] == '\\' && !backslash_found){
            backslash_found = 1;
        }
        else if (backslash_found){
            backslash_found = 0;
            char symbol = '\0';
            switch (substitution[counter]){
                case '\\':
                    symbol = '\\';
                    break;
                case 'n':
                    symbol = '\n';
                    break;
                case 't':
                    symbol = '\t';
                    break;
                case 'b':
                    symbol = '\b';
                    break;
                case 'r':
                    symbol = '\r';
                    break;
            }
            if (symbol == '\0'){
                if (isdigit(substitution[counter])){
                    int64_t reference = substitution[counter] - '0';
                    if (reference >= MAXGR || !reference || pmatch[reference].rm_so == -1){
                        fprintf(stderr, "Undefined reference error\n");
                        regfree(&regex);
                        free(sub_string);
                        exit(1);
                    }
                    else{
                        int64_t new_sub_begin = pmatch[reference].rm_so;
                        int64_t new_sub_end = pmatch[reference].rm_eo;
                        int64_t new_counter = new_sub_begin;
                        while (new_counter < new_sub_end){
                            sub_string[sub_string_counter] = string[new_counter];
                            sub_string_counter++;
                            new_counter++;
                        }
                    }
                }
                else{
                    fprintf(stderr, "Substitution backslash error\n");
                    regfree(&regex);
                    free(sub_string);
                    exit(1);
                }
            }
            else{
                sub_string[sub_string_counter] = symbol;
                sub_string_counter++;
            }
        }
        else{
            sub_string[sub_string_counter] = substitution[counter];
            sub_string_counter++;
        }
        counter++;
    }
    if (backslash_found){
        fprintf(stderr, "Exceed backslash error\n");
        regfree(&regex);
        free(sub_string);
        exit(1);
    }
    counter = sub_end;
    while (string[counter] != '\0'){
        sub_string[sub_string_counter] = string[counter];
        counter++;
        sub_string_counter++;
    }

    fprintf(stdout, "%s\n", sub_string);
    regfree(&regex);
    free(sub_string);
    return 0;
}