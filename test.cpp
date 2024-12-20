#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>

using namespace std;

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

            if (row == 2 && column == 2){

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

int main(){

    int SLOTSIZE = 9;
    char SLOT[SLOTSIZE - 1]; // 9 slots including 0

    for (int i = 0; i < SLOTSIZE; i++){
        SLOT[i] = ' ';
    }

    bool gamestate = true;
    int i = 0;
    int PlayerTurn = 1;
    int select;

    //Main game loop
    do{

        // Draws grid and elements
        GridRows(SLOT[0],SLOT[1],SLOT[2]);
        lineSeg();
        GridRows(SLOT[3],SLOT[4],SLOT[5]);
        lineSeg();
        GridRows(SLOT[6],SLOT[7],SLOT[8]);


        cout << endl;

        //Ask for user input
         if (i == 9){
            cout << "Press enter to continue: ";
            getch();

            gamestate = false;
        }
        else if (PlayerTurn == 1){

            cout << "Player X's turn (Select 1 - 9): ";
            cin >> select;

            SLOT[select - 1] = 'x';

            PlayerTurn = 2;
        }
        else{

            cout << "Player O's turn (Select 1 - 9): ";
            cin >> select;

            SLOT[select - 1] = 'o';

            PlayerTurn = 1;
        }

        system("cls");

        i++;

    }while(gamestate == true);

    return 0;

}

