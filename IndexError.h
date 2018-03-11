//
// Created by Drasik on 3/11/2018.
//

#ifndef SDIZO_PROJ_1_INDEXERROR_H
#define SDIZO_PROJ_1_INDEXERROR_H

#include <iostream>

using namespace std;

struct IndexError : public exception {
    const char *what() const throw() override {
        return "Index out of range";
    }
};

#endif //SDIZO_PROJ_1_INDEXERROR_H
