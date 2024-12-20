#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

void Header(string username[], string symbol[]){
    cout<<"+----------------------------------+\n";
    cout<<" \t🙞 Tic-Tac-Toe!🙜\n";
    cout<<"+----------------------------------+\n\n";
    cout<<" "<<username[0]<<symbol[0]<<"\t\t"<<username[1]<<symbol[1]<<endl<<endl;
}

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

int main(){

    SetConsoleOutputCP(CP_UTF8);
    int SLOTSIZE = 9, PLAYERS=2, p=0;
    char SLOT[SLOTSIZE - 1], confirm; // 9 slots including 0
    string username[PLAYERS];

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

    char rematch;
    do{
        system("cls");
        string symbol[PLAYERS];
        int randomNum = rand() % 2;
        if (randomNum==1){
            symbol[0] = "\xF0\x9F\x8D\x87";
        }
        else if (randomNum==0){
            symbol[0] = "\xF0\x9F\x8D\x92";
        }
        if (1-randomNum==1){
            symbol[1] = "\xF0\x9F\x8D\x87";
        }
        else if (1-randomNum==0){
            symbol[1] = "\xF0\x9F\x8D\x92";
        }


    for (int i = 0; i < SLOTSIZE; i++){
        SLOT[i] = ' ';
    }

    bool gamestate = true;
    int i = 0;
    int PlayerTurn = 1;
    int select;

    //Main game loop
    do{

        Header(username,symbol);

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

    cout << "\n Congratulations, "<<username[0]<<" you have won against "<<username[1]<<"! (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧";

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

