//
// Created by Drasik on 3/13/2018.
//


template<typename T,int N>
int getArraySize(T (&input_array)[N]){
    int input_size = sizeof(input_array) / sizeof(input_array[0]);;
    return input_size;
};