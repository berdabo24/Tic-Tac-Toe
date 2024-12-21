#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>

using namespace std;

//GLOBAL VARIABLES
const int SLOTSIZE = 9;
char SLOT[SLOTSIZE]; // 9 slots including 0
int ACTIVESLOT[SLOTSIZE] = {0};

void GridRows(char a,char b,char c){
    //Row 1

    for (int row = 1; row <= 3; row++){
        cout << " ";
        for (int column = 1; column < 10; column++){


            // Middle row holes
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

    if (ACTIVESLOT[input] == 0){
        SLOT[input] = turn;
        ACTIVESLOT[input] = 1;
        return true;
    }
    else
        return false;

}

void DrawGrid(){
    GridRows(SLOT[1],SLOT[2],SLOT[3]);
    lineSeg();
    GridRows(SLOT[4],SLOT[5],SLOT[6]);
    lineSeg();
    GridRows(SLOT[7],SLOT[8],SLOT[9]);
}

int main(){

    for (int i = 1; i <= SLOTSIZE; i++){
        SLOT[i] = ' ';
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
         if (i == 9){
            cout << "Press enter to continue: ";
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

