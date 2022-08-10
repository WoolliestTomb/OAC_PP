#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    printf("Hello World\n");

    printf("%s\n", argv[1]);

    if(strcmp(argv[1], "-p") == 0){
        printf("foi");
    }
    

    return 0;
}