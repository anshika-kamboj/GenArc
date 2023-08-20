#include"tictactoe.h"


int box::move = 1;
int box::start = 0;
char box::opt[2] = {'X','O'};

box::box(){
    val = ' ';
}

void box::doMove(){
    val = opt[start];
    move++;
    box::start = !box::start;
}

grid::grid(int start = 0){
    box::start = start;
    for(int i=1; i<=9; i++){
        board.insert(pair<int,box*>(i, new box()));
    }
}

int grid::checker(char win){
    for(int i=1;i<9;i+=3){
        if(board.at(i)->val == board.at(i+1)->val && board.at(i)->val == board.at(i+2)->val && (board.at(i)->val == 'X' || board.at(i)->val == 'O')){throw win;}
    }

    for(int i=1;i<4;i++){
        if(board.at(i)->val == board.at(i+3)->val && board.at(i)->val == board.at(i+6)->val && (board.at(i)->val == 'X' || board.at(i)->val == 'O')){throw win;}
    }

    if(board.at(1)->val == board.at(5)->val && board.at(9)->val && (board.at(5)->val == 'X' || board.at(5)->val == 'O')){throw win;}
    if(board.at(3)->val == board.at(5)->val && board.at(7)->val && (board.at(5)->val == 'X' || board.at(5)->val == 'O')){throw win;}
    return 0;
}

void grid::drawGrid(){
    char choice;
    cout<<"Choose the marker for "<<"Player "<<P1->Name<<" (X/O): ";
    cin>>choice;
    map<char,Player*> P;
    if (choice == 'O'){box::start = 1;}
    P.insert(pair(box::opt[box::start],P1));
    P.insert(pair(box::opt[!box::start],P2));
    while(1){
        int spot, place = 1;
        map<int,box*>::iterator sq;
        sq = board.begin();

        cout<<flush;
        system("CLS");
        if(box::start){
            cout<<flush;
            system("color A");
        }else{
            cout<<flush;
            system("color B");
        }


        for(int i=0;i<3;i++){
            for(int j=0; j<3;j++){
                cout<<"|"<<place<<"   "<<" |";
                place++;
            }
            cout<<endl;
            for(int j=0; j<3;j++){
                cout<< "| "<<" "<<sq->second->val<<" "<<" |";
                sq++;
            }
            cout<<endl;
            for(int j=0; j<3;j++){
                cout<<"| "<<"   "<<" |";
            }
            cout<<endl;
            if(i==2){break;}
            for(int j=0; j<3;j++){
                cout<<"--"<<"---"<<"--";
            }
            cout<<endl;
        }
        cout<<"Player"<<" Enter the number of box to place marker: ";
        cin>>spot;
        sq = board.find(spot);
        sq->second->doMove();
        try{
            if(box::move>=5){
                if(checker(box::opt[!box::start]));
            }
            cout<<flush;
            system("CLS");

        }catch(char winner){
            cout<<flush;
            system("CLS");

            ofstream lead;
            lead.open("tttLeaderboard.txt",ios::app);
            lead<<P.at('X')->Name<<" v/s "<<P.at('O')->Name<<" | Winner: "<<P.at(winner)->Name<<endl;
            lead.close();

            cout<<P.at(winner)->Name<<" won!!"<<endl<<flush;
            system("PAUSE");
            break;
        }
    }

}

grid::~grid(){
    map<int,box*>::iterator key;
    for(int i=1; i<=9; i++){
        key = board.find(i);
        delete key->second;
    }
    cout<<flush;
    system("CLS");
}

Player::Player():Account(1){
    this->getDP(this->Name);
}

Player::Player(Account A):Account(A){
    A.getDP(this->Name);
}

int ttt(){
    int ch;
    while(1){
        do{
            cout<<flush;
            system("CLS");

            cout<<"******Welcome to Tic Tac Toe!!*******\n"<<endl;
            cout<<"Please choose an option from below: \n"
            <<"1. Select existing 2 accounts\n"
            <<"2. Create new accounts\n"
            <<"3. See LeaderBoard\n"
            <<"4. Back\n"<<endl;
            cout<<"Enter the code: ";
            cin>>ch;
            if(ch!=4 && ch!=3 && ch!=2 && ch!=1){
                cout<<"Enter valid code!!"<<endl<<flush;
                system("PAUSE");
            }
        }while (!(ch==4 || ch==3 || ch==2 || ch==1));

        if (ch == 4){
            break;
        }else if (ch == 3){
            Leader: ifstream lead;
            lead.open("tttLeaderboard.txt",ios::in);
            string line;
            cout<<"******LeaderBoard and History******\n"<<endl;
            if(!lead){ cout<<"Error opening LeaderBoard !!\n";}
            while(lead){
                getline(lead,line);
                cout<<line<<endl;
            }
            lead.close();
            cout<<flush;
            system("PAUSE");
        }else if (ch == 2){
            Player PP1;
            Player PP2;
            P1 = &PP1;
            P2 = &PP2;
            grid g;
            g.drawGrid();
            goto Leader;
        }else if (ch == 1){
            ifstream As;
            As.open("accounts.dat", ios::in|ios::binary|ios::ate);
            int size = As.tellg()/sizeof(Account);
            As.seekg(ios::beg);
            vector<Account> Acts(size);

            for(int i=0; i<size; i++){
                As.read((char*)&Acts[i], sizeof(Account));
            }
            As.close();

            int p1,p2;
            char pass[len];
            char dp[len];
            cout<<"Please select the accounts from the list below: \n";
            for(int i=0; i<size; i++){
                Acts[i].getDP(dp);
                cout<<i+1<<". "<<dp<<endl;
            }
            cout<<"Enter the account codes: ";
            cin>>p1>>p2;
            Acts[p1-1].getDP(dp);
            cout<<"Enter the password for "<<dp<<": ";
            cin>>pass;
            if(Acts[p1-1].checkPass(pass)){
                cout<<flush;
                system("color A");
                cout<<"Player 1 verified!"<<endl;
                Player PP1(Acts[p1-1]);
                P1 = new Player(PP1);
            }else{
                cout<<flush;
                system("color C");
                cout<<"Could not verify Player 1 please register!!"<<endl<<endl;
                Player PP1;
                P1 = new Player(PP1);
            }
            Acts[p2-1].getDP(dp);
            cout<<"Enter the password for "<<dp<<": ";
            cin>>pass;
            if(Acts[p2-1].checkPass(pass)){
                cout<<flush;
                system("color A");
                cout<<"Player 2 verified!"<<endl;;
                Player PP2(Acts[p2-1]);
                P2 = new Player(PP2);
            }else{
                cout<<flush;
                system("color C");
                cout<<"Could not verify Player 2 please register!!"<<endl<<endl<<flush;
                system("PAUSE");
                Player PP2;
                P2 = new Player(PP2);
            }
            grid g;
            g.drawGrid();
            goto Leader;
        }
        
    }
    delete P1;
    delete P2;

    cout<<flush;
    system("color 7");

    return 0;
}