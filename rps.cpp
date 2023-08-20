#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Game
{
  public:
  char computer;
  char player;
  char playmore;
  void homescreen();
  void gametime();
  int rule(char,char);
};

int Game:: rule(char p, char c)
{
    if (p == c)
    {
        return 0;
    }
    if (p == 'r' && c == 'p')
    {
        return -1;
    }
    else if (p == 's' && c == 'p')
    {
        return 1;
    }
    else if (p == 'p' && c == 'r')
    {
        return 1;
    }
    else if (p == 's' && c == 'r')
    {
        return -1;
    }
    else if (p == 'r' && c == 's')
    {
        return 1;
    }
    else if (p == 'p' && c == 's')
    {
        return -1;
    }
}
 void  Game ::homescreen()
    {
        cout << "\t\t\t\t";
        for(int i = 0; i < 50; i++)
        {
        cout << "-";
        }
    cout << endl;
    cout << "\t\t\t\t";
    cout << "\t Welcome to Rock, Paper and Scissors Game" << endl;
    cout << "\t\t\t\t";
        for(int i = 0; i < 50; i++)
       {
        cout << "-";
       }
    cout << endl;
    cout << "\t\t\t\t";
    cout << "\t Note: " << endl;
    cout << "\t\t\t\t";
    cout << "\t\t r : Rock" << endl << "\t\t\t\t" << "\t\t p : Paper" << endl << "\t\t\t\t" << "\t\t s : scissor" << endl << "\t\t\t\t"<< endl << endl;
    cout << "\t\t\t\t";
    for(int i = 0; i < 50; i++)
    {
        cout << "-";
    }
    cout << endl;
    }
    void Game:: gametime()
    {
        do{
        int number = 0;
        srand(time(0));        // initialized time to 0
        number = rand() % 100; // will choose a number in range 0 - 99
        // r - for rock
        // p - for paper
        // s - for scissors
        if (number < 33)
        {
            computer = 'r';
        }
        else if (number > 66)
        {
            computer = 's';
        }
        else
        {
            computer = 'p';
        }
        // cout << "Note: \"r\" for \"Rock\", \"p\" for \"Paper\", \"s\" for \"Scissor\"." << endl;
        cout << "\t\t\t\t";
        cout << "Enter your choice: ";
        cin >> player;
        int result = rule(player, computer);
        if(result == 1){
            cout << "\t\t\t\t";
            cout << "You won! Hurray" << endl;
        }
        else if(result == -1){
            cout << "\t\t\t\t";
            cout << "You lose! Bad Luck" << endl;
        }
        else{
            cout << "\t\t\t\t";
            cout << "Woah! That's Tie!" << endl;
        }
        cout << "\t\t\t\t";
       
        cout << "Do you want to continue with another game: ";
        cin >> playmore;
        cout << "\t\t\t\t";
        for(int i = 0; i < 50; i++){
            cout << "-";
        }
        cout << endl;
    }while(playmore != 'n');
    }
void printrps()
{
    cout<<  "                                         &&&&&&       &&&&&&     &&&&&   "<<endl;
    cout<<  "                                         &&   &&      &&   &&   &&   &&  "<<endl;
    cout<<  "                                         &&   &&      &&   &&   &&       "<<endl;
    cout<<  "                                         &&&&&&       &&&&&&     &&&&    "<<endl;
    cout<<  "                                         &&&&         &&             &&  "<<endl;
    cout<<  "                                         && &&        &&        &&   &&  "<<endl;
    cout<<  "                                         &&  &&       &&         &&&&&   "<<endl<<endl;
    cout<<  "                                         ROCK         PAPER     SCISSOR  "<<endl<<endl<<endl<<endl;
}
int rps()
{
    printrps();
 Game obj;
 obj.homescreen();
 obj.gametime();
    return 0;
}