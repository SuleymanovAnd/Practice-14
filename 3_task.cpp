//
// Created by Андрей on 18.06.2022.
//
#include <iostream>
#include "overflow.h"

void input_matrix (int matrix [][4]){
    for (int i = 0; i <4;i++){
        for (int j =0; j<4;j++){
            std::cout << "input element " << i <<":"<< j <<" :";
            std::cin >> matrix [i][j];
            while (overflow ()){ std::cin >> matrix [i][j];}
        }
    }
}
void output_matrix (int matrix [][4]){
    for (int i = 0; i <4;i++){
        for (int j =0; j<4;j++){
            std::cout << matrix [i][j]<< " ";
        }
        std::cout << std::endl;
    }
}
bool matrix_equal (int A [4][4],int B [4][4]){
    bool matrix_is_equal = true;

    for (int i =0; i<4 && matrix_is_equal;i++){
        for (int j =0;j<4 && matrix_is_equal;j++){
            if (A[i][j] != B[i][j]){matrix_is_equal = false;}
        }
    }
    return matrix_is_equal;
};
void diagonal_matrix (int A [][4]){
    for (int i =0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i != j) {A[i][j] = 0;}
        }
    }
}

void matrix (){
    int A [4][4];
    int B [4][4];

    std::cout<< "MATRIX A\n";
    input_matrix (A);
    std::cout<< "MATRIX B\n";
    input_matrix (B);


    if (matrix_equal(A,B)) {
        std::cout << "Matrix A equal matrix B!\n";
        diagonal_matrix (A);

        std::cout << "Diagonal Matrix A:\n";
        output_matrix(A);
    }else {
        std::cout << "Matrix A not equal matrix B!";
    }
}