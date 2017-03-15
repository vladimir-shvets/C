#include <iostream>
#include <iomanip>
//#include<windows.h>
using namespace std;


////////////////////////////////////////////////////////////////////////////////
const int SZ = 4;
int board[SZ][SZ];
/*
 _____________
 |1 |2 |3 |4 |
 |5 |6 |7 |8 |
 |9 |10|11|12|
 |13|14|15|0 |
 -------------
 */


    void cleanBoard();
    bool checkForSolution();
    bool checkBoard();
    void showBoard();
    void changeBoard();
    void fillBoard();
    void mainMenu();
    void startGame();
    

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
void mainMenu()
{
    char choice;
    A:   cout << "\t\tП Я Т Н А Ш К И(15 P U Z Z L E)\n";
    
    cout << "1.Star a New Game!\n"<< "2.Help-Menu.\n"<< "3.Exit\n";
    cout<<"Choice:";
    cin>>choice;
    switch (choice)
    {
        case '1':
            startGame();
            break;
        case '2':
            cout<<"Enter which number do you want to move. It will go to the free section. Continue until all numbers won't be from 1 to 15. If you want to show main menu enter 0. Good Luck!\n";
            cout<<"Для того, чтобы играть, введите номер цифры, которую вы хотите переместить в пустую клеточку. Продолжайте перемещать, пока на поле все цифры не будут от 1 до 15. Для того, чтобы вызвать меню нажмите '0'. Удачи!\n";
            cout<<"Now you're ready to start!\n";
           // Sleep(10000000);
            startGame();
            
            break;
        case '3':
            cout<<"Bye!\n";
            exit(0);
            break;
        default:
            cout<<"\nIncorrect input!Try again!\n\n";
            goto A;
            break;
    }
}
////////////////////////////S T A R T  A  G A M E/////////////////////////////////
void startGame()
{
    do
    {
        cleanBoard();
        fillBoard();
    } while (!checkForSolution());
    
    int turns = 0;
    while (!checkBoard())
    {
        showBoard();
        changeBoard();
        turns++;
    }
    cout << "You made it in "<< turns << " turns!";
    system("pause");
}
////////////////////////////C L E A N I N G  A  B O A R D////////////////////////////
void cleanBoard()
{
    for (int i = 0; i < SZ; i++)
        for (int j = 0; j < SZ; j++)
            board[i][j] = 0;
}
////////////////////////////////////////////////////////////////////////////////
bool checkForSolution()
{
    int solution[SZ*SZ] = {0};
    int inv = 0;
    int index = 0;
    for (int i = 0; i < SZ; i++)
        for (int j = 0; j < SZ; j++, index++)
            solution[index] = board[i][j];
    
    for (int i = 0; i < SZ*SZ; i++)
        if (solution[i])
            for (int j = 0; j < i; j++)
                if (solution[j] > solution[i])
                    ++inv;
    for (int i = 0; i < SZ*SZ; i++)
        if (solution[i] == 0)
            inv += 1 + i / 4;
    if(inv&1)
        return 0;
    else
        return 1;
    
    

}

////////////////////////////////////////////////////////////////////////////////
bool checkBoard()//проверяет свободно ли место
{
    int count = 1;
    for (int i = 0; i < SZ; i++)
        for (int j = 0; j < SZ; j++, count++)
        {
            if (i == SZ-1 && j == SZ-1 && board[i][j] == 0)
                break;
            if (board[i][j] != count)
                return 0;
        }
    return 1;
}

////////////////////////////////////////////////////////////////////////////////
void showBoard()
{
    //cout << "15 P U Z Z L E";
    
    for (int i = 0; i < SZ; i++)
    {
        cout << "-------------\n";
        cout << "|";
        for (int j = 0; j < SZ; j++)
        {
            cout <<left<< setw(2)<< board[i][j]<< "|";
        }
        cout<<"\n";
    }
    cout << "-------------\n";
}
////////////////////////////////////////////////////////////////////////////////
void changeBoard()
{
    bool y = 0;
    while (!y)
    {
        int turn = 0;
        do
        {
            cout << "Choice:";
            cin >> turn;
        } while (turn < 0 || turn > 15);
        
        if (turn == 0)
        {
            mainMenu();
            return;
        }
        int getx = 0;
        int gety = 0;
        for (int i = 0; i < SZ; i++)
            for (int j = 0; j < SZ; j++)
                if (board[i][j] == turn)
                {
                    getx = i;
                    gety = j;
                }
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            int newx = getx + dx[i];
            int newy = gety + dy[i];
            if (newx < 0 || newx > SZ-1 ||
                newy < 0 || newy > SZ-1)
                continue;
            if (board[newx][newy] == 0)
            {
                board[newx][newy] = turn;
                board[getx][gety] = 0;
                y = 1;
                break;
            }
        }
        if (!y)
            cout << "Incorrect turn! Try again!\n";
    }
}
////////////////////////////////////////////////////////////////////////////////
void fillBoard()
{
    bool already[15] = {0};
    int count = 1;
    for (int i = 0; i < SZ; i++)
        for (int j = 0; j < SZ; j++, count++)
        {
            if (i == SZ-1 && j == SZ-1)
                break;
            while (true)
            {
                int randNum = rand()%15;
                if(!already[randNum])
                {
                    already[randNum] = 1;
                    board[i][j] = randNum+1;
                    break;
                }
            }
        }
}

/////////////////////////////////M A I N    M E N U//////////////////////////////
int main()
{
    mainMenu();
    return 0;
}