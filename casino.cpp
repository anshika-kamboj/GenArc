#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
class casino
{
    public:
    string playerName;
    int amount; // hold player's balance amount
    int bettingAmount;
    int guess;
    int dice; // hold computer generated number
    char choice;
    //srand(time(0)); // "Seed" the random generator
    casino()
    {
        printcasino();
     cout <<endl<< "Enter Your Name : ";
     getline(cin, playerName);
     cout << "Enter Deposit amount to play game : $";
     cin >> amount;
    }
    void game();
    void cont();
    void rules();
    void getbettingamnt();
    void printcasino();
    void printaww();
    void printyayy();
    void result();
    void drawLine(int,char);
};

int cso()
{
    casino obj;
     obj.rules();
          do
    {
       
        cout <<endl<< "Your current balance is $ " << obj.amount <<endl;
        // Get player's betting amount
        obj.getbettingamnt();
        obj.game();
        obj.result();
        obj.cont();
    }while(obj.choice =='Y'|| obj.choice=='y');
     
   obj.drawLine(137,'#');
    cout <<endl<< "Thanks for playing game. Your balance amount is $ " << obj.amount << "\n";
   obj.drawLine(137,'#');
    return 0;
}


  void casino:: getbettingamnt()
    {
        do
        {
            cout <<playerName<<", enter money to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << endl<<"Your betting amount is more than your current balance"
                       <<" , please re-enter betting amount";
        }while(bettingAmount > amount);
    }
   void casino:: game()
    {
        do
        {
            cout <<endl <<"Guess your number to bet between 1 to 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout <<endl<< "Please check the number!! it should lie between 1 to 10"
                    <<", Re-enter number ";
        }while(guess <= 0 || guess > 10);
        dice = rand()%10 + 1; // Will hold the randomly generated integer between 1 and 10
         
         cout<<endl;
         drawLine(54,'>');
        cout << " The winning number is : " << dice<< "  ";
        drawLine(54,'<');
        cout<<endl<<endl<<endl<<endl;
    }
  void casino:: result()
    {
        if(dice == guess)
        {
            printyayy();
            cout <<endl<< " You won $" << bettingAmount * 2;
            amount = amount + bettingAmount * 2;
        }
        else
        {    printaww();
            cout <<endl<< " You lost $ "<< bettingAmount <<endl
            ;
            amount = amount - bettingAmount;
        }

        cout << "\n"<<playerName<<", You have $ " << amount << "\n";
        if(amount == 0)
        {
            cout <<endl<< "You have no money to play ";
            exit;
        }
    }
  void casino::cont()
    {
        drawLine(137,'*');
        cout <<endl;
        drawLine(30,' ');
        cout<< "Do you want to play again (y/n)?  ";
        cin >> choice;
        drawLine(137,'*');
        cout<<endl<<endl<<endl;
    }

void casino:: rules()
{
    drawLine(60,'_');
    cout << "RULES OF THE GAME";
    drawLine(60,'_');
    cout <<endl<< "1. Choose any number between 1 to 10"<<endl;
    cout << "2. If you win you will get 2 times of money you bet"<<endl;
    cout << "3. If you bet on wrong number you will lose your betting amount"<<endl;
    drawLine(137,'_');
    cout<<endl<<endl;
}
  void casino:: drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
}

void casino:: printcasino()
{
    drawLine(30,' ');
    cout<<"     $$$$        $$       $$$$$   $$$$$$$$    $$      $$       $$$     "<<endl;
    drawLine(30,' ');
    cout<<"    $$   $$    $$  $$    $$   $$     $$       $$$     $$     $$   $$   "<<endl;
    drawLine(30,' ');
    cout<<"   $$         $$    $$   $$          $$       $$ $$   $$    $$     $$  "<<endl;
    drawLine(30,' ');
    cout<<"   $$        $$      $$   $$$$$      $$       $$  $$  $$   $$       $$ "<<endl;
    drawLine(30,' ');
    cout<<"   $$        $$$$$$$$$$       $$     $$       $$   $$ $$    $$     $$  "<<endl;
    drawLine(30,' ');
    cout<<"    $$   $$  $$      $$  $$   $$     $$       $$     $$$     $$   $$   "<<endl;
    drawLine(30,' ');
    cout<<"     $$$$    $$      $$   $$$$$   $$$$$$$$    $$      $$       $$$     "<<endl;
    drawLine(60,'_');
}
void casino:: printaww()
{
    drawLine(30,' ');
            cout<<"   $$      $$     $     $$  $$     $     $$   $$ $$ "<<endl;
            drawLine(30,' ');
            cout<<"  $$ $$    $$    $$$    $$  $$    $$$    $$   $$ $$ "<<endl;
            drawLine(30,' ');
            cout<<" $$   $$   $$   $$ $$   $$  $$   $$ $$   $$   $$ $$ "<<endl;
            drawLine(30,' ');
            cout<<"$$$$$$$$$   $$ $$   $$ $$   $$ $$    $$ $$          "<<endl;
            drawLine(30,' ');
            cout<<"$$     $$    $$      $$      $$       $$      $$ $$ "<<endl;
            drawLine(50,' ');
}
void casino:: printyayy()
{
            drawLine(30,' ');
            cout<<"$$   $$    $$    $$   $$  $$   $$  $$ $$ "<<endl;
            drawLine(30,' ');
            cout<<" $$ $$    $$ $$   $$ $$    $$ $$   $$ $$ "<<endl;
            drawLine(30,' ');
            cout<<"  $$$    $$   $$   $$$      $$$    $$ $$ "<<endl;
            drawLine(30,' ');
            cout<<"   $$   $$$$$$$$$   $$       $$          "<<endl;
            drawLine(30,' ');
            cout<<"   $$   $$     $$   $$       $$    $$ $$ "<<endl;
            drawLine(50,' ');
           
}