//
// Created by Андрей on 19.06.2022.
//
#include <iostream>
#include "overflow.h"
using namespace std;
void whole_pimple (bool pimple [][12]){
    for (int i = 0; i<12;i++){
        for (int j = 0;j<12;j++){
            pimple [i][j] = true;
        }
    }
}

void show_pimple (bool pimple [][12]){
    for (int i = 0; i<12;i++){
        for (int j = 0;j<12;j++){
          if(pimple [i][j]) {cout << "o ";}
          else {cout << "x ";}
        }
        cout << endl;
    }
}

void pop_pimple (bool pimple [][12], int x1point, int y1point, int x2point, int y2point){
    for (int i = x1point; i <= x2point;i++) {
        for (int j = y1point; j <= y2point; j++) {
           if (pimple [i][j]) {cout << "Pop\n";}
               pimple [i][j] = false;
        }
    }
}

void pimple (){
    bool pimple [12][12];

    whole_pimple (pimple);

    cout << "pimple\n";
    show_pimple (pimple);

    int number_of_bubbles = 144;
    while (number_of_bubbles >0) {

        int xFirst;
        int xSecond;
        int yFirst;
        int ySecond;
        cout << "Input two point for pop pimple\nFirst point\n";
        cout << "x:";
        cin >> xFirst;
        while (overflow()) { cin >> xFirst; }
        cout << "y:";
        cin >> yFirst;
        while (overflow()) { cin >> yFirst; }

        while (xFirst < 0 || xFirst > 11 || yFirst < 0 || yFirst > 11) {
            cout << "wrong position! input again: ";
            cout << "x:";
            cin >> xFirst;
            while (overflow()) { cin >> xFirst; }
            cout << "y:";
            cin >> yFirst;
            while (overflow()) { cin >> yFirst; }
        }

        cout << "Second point\n";
        cout << "x:";
        cin >> xSecond;
        while (overflow()) { cin >> xSecond; }
        cout << "y:";
        cin >> ySecond;
        while (overflow()) { cin >> ySecond; }
        while (xSecond < xFirst || xSecond > 11 || ySecond < yFirst || ySecond > 11) {
            cout << "wrong position! input again: ";
            cout << "x:";
            cin >> xSecond;
            while (overflow()) { cin >> xSecond; }
            cout << "y:";
            cin >> ySecond;
            while (overflow()) { cin >> ySecond; }
        }

        pop_pimple(pimple, xFirst, yFirst, xSecond, ySecond);

        number_of_bubbles = 0;
        for (int i =0; i <12;i++){
            for (int j =0; j<12; j++){
                if (pimple[i][j]){number_of_bubbles++;}
            }
        }
        show_pimple (pimple);
    }
}