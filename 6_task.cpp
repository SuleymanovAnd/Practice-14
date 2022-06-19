//
// Created by Андрей on 19.06.2022.
//
#include <iostream>

void snake (){
    int digits [5][5];
    int number = 0;

    for (int i = 0; i < 5; ++i) {
        int n = i%2;
        for (int j = 0; j < 5; ++j) {
            digits[i][(n*2 - 1)*(n*4 - j)] = number;
            number += 1;
        }
    }

    for (int i = 0; i <5;i++){
        for (int j =0; j<5;j++){
            std::cout << digits [i][j]<< " ";
        }
        std::cout << std::endl;
    }
}

//   0 -1(0 - j) ||  2 - 1 (4 - j)

