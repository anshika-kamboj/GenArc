#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include"accounts.cpp"
#include"tictactoe.cpp"
#include"casino.cpp"
#include"rps.cpp"
#include"monstergame.cpp"
#include"zwar.cpp"
#include"snakegame.cpp"
#include"guessgame.cpp"

using namespace std;

int selectScreen(){

    int game;
    while(1){
        cout<<"Please a select a gamecode from our variety of games: "<<endl
        <<"1. Casino Bet Game"<<endl
        <<"2. Tic Tac Toe (2 Player)"<<endl
        <<"3. Rock Paper Scissor (vs Computer)"<<endl
        <<"4. Monster Fight Game"<<endl
        <<"5. Zombie War Scenario"<<endl
        <<"6. The Snake Game"<<endl
        <<"7. The Guessing Games"<<endl
        <<"8. Exit"<<endl<<endl;

        cout<<"Enter the Game Code: ";
        cin>>game;
        getchar();
        if (game == 8){break;
        }else if(game == 7){
            ggame();
        }else if(game == 6){
            snkG();
        }else if(game == 5){
            zwar();
        }else if(game == 4){
            mbattle();
        }else if(game == 3){
            rps();
        }else if(game == 2){
            ttt();
        }else if(game == 1){
            cso();
        }else{

            cout<<"Enter the valid code !!"<<endl<<flush;
            system("color C");
            system("PAUSE");
            system("color 7");
        }
    }


    return 0;
}

int main()
{


    cout<<"*******************"<<endl;
    cout<<"*****GenArcade*****"<<endl;
    cout<<"*******************"<<endl<<endl;
    for(int i=0; i<40; i++){
        cout<<flush;
        system("color C");
        sleep(0.1);
        cout<<flush;
        system("color A");
        sleep(0.1);
    }
    cout<<flush;
    system("color 7");

    int choice;

    cout<<"Welcome to the GenArcade!!"<<endl
    <<"1. Please Create an Account if you don't have one"<<endl
    <<"            OR                     "<<endl
    <<"2. Login with an already existant id"<<endl
    <<"            OR                     "<<endl
    <<"3. See account details by loggin in"<<endl
    <<"            OR                     "<<endl
    <<"4. Login as a Guest"<<endl<<endl;

    choose: cout<<"Enter your choice code: ";
    cin>>choice;

    if(choice == 4){
        selectScreen();
    }else if(choice == 3){
        ifstream As;
        As.open("accounts.dat", ios::in|ios::binary|ios::ate);
        int size = As.tellg()/sizeof(Account);
        As.seekg(ios::beg);
        vector<Account> Acts(size);

        for(int i=0; i<size; i++){
            As.read((char*)&Acts[i], sizeof(Account));
        }
        As.close();

        int code;
        char pass[len];
        char dp[len];
        cout<<"Please select the accounts from the list below: \n";
        for(int i=0; i<size; i++){
            Acts[i].getDP(dp);
            cout<<i+1<<". "<<dp<<endl;
        }

        cout<<"Enter the id code: ";
        cin>>code;

        Acts[code-1].getDP(dp);
        cout<<"Enter the password for "<<dp<<": ";
        cin>>pass;
        if(Acts[code-1].checkPass(pass)){
            cout<<flush;
            system("color A");
            cout<<"Account verified!"<<endl;
        }else{
            cout<<"Please choose other option or try again later!"<<endl;
            goto choose;
        }
        cout<<"Showing All Details: \n";
        Acts[code-1].showAll();
        cout<<endl;
    }else if(choice == 2){
        ifstream As;
        As.open("accounts.dat", ios::in|ios::binary|ios::ate);
        int size = As.tellg()/sizeof(Account);
        As.seekg(ios::beg);
        vector<Account> Acts(size);

        for(int i=0; i<size; i++){
            As.read((char*)&Acts[i], sizeof(Account));
        }
        As.close();

        int code;
        char pass[len];
        char dp[len];
        cout<<"Please select the accounts from the list below: \n";
        for(int i=0; i<size; i++){
            Acts[i].getDP(dp);
            cout<<i+1<<". "<<dp<<endl;
        }

        cout<<"Enter the id code: ";
        cin>>code;
        getchar();

        Acts[code-1].getDP(dp);
        cout<<"Enter the password for "<<dp<<": ";
        cin>>pass;
        if(Acts[code-1].checkPass(pass)){
            cout<<flush;
            system("color A");
            cout<<"Account verified!"<<endl;
        }else{
            cout<<flush;
            system("color C");
            cout<<"Could not verify Account please create new one!!"<<endl<<endl;
            Account a1(1);
        }
        selectScreen();
    }else if(choice == 1){
        Account a1(1);
        selectScreen();
    }else{
        cout<<"Enter valid code!!"<<endl<<flush;
        system("color C");
        system("PAUSE");
        goto choose;
    }

    cout<<"Thank YOU for using GenArcade!!"<<endl<<endl;
    getch();
    return 0;
}
