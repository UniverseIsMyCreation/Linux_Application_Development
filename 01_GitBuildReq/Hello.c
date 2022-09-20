#include <stdio.h>
#include <stdlib.h>
#define LEN 100

int main(){
	char * str;
	str = (char *)malloc(LEN * sizeof(char));
	if (str == NULL){
		printf("Allocation error memory!!!!!\n");
		return 1;
	}	
	scanf("%s",str);
	printf("Hello, %s!\n",str);
	free(str);
	return 0;
}
