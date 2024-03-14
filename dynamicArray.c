#include <stdio.h>
#include <stdlib.h>


typedef struct{
    float *items;
    size_t capacity;
    size_t count;
} DynamicArray;

#define dynamicArray_append(array, value)\
    do{\
        if(array.count >= array.capacity){\
            if(array.capacity == 0) array.capacity = 256;\
            else array.capacity *= 2;\
            array.items = realloc(array.items, array.capacity*sizeof(*array.items));\
        }\
        array.items[array.count] = value;\
        array.count++;\
    } while(0)

int main(void){

    DynamicArray da = {0};

    for (int i = 0; i < 10; i++) dynamicArray_append(da, i);
    for (size_t i = 0; i < da.count; i++) printf("%f \n", da.items[i]);
}