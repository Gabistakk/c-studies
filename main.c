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
    //create examples
    create("test1");
    create("test2");
    create("test3");
    create("test4");
    create("test5");

    // final loop to exhibit all of the db content
   for(int i = 0; i < count; i++) read(i);
}

void create(char *value){
    // create the element as it increases the counter of elements.
    crudArray[count++] = value;
}

void read(int position){
    // prints the element.
    if(checkIfPositionIsValid(position)) printf("%s \n", crudArray[position]);
}

void update(char *value, int position){
    // pretty self explanatory, but we substitute the data of the element with the target value.
    if(checkIfPositionIsValid(position)) crudArray[position] = value;
}

void destroy(int position){
    if(checkIfPositionIsValid(position)){
        crudArray[position] = NULL;
        
        // if the destroy target is the last element in the array, it simply removes one from the counter of elements.
        if(position == count - 1){
            count--;
            return;
        }

        // if it isn't, then we shift all of the elements after the target to the left, filling it's gap.
        for(int i = position; i <= count; i++){
            crudArray[i] = crudArray[i + 1];
        }
        // then of course mark it as one less element.
        count--;
    }
}

int checkIfPositionIsValid(int position){
    if(position >= count){
        printf("Invalid Position. \n");
        return 0;
    }
    return 1;
}