//
// Created by Андрей on 18.06.2022.
//
#include <iostream>
using namespace std;

void banquet (){
    int tableware [12][4]= {{1,1,1,1}, //vip
                            {1,1,1,1}, //vip
                            {1,1,1,0},
                            {1,1,1,0},
                            {1,1,1,0},
                            {1,1,1,0}, //end of row
                            {1,1,1,0},
                            {1,1,1,0},
                            {1,1,1,0},
                            {1,1,1,0},
                            {1,1,1,0},
                            {1,1,1,0}} ;// количество приборов

    int dinnerware [12][3]  = {{1,1,1}, //vip
                               {1,1,1}, //vip
                               {1,1,0},
                               {1,1,0},
                               {1,1,0},
                               {1,1,0}, //end of row
                               {1,1,0},
                               {1,1,0},
                               {1,1,0},
                               {1,1,0},
                               {1,1,0},
                               {1,1,0}};// количество посуды

    int chairs [12]  = {1,1,1,1,1,1,1,1,1,1,1,1,};//количество стульев

    chairs [4] = 2; // добавляем стул на 5ое место 1ого ряда.

   /* for (int i = 0; i <3;i++){ // добавляем по тарелке и прибору на 5е место для ребенка
        tableware [4][i] ++;
        if (i<2) dinnerware [4][i] ++;
    }*/

     //украли ложку 3 место 2 ряд
     tableware [8][1] --;

    // Vip поделился ложкой
    tableware [1][1] --;
    tableware [8][1] ++;

    //официант забрал десертную тарелку у этого vip
    dinnerware [1][2] --;
}