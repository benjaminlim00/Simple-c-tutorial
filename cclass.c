#include "cclass.h"

/*
create a data structure to hold a bunch of arguments, in a struct you cannot have methods.
 */
typedef struct arguments_data_structure{        //this is the name of the struct, by right same as below. but useless here. USED for pointer purpose.
    int arg1;
    int arg2;
    float arg3;
    //add your own arguments here
}AS;                                    //this is data type. so like class AS(). the useful one

typedef struct demo {
    int x;
}AD;

//struct in a struct example.
typedef struct arguments_data_structure_demo{
    int arg1;
    int arg2;
    float arg3;
    //add your own arguments here

    //struct arguments_data_structure_demo my_children[2]; cannot store ownself type of struct, but can store other struct
    AD mychildren[2];

    struct arguments_data_structure_demo* my_children_pointers[2];  //can store address of own type of struct
    
}ASdemo;


void struct_example(void) {
    //initialize memory location, hasn't set any values within it yet
    ASdemo AS_one;
    AS_one.arg1 = 1;
    //....

    ASdemo AS_two;
    AS_two.arg1 = 2;
    ASdemo AS_three;
    AS_three.arg1 = 3;

    AD AD_one;
    AD_one.x = 0;
    AD AD_two;
    AD_two.x = 0;

    AS_one.my_children_pointers[0] = &AS_two;
    AS_one.my_children_pointers[1] = &AS_three;
    printf("the first argument of AS_two is %d, the first argument of AS_three is %d\n",
    AS_one.my_children_pointers[0]->arg1,
    AS_one.my_children_pointers[1]->arg1);

    AS_one.mychildren[0] = AD_one;
    AS_one.mychildren[1] = AD_two;
    printf("the x val of AD_one is %d, the x val of AD_two is %d\n",
    AS_one.my_children_pointers[0].x,
    AS_one.my_children_pointers[1].x);



    
}



void* pointer_example(void* args) {      //take pointer of any type.

    // int* args_input_address = (int*) args;  //we typecast the void* back to int*
    // int arg_input_value = *args_input_address;  // here we retreive the value from a pointer
    // printf("The input argument is %d\n", arg_input_value);

    AS* args_input_address = (AS*) args;  //we typecast the void* back to AS*
    AS args_input_value = *args_input_address;  // here we retreive the value from a pointer
    printf("The input argument (struct type) has arg1: %d, arg2: %d, arg3: %f, \n", args_input_value.arg1, args_input_value.arg2, args_input_value.arg3);
    printf("METHOD2: The input argument (struct type) has arg1: %d, arg2: %d, arg3: %f, \n", args_input_address->arg1, args_input_address->arg2, args_input_address->arg3);
    //the -> notation only works for struct. retrieve args from a struct pointer.
    
    int number = 5;
    printf("The number is %d \n", number);

    int* number_address = &number;  //& means i take the add of number and save in num_address
    printf("The address of number is %p \n", number_address);

    float number_float = 2.5;
    float* number_float_address = &number_float;
    printf("The address of number_float is %p \n", number_float_address);

    //we do pointer to pointer here
    float** the_addr_of_number_float_addr = &number_float_address;
    printf("number_float_address is stored at %p \n", the_addr_of_number_float_addr);
    printf("The content that the_addr_of_number_float_addr points to is %p\n", *the_addr_of_number_float_addr);


    args_input_address->arg1 = 15; //we change arg1 to value 15.
    return((void*) args_input_address);


    //return((void*) number_address);
    //it is dangerous to return the addr of local variables, because local vars are supposed to be destroyed when the function exits.
    //arg is the only non local var. for python java, the arg is actually a copy of the original arg, not the same.
}

void array_example(void) {
    int my_array[10];
    char my_chararray[BUFFERSIZE];

    AS my_ASarray[10];

    for (int i=0; i<10; i++) {
        my_array[i] = i;
    }

    for (int i=0; i<10; i++) {
        printf("element %d is %d\n", i, my_array[i]);
    }


    //filling array values using address
    for (int i=0; i<10; i++) {
        *(my_array+i) = 100;
    }

    for (int i=0; i<10; i++) {
        printf("element %d is now %d\n", i, my_array[i]);
    }

    printf("my array starts at address %p\n", my_array);

    //malloc lesson
    int* myMallocArray = malloc(10*sizeof(int)); //can hold 10 ints. (malloc take in bytes so must multiply)
    for (int i=0; i<10; i++) {
        myMallocArray[i] = i;
    }
    for (int i=0; i<10; i++) {
        printf("element %d of myMallocArray is %d\n", i, myMallocArray[i]);
    }

}


int main() {

    array_example();
//     printf("Hello\n");

//     int x = 10;
//     int* x_addr = &x;


//     AS argument;
//     argument.arg1 = 1;
//     argument.arg2 = 2;
//     argument.arg3 = 100.1;

//     AS* argument_pointer = &argument;
    
//     //example last

//     void* return_value_of_voidstar = pointer_example((void*) argument_pointer);
//     AS* return_value_of_ASstar = (AS*) return_value_of_voidstar;
//     printf("The arg1 that was changed is now %d\n", return_value_of_ASstar->arg1);


//     //pointer_example((void*) x_addr); //we typecast x_addr from int* to void*

//     /*
//     void* return_value_of_voidstar = pointer_example((void*) argument_pointer);

//     int* return_value_of_intstar = (int*) return_value_of_voidstar;
//     printf("The return value of the void star example is %d\n", *return_value_of_intstar);
    
//     */
    

    return (0);
}

