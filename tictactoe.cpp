#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

string box[9] = {"_", "_", "_", "_", "_", "_", "_", "_", "_"};
int number;

void thebox()
{
    cout << "TIC-TAC-TOE" << endl;
    cout << "1|" << box[0] << "| 2|" << box[1] << "| 3|" << box[2] << "|" << endl;
    cout << "4|" << box[3] << "| 5|" << box[4] << "| 6|" << box[5] << "|" << endl;
    cout << "7|" << box[6] << "| 8|" << box[7] << "| 9|" << box[8] << "|" << endl;
}

void picknumber(string letter)
{
    while (true)
    {
        cout << "Player " << letter << " turn, pick a number : ";
        cin >> number;
        if (number>0, number<10, box[number-1]=="_")
        {
            box[number-1] = letter;
            break;
        }
        else
        {
            cout << "Please pick another number..." << endl;
        }
    }
}

bool wincheck(string winner)
{
    bool confirm = false;
    if (box[0]==box[1] && box[1]==box[2] && box[0]!="_")
    {
        cout << "\033[2J\033[1;1H";
        thebox();
        cout << "player" << winner << "has won!";
        return true;
    }
    else if (box[3]==box[4] && box[4]==box[5] && box[3]!="_")
    {
        cout << "\033[2J\033[1;1H";
        thebox();
        cout << "player" << winner << "has won!";
        return true;
    }
    else if (box[6]==box[7] && box[7]==box[8] && box[6]!="_")
    {
        cout << "\033[2J\033[1;1H";
        thebox();
        cout << "player" << winner << "has won!";
        return true;
    }
    else if (box[0]==box[3] && box[3]==box[6] && box[0]!="_")
    {
        cout << "\033[2J\033[1;1H";
        thebox();
        cout << "player" << winner << "has won!";
        return true;
    }
    else if (box[1]==box[4] && box[4]==box[7] && box[1]!="_")
    {
        cout << "\033[2J\033[1;1H";
        thebox();
        cout << "player" << winner << "has won!";
        return true;
    }
    else if (box[2]==box[5] && box[5]==box[8] && box[2]!="_")
    {
        cout << "\033[2J\033[1;1H";
        thebox();
        cout << "player" << winner << "has won!";
        return true;
    }
    else if (box[0]==box[4] && box[4]==box[8] && box[0]!="_")
    {
        cout << "\033[2J\033[1;1H";
        thebox();
        cout << "player" << winner << "has won!";
        return true;
    }
    else if (box[2]==box[4] && box[4]==box[6] && box[2]!="_")
    {
        cout << "\033[2J\033[1;1H";
        thebox();
        cout << "player" << winner << "has won!";
        return true;
    }
    for(int i=0;i<9;i++)
    {
        if (box[i]=="_")
        {
            confirm = false;
            break;
        }
        else
        {
            confirm = true;
        }
    }
    if (confirm == false)
    {
        return false;
    }
    else
    {
        cout << "\033[2J\033[1;1H";
        thebox();
        cout << "TIE!!!";
        return true;
    }
}

int main()
{
    string player = "X";
    while (true)
    {
        thebox();
        if (player == "X")
        {
            picknumber("X");
            if (wincheck("X") == true)
            {
                break;
            }
            player = "O";
        }
        else if (player == "O")
        {
            picknumber("O");
            if (wincheck("O") == true)
            {
                break;
            }
            player = "X";
        }
        cout << "\033[2J\033[1;1H";

        
    }
}