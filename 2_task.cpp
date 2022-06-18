//
// Created by Андрей on 18.06.2022.
//
#include <iostream>
#include "overflow.h"
using namespace std;
void Input_place (bool places [][3],char field [][3],char gamer);

void tic_tac_toe (){
    char field [3][3];
    bool places [3][3];

    for (int i = 0;i<3;i++){
        for (int j =0;j<3;j++){
            field [i][j] = ' ';
            places [i][j] = false;
        }
    }



    bool anyoneWin = false;
    char gamer_name = 'X';
    char player_win = ' ';
    int move_number = 0;
    while (!anyoneWin && move_number<9){

        if (gamer_name == 'X'){
            Input_place (places,field,gamer_name);
                gamer_name = 'O';
        } else {
            Input_place (places,field,gamer_name);
            gamer_name = 'X';
        }
        move_number ++;

        for (int i =0; i<3 && !anyoneWin;i++){
           char a = field[i][0]; // почему-то если вставлять ссылки на массив сразу,
           char b = field[i][1]; // без этих переменных условия работают не корректно!
           char c = field[i][2];
            if ( a == b &&  a == c  &&  a != ' ') {anyoneWin = true; player_win = field [i][0];}
           char d = field[0][i];
           char e = field[1][i];
           char f = field[2][i];
            if ( d == e && d == f && d != ' ') {anyoneWin = true;player_win = field [0][i];}
        }

        for (int i =0; i<3; i++){
            for (int j =0; j<3;j++){
                if (j == 1){cout <<" "<< field [i][j]<< " ";}
                else  { cout <<"| "<< field [i][j]<< " |"; }
            }
            cout<<endl;
        }
        cout << endl;
    }
    if (anyoneWin) {cout << "Player playing '"<<player_win<<"' win!!!";}
    else {cout << "Draw";}
}

void Input_place (bool places [][3],char field [][3],char gamer){
    int line = 0;
    int column = 0;

    if (gamer == 'X'){
        cout << "The turn of the player playing 'X'\nInput coordinate of field:";
    } else {
        cout << "The turn of the player playing 'O'\nInput coordinate of field:";
    }

    cin >> line>>column;
    while (overflow ()) {cin >> line>>column;}

    if (line >2 || line <0 || column >2|| column <0 ){
        cout << "Wrong position. This position is outside the playing field.\nInput again : ";
        cin >> line >>column;
        while (overflow ()) {cin >> line>>column;}
    }
    if (places [line][column]){
        cout << "Wrong position. this position has already been taken.\nInput again : ";
        cin >> line >>column;
        while (overflow ()) {cin >> line>>column;}
    }
    if (gamer == 'X'){field [line][column] = 'X';}
    else {field [line][column] = 'O';}
    places [line][column] = true;
}