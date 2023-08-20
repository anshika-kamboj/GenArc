#pragma once

#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<vector>
#include<conio.h>
#include<fstream>
#define len 100

using namespace std;
// template<class T>
// string protected_input();

bool email_check(char em[]);

class Account{
    private:
        char Password[len];

    protected:
        char Fname[len];
        char Lname[len];
        char email[len];
        char Dispname[len];
        unsigned int Age;
        char Phone[len];
        // int GamesPlayed;
    
    public:
        Account();
        Account(int input);
        Account(Account& act);
        int checkPass(char Pass[len]);
        void getName(char (&name)[len]);
        void getEmail(char (&em)[len]);
        void getDP(char (&dp)[len]);
        int getAge();
        void getPhone(char (&ph)[len]);
        // int showGames();
        void showAll();

};