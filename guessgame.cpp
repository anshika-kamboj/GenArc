#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
class guess
{
    public:
    int a;
    string name;
    guess()
    {
        cout<<"please enter your name : ";
        getline(cin,name);
        cout<<endl;
        cout << "What game you want to play? "<<endl << "1. Guess the number  "<<endl << "2. Math answers "<<endl << "3. Guess the word " << endl;
       cout<<endl<<" choice : ";
        cin >> a;
    }
    void guessnumber()
    {
        char ch='y';
        while(ch=='y'||ch=='Y')
        {
        int d;
            int c;
            c = rand() % 100+20;
            int l,m;
            l=rand()%5+1;
            m=rand()%10+5;
            cout << "HINT: The number is between " << c-l<< " and " << c+m<<endl;
            cout << "Enter your guess:"<<endl;
            cin >> d;
            if(d==c)
                cout << "Right answer"<<endl;
            else
                cout << "Wrong answer. The answer is " << c << endl;
                cout<<"Do you want to continue playing guessing number game (y/n) : ";
                cin>>ch;
                cout<<endl;
        }
       
    }
    void maths()
    {  char ch;
        do{
         int c;
            c=rand() % 20+10;
            int d;
            d = rand() % 14+7;
            int p =rand()%50+1;
            int f;
            cout << "What is " << c << " + " << d <<" * "<<p<< " = " <<endl;
            cin >> f;

            if (f==c+d*p)
                cout << "Right answer!!"<< endl;

            else
                cout<<"Wrong answer! The answer is: " << c+d*p << endl;
                 cout<<"Do you want to continue playing maths game (y/n) : ";
                cin>>ch;
                cout<<endl;
        }while(ch=='y'||ch=='Y');
    }
    void guessword()
    {
        char ch;
        do{
          string word;
            string ans;
            int ran;
            ran = rand() % 5+1;

            if(ran==1 || ran==2)
            word = "rabbit";

            if(ran==3)
            word = "apple";

             if(ran==4)
            word = "football";

             if(ran==5)
            word = "cricket";

            int l = word.size();

            cout << "Guess the word:  " ;

            for (int i=0;i<l;i++)
            {
                if(i%2==0)
                    cout << word[i];

                else
                    cout << "_";
            }

            cout << endl << "Enter your answer:  ";
            cin >> ans;

            if (word==ans)
                cout << " Right answer! " << endl;

            else
                cout << " Wrong answer. The right answer is "<<word << endl;
               
                 cout<<" Do you want to continue playing maths game (y/n) : ";
                cin>>ch;
                cout<<endl;
                cin.ignore();
        }
        while(ch=='y'||ch=='Y');
    }
};
void hscreen()
{cout<<endl<<endl<<endl<<endl;
    cout<<"_____________________________________________________________________________________________________________"<<endl<<endl<<endl;
    cout<<"               @@@@@@@    @@     @@  @@@@@@@@   @@@@@@    @@@@@@       @@  @@  "<<endl;
    cout<<"              @@     @@   @@     @@  @@        @@    @@  @@    @@      @@  @@  "<<endl;
    cout<<"             @@           @@     @@  @@        @@        @@            @@  @@  "<<endl;
    cout<<"             @@           @@     @@  @@@@@@     @@@@@@    @@@@@        @@  @@  "<<endl;
    cout<<"             @@    @@@@   @@     @@  @@              @@       @@       @@  @@  "<<endl;
    cout<<"              @@  @@ @@    @@   @@   @@        @@    @@  @@   @@               "<<endl;
    cout<<"               @@@@  @@     @@@@@    @@@@@@@@   @@@@@@    @@@@@        @@  @@  "<<endl;
    cout<<"______________________________________________________________________________________________________________"<<endl<<endl;
    cout<<"                                      GUESSING GAMES                                                          "<<endl;
    cout<<"______________________________________________________________________________________________________________"<<endl;
}
int ggame()
{
   
    char b='y';
    hscreen();
    while(b=='y'|| b=='Y')
    {  
        guess obj;
        if (obj.a==1)
        {
          obj.guessnumber();
          cout<<" do you want to choose some other game press 'y' else  press 'e' to exit : ";
          cin>>b;
        }
        else if(obj.a==2)
        {
           obj.maths();
           cout<<" do you want to choose some other game press 'y' else  press 'e' to exit : ";
          cin>>b;
        }
        else if (obj.a==3)
        {
            obj.guessword();
            cout<<" do you want to choose some other game press 'y' else  press 'e' to exit : ";
          cin>>b;
        }
    }
    return 0;
}
