#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>

using namespace std;

//GLOBAL VARIABLES
const int SLOTSIZE = 9, PLAYERS = 2;
char DRAW_SLOT[SLOTSIZE]; // 9 slots including 0
int SLOT_X[SLOTSIZE] = {0};
int SLOT_O[SLOTSIZE] = {0};
string username[PLAYERS];
char rematch;


void Header(string username[], string symbol[]){
    cout<<"+----------------------------------+\n";
    cout<<" \t     Tic-Tac-Toe\n";
    cout<<"+----------------------------------+\n\n";
    cout<<" "<<username[0]<<" {"<<symbol[0]<<"}"<<"\t\t"<<username[1]<<" {"<<symbol[1]<<"}"<<endl<<endl;
}

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

    cout<<"+-------------------------------------------------+\n";
    cout<<" Hello, user! Welcome to >>>Tic-Tac-Toe<<< ! OvO\n";

    int p=0;
    char confirm;
    while(p<PLAYERS){
        cout<<"+-------------------------------------------------+\n";
        cout<<"\n What's Player "<<p+1<<"'s name? \n ";
        getline(cin, username[p]);
        cout<<"\n+-------------------------------------------------+\n\n";
        cout<<" Player "<<p+1<<"'s name is "<<username[p]<<"? (Y/N)\n ";
        cin>>confirm;
        cin.ignore();
        if ((confirm == 'Y')||(confirm == 'y')){
            p++;
        }
        else if ((confirm == 'N')||(confirm == 'n')){}
        else{
            while ((confirm != 'Y')&&(confirm != 'y')&&(confirm != 'N')&&(confirm != 'n')){
                cout<<"Invalid input. Please try again. ;-;";
                cout<<" Your name is "<<username[p]<<"? (Y/N)\n ";
                cin>>confirm;
            }
            if ((confirm == 'Y')||(confirm == 'y')){
                p++;
            }
            else if ((confirm == 'N')||(confirm == 'n')){}
        }
    }

    do{
        system("cls");
        string symbol[PLAYERS];


        int randomNum = rand() % 2; // X(1)/O(0) for Player 1
        if (randomNum==1){
            symbol[0] = 'X'; //Player 1: X
        }
        else if (randomNum==0){
            symbol[0] = 'O'; //Player 1: O
        }
        if (1-randomNum==1){
            symbol[1] = 'X'; //Player 2: X
        }
        else if (1-randomNum==0){
            symbol[1] = 'O'; //Player 2: O
        }


    for (int i = 1; i <= SLOTSIZE; i++){
        DRAW_SLOT[i] = ' ';
    }

    bool gamestate = true;
    int i = 0;
    int PlayerTurn = 1;
    int select;


    //Main game loop
    do{

        Header(username,symbol); //Display title and players

        // Draws grid and elements
        DrawGrid();

        cout << endl;

        //Ask for user input


        if (i == 9 || CheckWinCond(SLOT_X) == true || CheckWinCond(SLOT_O) == true){
            if (CheckWinCond(SLOT_X)){
                cout<<"\n+----------------------------------+\n";
                cout << " YAY! X won! *v*";
                cout<<"\n+----------------------------------+\n";
            }
            else if (CheckWinCond(SLOT_O)){
                cout<<"\n+----------------------------------+\n";
                cout << " WOW! O won! *v*";
                cout<<"\n+----------------------------------+\n";
            }
            else{
                cout<<"\n+----------------------------------+\n";
                cout << "IT'S A DRAW!!! >:O";
                cout<<"\n+----------------------------------+\n";
            }
            getch();

            gamestate = false;
        }
        else if (PlayerTurn == 1){

            do{
                cout<<"\n+----------------------------------+\n";
                cout << " Player X's turn (Select 1 - 9): ";
                cin >> select;

                if (isMoveValid(select, 'x')){ // Checks if slot is occupied
                    break;
                }
                else
                    system("cls");
                    DrawGrid();
                    cout << "\n Uh-oh! That slot is occupied. (._.;)" << endl;


            }while(true);

            PlayerTurn = 2;
        }
        else{

            do{
                cout<<"\n+----------------------------------+\n\n";
                cout << " Player O's turn (Select 1 - 9): ";
                cin >> select;

                if (isMoveValid(select, 'o')){
                    break;
                }
                else
                    system("cls");
                    DrawGrid();
                    cout << "\n Uh-oh! That slot is occupied. (._.;)" << endl;


            }while(true);

            PlayerTurn = 1;
        }

        system("cls");

        i++;




    }while(gamestate == true);

    cout << "\n Would you like to have a rematch?\n ";
        cin>>rematch;

        if (rematch=='N'||rematch=='n'){
            cout<<"\n+-------------------------------------------------+\n";
            cout<<" Come back when you want to play again! :D";
            cout<<"\n+-------------------------------------------------+\n";
        }
        else if ((rematch != 'Y')&&(rematch != 'y')&&(rematch != 'N')&&(rematch != 'n')){
            do{
                cout<<"\n Oops! It was meant to be a 'Yes' or 'No' question. =v=;";
                cout<<"\n Would you like to have a rematch? (Y/N)\n ";
                cin>>rematch;
                if ((rematch == 'N')||(rematch == 'n')){
                    cout<<"\n+-------------------------------------------------+\n";
                    cout<<" Come back when you want to play again! :D";
                    cout<<"\n+-------------------------------------------------+\n";
                }
            }while ((rematch != 'Y')&&(rematch != 'y')&&(rematch != 'N')&&(rematch != 'n'));
        }
    }while (rematch=='Y'||rematch=='y');



    return 0;

}

