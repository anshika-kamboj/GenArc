#pragma once
#include "accounts.h"


// template<class T>
// const char(*)[len] protected_input(){
//     char temp[len];
//     T x;
    
//     x = getch();
//     int i = 0;
//     while(x!=13){
//         temp[i] = x;
//         cout<<"*";
//         i++
//         x = getch();
//     }
//     temp[i] = '\0';
//     cout<<endl;
//     return &temp;
// }

bool email_check(char em[]){
    bool flag1 = false;
    bool flag2 = false;
    for(int i=0; i<strlen(em)-1; i++){
        if(em[i] == '@') flag1 = true;
        if(em[i] == '.') flag2 = true;
    }
    return (flag1 && flag2);
}

Account::Account(){

}

Account::Account(int input){

    cout<<flush;
    system("CLS");
    cout<<"******CREATE ACCOUNT******\n\n"<<flush;

    system("echo All the (*) fields are compulsory");
    system("echo for non(*) fields u may enter '-' to skip!!\n");
    system("color A");

    // GamesPlayed = 0;

    cout<<"*Enter your Full Name: ";
    cin>>Fname>>Lname;

    cout<<"*Enter your Display Name: ";
    cin>>Dispname;

    cout<<"*Enter the Password: ";
    
    {char x;

    x = getch();
    int i = 0;
    while(x!=13){
        Password[i] = x;
        cout<<"*";
        i++;
        x = getch();
    }
    Password[i] = '\0';}
    cout<<endl;

    while(1){
        try{
            cout<<"*Enter your Age: ";
            int check;
            check = scanf("%d",&Age);
            cin.ignore();
            if(check) break;
            else throw 0;
        }catch(int){
            cout<<"Enter valid Age!!"<<endl<<flush;
            system("color C");
            system("PAUSE");
        }
    }
    cout<<flush;
    system("color A");

    cout<<"*Enter your Email id: ";
    cin>>email;
    while(1){        
        if(email_check(email)){
            break;
        }
        cout<<"Please Enter a valid Email!!"<<endl<<flush;
        system("color C");
        system("PAUSE");
        cout<<"*Enter your Email id: \t";
        cin>>email;
    }
    cout<<flush;
    system("color A");

    int x;
    cout<<"Enter your Phone No: ";
    x = getch();
    cout<<(char)x<<"";
    if(x == 45){
        Phone[0] = 'N';
        Phone[1] = 'A';
        Phone[2] = '\0';
    }
    int i = 0;
    while(x!=45 && x!=13){
        try{
            if(!(x>47 && x<58)){throw 0;}
            Phone[i] = x;
            i++;
            x = getch();
            cout<<(char)x<<"";
        }
        catch(int){
            cout<<endl<<"Please enter Numbers only!!"<<endl<<flush;
            system("color C");
            cout<<"Enter your Phone No: ";
            x = getch();
            cout<<(char)x<<"";
        }
    }
    Phone[i] = '\0';
    cout<<endl<<flush;
    system("color A");
    ofstream acts;
    acts.open("accounts.dat", ios::app|ios::binary);
    if(!acts){
        cout<<endl<<"Error Opening the file!!"<<endl;
    }else{
        acts.write((char*)this,sizeof(Account));
        acts.close();
        if(!acts.good()){
            cout<<"Error in writing!!"<<endl;
        }
        cout<<flush;
        system("CLS");
        cout<<"Account Successfully created!!\n"<<flush;
        system("PAUSE");
        system("color 7");
    }
}

Account::Account(Account& act){
    Age = act.Age;
    strcpy(Dispname,act.Dispname);
    strcpy(email,act.email);
    // GamesPlayed = act.GamesPlayed;
    strcpy(Fname,act.Fname);
    strcpy(Lname,act.Lname);
    strcpy(Password,act.Password);
    strcpy(Phone,act.Phone);
}

int Account::checkPass(char Pass[len]){
    if (strcmp(Password,Pass) == 0){
        return 1;
    }else{
        return 0;
    }
}

void Account::getName(char (&name)[len]){
    char Name[len];
    strcpy(Name,Fname);
    strcat(Name," ");
    strcat(Name,Lname);
    strcpy(name,Name);
    // return &Name;
}

void Account::getDP(char (&dp)[len]){
    strcpy(dp,Dispname);
    // return &Dispname;
}

void Account::getEmail(char (&em)[len]){
    strcpy(em,email);
    // return &email;
}

void Account::getPhone(char (&ph)[len]){
    strcpy(ph,Phone); 
    // return &ph;
}

int Account::getAge(){
    return Age;
}

// int Account::showGames(){
//     return GamesPlayed;
// }

void Account::showAll(){
    cout<<"Name: \t\t"<<Fname<<" "<<Lname<<endl
    <<"User: \t\t"<<Dispname<<endl
    <<"Age: \t\t"<<Age<<endl
    <<"Email ID: \t"<<email<<endl
    <<"Phone No: \t"<<Phone<<endl;
    // <<"Games Played: \t"<<GamesPlayed<<endl;
}