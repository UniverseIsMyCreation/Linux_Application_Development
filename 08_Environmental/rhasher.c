#include <stdio.h>
#include <rhash.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define LEN_SEP 10
#define LEN_DIGEST 64
#define LEN_OUTPUT 130

#include "config.h"

#ifdef WITH_READLINE
    #include <readline/readline.h>
    #include <readline/history.h>
#endif

size_t getcurrentline(char ** cur_line){
    #ifdef WITH_READLINE
	    if (*cur_line) {
		    free(*cur_line);
	    }
	    *cur_line = readline(NULL);
	    if (*cur_line == NULL) {
		    return -1;
	    }
	    return strlen(*cur_line);
    #else
	    size_t length = 0;
	    return getline(cur_line, &length, stdin);
    #endif
}

int main(int argc, char ** argv){
    char digest[LEN_DIGEST];
    char output[LEN_OUTPUT];
    char * cur_line = NULL;
    char sep[LEN_SEP] = " ";
    char * algorithm = NULL;
    char * name = NULL;
    int style;
    unsigned hash;
    int result;

    rhash_library_init(); /* initialize static data */

    for(;;){

        result = getcurrentline(&cur_line);
        
        if (result == -1){
            break;
        }

        algorithm = strtok(cur_line, sep);
        if (algorithm == NULL){
            fprintf(stderr, "Bad algorithm\n");
            continue;
        }
        name = strtok(NULL, sep);
        if (name == NULL){
            fprintf(stderr, "Bad name\n");
            continue;
        }

        if (islower(algorithm[0])){
            style = RHPR_BASE64; 
        }
        else{
            style = RHPR_HEX;
        }

        int length = strlen(algorithm);
        for (int i = 0; i < length; ++i){
            algorithm[i] = tolower(algorithm[i]);
        }

        if (!strcmp(algorithm, "md5")){
            hash = RHASH_MD5;
        }
        else if (!strcmp(algorithm, "tth")){
            hash = RHASH_TTH;
        }
        else if (!strcmp(algorithm, "sha1")){
            hash = RHASH_SHA1;
        }
        else{
            fprintf(stderr, "Bad type of algorithm\n");
            continue;
        }

        int result_of_hash;
        if (name[0] == '"'){
            result_of_hash = rhash_msg(hash, &name[1], strlen(name)-1, digest);
        }
        else{
            result_of_hash = rhash_file(hash, name, digest);
        }
        if (result_of_hash < 0){
            fprintf(stderr, "Problem with hash str or file\n");
            continue;
        }

        rhash_print_bytes(output, digest, rhash_get_digest_size(hash), (style));
        fprintf(stdout, "%s\n", output);

    }
    if (cur_line){
        free(cur_line);
    }
    return 0;

}