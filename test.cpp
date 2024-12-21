#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>

using namespace std;

//GLOBAL VARIABLES
const int SLOTSIZE = 9;
char DRAW_SLOT[SLOTSIZE]; // 9 slots including 0
int SLOT_X[SLOTSIZE] = {0};
int SLOT_O[SLOTSIZE] = {0};

void GridRows(char a,char b,char c){
    //Row 1

    for (int row = 1; row <= 3; row++){
        cout << " ";
        for (int column = 1; column < 10; column++){


            // row middle holes
            if (row == 2 && column == 2){
                cout << " " << a;
            }
            else if (row == 2 && column == 5){
                cout << " " << b;
            }
            else if (row == 2 && column == 8){
                cout << " " << c;
            }
            else{
                cout << " " << " ";
            }

            //Top and bottom
            if (column == 3 || column == 6)
            {
                cout << " " << "|";
            }

        }
        cout << endl;
    }
}

void lineSeg(){

    for (int i = 0; i < 25; i++){
        if (i == 8 || i == 16)
            cout << "+";
        else
             cout << "-";
    }
    cout << endl;

}

bool isMoveValid(int input, char turn){

    if (SLOT_X[input] == 0 && SLOT_O[input] != 1 && turn == 'x'){
        DRAW_SLOT[input] = turn;
        SLOT_X[input] = 1;
        return true;
    }
    else if (SLOT_O[input] == 0 && SLOT_X[input] != 1 && turn == 'o'){
        DRAW_SLOT[input] = turn;
        SLOT_O[input] = 1;
        return true;
    }
    else
        return false;

}

void DrawGrid(){
    GridRows(DRAW_SLOT[1],DRAW_SLOT[2],DRAW_SLOT[3]);
    lineSeg();
    GridRows(DRAW_SLOT[4],DRAW_SLOT[5],DRAW_SLOT[6]);
    lineSeg();
    GridRows(DRAW_SLOT[7],DRAW_SLOT[8],DRAW_SLOT[9]);
}

bool CheckWinCond(int ary[]){

    if (
        /*
        1 0 0
        0 1 0
        0 0 1
        */
        (ary[1] == 1 && ary[5] == 1 && ary[9] == 1) ||
        /*
        0 0 1
        0 1 0
        1 0 0
        */
        (ary[3] == 1 && ary[5] == 1 && ary[7] == 1) ||
        /*
        1 1 1
        0 0 0
        0 0 0
        */
        (ary[1] == 1 && ary[2] == 1 && ary[3] == 1) ||
        /*
        0 0 0
        1 1 1
        0 0 0
        */
        (ary[4] == 1 && ary[5] == 1 && ary[6] == 1) ||
        /*
        0 0 0
        0 0 0
        1 1 1
        */
        (ary[7] == 1 && ary[8] == 1 && ary[9] == 1) ||
        /*
        1 0 0
        1 0 0
        1 0 0
        */
        (ary[1] == 1 && ary[4] == 1 && ary[7] == 1) ||
        /*
        0 1 0
        0 1 0
        0 1 0
        */
        (ary[2] == 1 && ary[5] == 1 && ary[8] == 1) ||
        /*
        0 0 1
        0 0 1
        0 0 1
        */
        (ary[3] == 1 && ary[6] == 1 && ary[9] == 1)
        ){
            return true;
        }
    else
        return false;

}

int main(){

    for (int i = 1; i <= SLOTSIZE; i++){
        DRAW_SLOT[i] = ' ';
    }

    bool gamestate = true;
    int i = 0;
    int PlayerTurn = 1;
    int select;


    //Main game loop
    do{

        // Draws grid and elements
        DrawGrid();

        cout << endl;

        //Ask for user input


        if (i == 9 || CheckWinCond(SLOT_X) == true || CheckWinCond(SLOT_O) == true){
            if (CheckWinCond(SLOT_X)){
                cout << "X won!";
            }
            else if (CheckWinCond(SLOT_O)){
                cout << "O won!";
            }
            else{
                cout << "Draw!";
            }
            getch();

            gamestate = false;
        }
        else if (PlayerTurn == 1){

            do{
                cout << "Player X's turn (Select 1 - 9): ";
                cin >> select;

                if (isMoveValid(select, 'x')){ // Checks if slot is occupied
                    break;
                }
                else
                    system("cls");
                    DrawGrid();
                    cout << "Slot occupied" << endl;


            }while(true);

            PlayerTurn = 2;
        }
        else{

            do{
                cout << "Player O's turn (Select 1 - 9): ";
                cin >> select;

                if (isMoveValid(select, 'o')){
                    break;
                }
                else
                    system("cls");
                    DrawGrid();
                    cout << "Slot occupied" << endl;


            }while(true);

            PlayerTurn = 1;
        }

        system("cls");

        i++;




    }while(gamestate == true);

    return 0;

}

