//
// Created by Oleksii Pilkevych on 3/13/2018.
//
#include "random"
#include "chrono"

using namespace std;

template<typename T,int N>
int getArraySize(T (&input_array)[N]){
    int input_size = sizeof(input_array) / sizeof(input_array[0]);;
    return input_size;
};

template<class T, typename ReturnType, typename... Args>
long long int measure(T *my_list, ReturnType (T::*func)(Args...), Args... args) {
    chrono::high_resolution_clock::time_point begin = chrono::high_resolution_clock::now();
    (my_list->*func)(args...);
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    long long int result = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();
    cout << result << "\t";
    return result;
}

int* fillWithRandomValues(int start_array[], int array_size, int bottom_limit, int top_limit){
    default_random_engine generator;
    uniform_int_distribution<int> distribution(bottom_limit,top_limit);
    for (int i = 0; i < array_size; i++)
        start_array[i] = distribution(generator);
    return start_array;
}

pair<int *, int> parse_file(string &file_name, int *array) {
    int size;
    ifstream infile(file_name);

    infile >> size;

    array = new int[size];
    int i = 0, value;
    while (infile >> value) {
        array[i] = value;
        i++;
    }

    infile.close();
    return make_pair(array, size);
}
