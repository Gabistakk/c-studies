#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// set crud functions
void create(char *value);
void read(int position);
void update(char *value, int position);
void destroy(int position);


// set ultility function
int checkIfPositionIsValid(int position);

// set an array of pointers as tinydb
#define MAX_ENTRIES 100
char *crudArray[MAX_ENTRIES] = {};
int count = 0;

void main(){

    destroy(2);

   for(int i = 0; i < count; i++) read(i);
}

void create(char *value){
    crudArray[count++] = value;
}

void read(int position){
    if(checkIfPositionIsValid(position) && crudArray[position] != NULL) printf("%s \n", crudArray[position]);
}

void update(char *value, int position){
    if(checkIfPositionIsValid(position)) crudArray[position] = value;
}

void destroy(int position){
    if(checkIfPositionIsValid(position)){
        crudArray[position] = NULL;

        if(position == count - 1){
            count--;
            return;
        }

        for(int i = count - 1; i >= position; i--){
            
        }
    }
}

int checkIfPositionIsValid(int position){
    if(position >= count){
        printf("Invalid Position. \n");
        return 0;
    }
    return 1;
}