#include <stdio.h>
#include <stdlib.h>

int str2int(char * string){
    int pointer = 0;
    while (string[pointer] == ' ' || string[pointer] == '\t'){
        pointer++;
    }
    int sign = 1;
    if (string[pointer] == '-'){
        sign = -1;
        pointer++;
    }
    int result = 0;
    while (string[pointer] != '\0'){
        if (string[pointer] < '0' || string[pointer] > '9'){
            if (string[pointer] == ' ' || string[pointer] == '\t'){
                while (string[pointer] == ' ' || string[pointer] == '\t'){
                    pointer++;
                }
            }
            if (string[pointer] == '\0'){
                break;
            }
            printf("error with parameters, try again\n");
            exit(1);
        }
        result = result * 10 + (string[pointer] - '0');
        pointer++;
    }
    return result*sign;
}

int main(int argc, char ** argv){
    if (argc == 1){
        printf("--HELP--\n");
        printf("\t\tUse ./out_file [n] [m] [step] to run programm\n\t\tlike in python\'s range(),\n");
        printf("\t\twhere n is start, m is end, step is distance between numbers\n");
    }
    else if (argc >= 2 && argc <= 4){
        int n,m;
        if (argc >= 3){
            n = str2int(argv[1]);
            m = str2int(argv[2]);
        }
        else{
            n = 0;
            m = str2int(argv[1]);
        }
        int step;
        if (argc == 4){
            step = str2int(argv[3]);
        }
        else{
            if (m < n){
                step = -1;
            }
            else{
                step = 1;
            }
        }
        if (m < n && step > 0){
            printf("Error in parameteres(m<n,step>0), try again\n");
            exit(1);
        }
        else if (m > n && step < 0){
            printf("Error in parameteres(m>n,step<0), try again\n");
            exit(1);
        }
        if (step > 0){
            for (int i = n; i < m; i+=step){
                printf("%d\n",i);
            }
        }
        else{
            for (int i = n; i >= m; i+=step){
                printf("%d\n",i);
            }
        }
    }
    else{
        printf("Exceed parameters, try again\n");
        exit(1);
    }
    return 0;
}