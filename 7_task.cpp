//
// Created by Андрей on 19.06.2022.
//
#include <iostream>

void pre_minecraft (){

    int land [5][5];
    int world [5][5][10];

    std::cout << "input matrix of heights:\n";
    for(int i =0; i<5;i++){
        for (int j =0;j<5;j++){
            std::cin>> land [i][j];
            while (land [i][j]>10 || land[i][j]<0){
                std::cout <<"wrong height. input again:";
                std::cin>> land [i][j];
            }
        }
    }

    for(int i =0; i<5;i++){
        for (int j =0;j<5;j++){
            for (int k = 0; k<10;k++){
               if (((land [i][j])) >= k) {world [i][j][k] = 1;}
               else {world [i][j][k] = 0;}
            }
        }
    }

    int slice;
    std::cout <<  "input slice: ";
    std::cin >> slice;
    while (slice <0 || slice >9) {std::cout << "slice out in range world height! Input again:"; std::cin >> slice;}

    for (int i = 0;i<5;i++){
        for(int j = 0;j<5;j++) {
            std::cout << world [i][j][slice] << " ";
        }
        std::cout << std::endl;
    }
}