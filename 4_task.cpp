//
// Created by Андрей on 18.06.2022.
//
#include <iostream>
#include "overflow.h"


void matrix_vector_multiplication (){
    float A [4][4];
    std:: cout << "Matrix A:\n";
    for (int i = 0; i <4;i++){
        for (int j =0; j<4;j++){
            std::cout << "input element " << i <<":"<< j <<" :";
            std::cin >> A [i][j];
            while (overflow ()){ std::cin >> A [i][j];}
        }
    }

    std:: cout << "Vector B:\n";
    float B [4];
    for (int i =0; i<4;i++){
        std::cout << "input element " << i <<" :";
        std::cin >> B[i];
        while (overflow()){ std::cin >> B[i];}
    }

    float C [4];

    for(int i=0;i<4;i++){
        float sum = 0;
        for (int j=0;j<4;j++){
            sum += A[i][j] * B[j];
        }
        C[i] = sum;
    }

    std::cout << "Multiplication matrix A on vector B = vector: \n";
    for(int i =0; i<4;i++){
        std::cout << C[i]<< "\n";
    }

}