#include <stdio.h>
#include <string.h>

// set crud functions
void create();
void read();
void update();
void destroy();

// set array as tinydb
char *crudArray[][255] = {};

void main(){

    *crudArray[0] = "teste";

    printf("%s \n", *crudArray[0]);
}

void create(){
    
}