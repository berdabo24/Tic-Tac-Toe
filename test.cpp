#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

//GLOBAL VARIABLES
const int SLOTSIZE = 9;
string SLOT[SLOTSIZE]; // 9 slots including 0
int ACTIVESLOT[SLOTSIZE] = {0};

void Header(string username[], string symbol[]){
    cout<<"+----------------------------------+\n";
    cout<<" \t🙞 Tic-Tac-Toe!🙜\n";
    cout<<"+----------------------------------+\n\n";
    cout<<" "<<username[0]<<symbol[0]<<"\t\t"<<username[1]<<symbol[1]<<endl<<endl;
}

void GridRows(string a,string b,string c){
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

bool isMoveValid(int input, string turn){

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

    SetConsoleOutputCP(CP_UTF8);
    int SLOTSIZE = 9, PLAYERS=2, p=0;
    string username[PLAYERS]; // 9 slots including 0
    char confirm,rematch;

    cout<<"+-------------------------------------------------+\n";
    cout<<" Hello, user! Welcome to \xE2\x96\xB6Tic-Tac-Toe!\xE2\x97\x80 ヾ(≧▽≦*)o\n";

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
                cout<<"Invalid input. Please try again.";
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


        int randomNum = rand() % 2; // Grape(1)/Cherry(0) for Player 1
        if (randomNum==1){
            symbol[0] = "\xF0\x9F\x8D\x87"; //Player 1: Grape as X
        }
        else if (randomNum==0){
            symbol[0] = "\xF0\x9F\x8D\x92"; //Player 1: Cherry as O
        }
        if (1-randomNum==1){
            symbol[1] = "\xF0\x9F\x8D\x87"; //Player 2: Grape as X
        }
        else if (1-randomNum==0){
            symbol[1] = "\xF0\x9F\x8D\x92"; //Player 2: Cherry as O
        }


    for (int i = 0; i < SLOTSIZE; i++){
        SLOT[i] = " ";
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
         if (i == 9){
            cout << "Press enter to continue: ";
            getch();

            gamestate = false;
        }
        else if (PlayerTurn == 1){

            do{
                cout << "Player \xF0\x9F\x8D\x87's turn (Select 1 - 9): ";
                cin >> select;

                if (isMoveValid(select, "\xF0\x9F\x8D\x87")){ // Checks if slot is occupied
                    break;
                }
                else
                    system("cls");

                DrawGrid();
                cout << "Uh-oh! That slot occupied! (._. ;)" << endl;

            }while(true);

            PlayerTurn = 2;
        }
        else{
            do{
                cout << "Player \xF0\x9F\x8D\x92's turn (Select 1 - 9): ";
                cin >> select;

                if (isMoveValid(select, "\xF0\x9F\x8D\x92")){
                    break;
                }
                else
                    system("cls");
                    DrawGrid();
                    cout << "Uh-oh! That slot occupied! (._. ;)" << endl;


            }while(true);

            PlayerTurn = 1;
        }

        system("cls");

        i++;

    }while(gamestate == true);

    cout << "\n Congratulations, "<<username[0]<<" wins! (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧";

        cout << "\n Would you like to have a rematch?\n ";
        cin>>rematch;

        if (rematch=='N'||rematch=='n'){
            cout<<"\n+-------------------------------------------------+\n";
            cout<<" Come back when you want to play again! o(*^▽^*)┛";
            cout<<"\n+-------------------------------------------------+\n";
        }
        else if ((rematch != 'Y')&&(rematch != 'y')&&(rematch != 'N')&&(rematch != 'n')){
            do{
                cout<<"\n Oops! It was meant to be a 'Yes' or 'No' question. =v=;";
                cout<<"\n Would you like to have a rematch? (Y/N)\n ";
                cin>>rematch;
                if ((rematch == 'N')||(rematch == 'n')){
                    cout<<"\n+-------------------------------------------------+\n";
                    cout<<" Come back when you want to play again! o(*^▽^*)┛";
                    cout<<"\n+-------------------------------------------------+\n";
                }
            }while ((rematch != 'Y')&&(rematch != 'y')&&(rematch != 'N')&&(rematch != 'n'));
        }
    }while (rematch=='Y'||rematch=='y');


    return 0;

}

