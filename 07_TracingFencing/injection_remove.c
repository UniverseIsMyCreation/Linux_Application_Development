#define _GNU_SOURCE
#include <dlfcn.h>
#include <string.h>
#include <stdlib.h>
#define FOUND 1

typedef int (*orig_f_type)(const char * file_path);

int remove(const char * file_path){
    if (strstr(file_path, "PROTECT") == NULL){
        orig_f_type initial_remove;
        initial_remove = (orig_f_type) dlsym(RTLD_NEXT, "remove");
        return initial_remove(file_path);
    }
    else{
        return FOUND;
    }
}