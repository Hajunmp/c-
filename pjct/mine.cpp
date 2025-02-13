#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <bits/stdc++.h>
#include <random>
using namespace std;

string mine[16] = {"_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_"};
string reveal[16] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};
string after[16];
int capacity;
// int bomb[5] = {5,6,2,8,3};
int open;
int clearing;
bool playing;

void sandbox()
{
    cout << "1 |" << mine[0] << "| 2 |" << mine[1] << "| 3 |" << mine[2] << "| 4 |" << mine[3] << "|" << endl;
    cout << "5 |" << mine[4] << "| 6 |" << mine[5] << "| 7 |" << mine[6] << "| 8 |" << mine[7] << "|" << endl;
    cout << "9 |" << mine[8] << "| 10|" << mine[9] << "| 11|" << mine[10] << "| 12|" << mine[11] << "|" << endl;
    cout << "13|" << mine[12] << "| 14|" << mine[13] << "| 15|" << mine[14] << "| 16|" << mine[15] << "|" << endl;

    // cout << "1 |" << reveal[0] << "| 2 |" << reveal[1] << "| 3 |" << reveal[2] << "| 4 |" << reveal[3] << "|" << endl;
    // cout << "5 |" << reveal[4] << "| 6 |" << reveal[5] << "| 7 |" << reveal[6] << "| 8 |" << reveal[7] << "|" << endl;
    // cout << "9 |" << reveal[8] << "| 10|" << reveal[9] << "| 11|" << reveal[10] << "| 12|" << reveal[11] << "|" << endl;
    // cout << "13|" << reveal[12] << "| 14|" << reveal[13] << "| 15|" << reveal[14] << "| 16|" << reveal[15] << "|" << endl;
}

// Logic Bomb 
// Input (How Many u Want Bomb <- for capacity)
// srand(time(0))
// rand(% 11) = 0-15  <- looping sesuai capacity

// jika posisi sesuai yang ada dibomb, maka replace "_" -> "*"
// jika "*" maka "dor"

int turn()
{
    cout << "reveal box : ";
    cin >> open;
    if (mine[open-1]!="_")
    {
        cout << "please choose another box";
    }
    else
    {
        mine[open-1] = reveal[open-1];
        reveal[open-1] = "_";
    }
}

bool wincheck()
{
    bool player;
    for (int i=0;i<16;i++)
    {
        for (int j=0;j<16;j++)
        {
            if (reveal[j] == "0")
            {
                player = true;
                break;
            }
            else if(reveal[j] == "1")
            {
                player = true;
                break;
            }
            else
            {
                player = false;
            }
        }
        if (mine[i] == "*")
            {
                mine[i] = after[i];
                cout << "\033[2J\033[1;1H";
                sandbox();
                cout << "===== YOU LOST =====";
                return false;
            }
        else if (player == false)
            {
                mine[i] = after[i];
                cout << "\033[2J\033[1;1H";
                sandbox();
                cout << "===== YOU WON =====";
                return false;
            }
    }
}

void game()
{
    while (playing=true)
    {
        cout << "\033[2J\033[1;1H";
        sandbox();
        turn();
        wincheck();
        if (wincheck == false)
        {
            exit(0);
        }
        cout << "==";
        cin >> clearing;
    }
}

void bombcap()
{
    int bomb[capacity];
    srand(time(0));
    if (capacity < 2)
    {
        bomb[0] = rand()%15;
        reveal[bomb[0]] = "*" ;
    }
    else
    {
        for (int i=0;i<capacity;i++)
        {
            for (int j=0;j<capacity;j++)
            {
                bomb[i] = rand()%15;
                if (bomb[i] != bomb[j])
                {
                    reveal[bomb[i]] = "*" ;
                    break;
                }
                
            }
        }
    }
    for (int i=0;i<16;i++)
    {
        if (reveal[i] == "*" && i>0 && i<3)
        {
            if (reveal[i+1] != "*")
            {
                reveal[i+1] = "1";
            }
            if (reveal[i-1] != "*")
            {
                reveal[i-1] = "1";
            }
            if (reveal[i+4] != "*")
            {
                reveal[i+4] = "1";
            }
        }
        else if (reveal[i] == "*" && i>4 && i<7)
        {
            if (reveal[i+1] != "*")
            {
                reveal[i+1] = "1";
            }
            if (reveal[i-1] != "*")
            {
                reveal[i-1] = "1";
            }
            if (reveal[i+4] != "*")
            {
                reveal[i+4] = "1";
            }
            if (reveal[i-4] != "*")
            {
                reveal[i-4] = "1";
            }
        }
        else if (reveal[i] == "*" && i>8 && i<11)
        {
            if (reveal[i+1] != "*")
            {
                reveal[i+1] = "1";
            }
            if (reveal[i-1] != "*")
            {
                reveal[i-1] = "1";
            }
            if (reveal[i+4] != "*")
            {
                reveal[i+4] = "1";
            }
            if (reveal[i-4] != "*")
            {
                reveal[i-4] = "1";
            }
        }
        else if (reveal[i] == "*" && i>9 && i<15)
        {
            if (reveal[i+1] != "*")
            {
                reveal[i+1] = "1";
            }
            if (reveal[i-1] != "*")
            {
                reveal[i-1] = "1";
            }
            if (reveal[i-4] != "*")
            {
                reveal[i-4] = "1";
            }
        }
        else if (reveal[i] == "*" && i==0)
        {
            if (reveal[i+1] != "*")
            {
                reveal[i+1] = "1";
            }
            if (reveal[i+4] != "*")
            {
                reveal[i+4] = "1";
            }
        }
        else if (reveal[i] == "*" && i==3)
        {
            if (reveal[i-1] != "*")
            {
                reveal[i-1] = "1";
            }
            if (reveal[i+4] != "*")
            {
                reveal[i+4] = "1";
            }
        }
        else if (reveal[i] == "*" && i==4)
        {
            if (reveal[i+1] != "*")
            {
                reveal[i+1] = "1";
            }
            if (reveal[i+4] != "*")
            {
                reveal[i+4] = "1";
            }
            if (reveal[i-4] != "*")
            {
                reveal[i-4] = "1";
            }
        }
        else if (reveal[i] == "*" && i==7)
        {
            if (reveal[i-1] != "*")
            {
                reveal[i-1] = "1";
            }
            if (reveal[i+4] != "*")
            {
                reveal[i+4] = "1";
            }
            if (reveal[i-4] != "*")
            {
                reveal[i-4] = "1";
            }
        }
        else if (reveal[i] == "*" && i==8)
        {
            if (reveal[i+1] != "*")
            {
                reveal[i+1] = "1";
            }
            if (reveal[i+4] != "*")
            {
                reveal[i+4] = "1";
            }
            if (reveal[i-4] != "*")
            {
                reveal[i-4] = "1";
            }
        }
        else if (reveal[i] == "*" && i==11)
        {
            if (reveal[i-1] != "*")
            {
                reveal[i-1] = "1";
            }
            if (reveal[i+4] != "*")
            {
                reveal[i+4] = "1";
            }
            if (reveal[i-4] != "*")
            {
                reveal[i-4] = "1";
            }
        }
        else if (reveal[i] == "*" && i==12)
        {
            if (reveal[i+1] != "*")
            {
                reveal[i+1] = "1";
            }
            if (reveal[i-4] != "*")
            {
                reveal[i-4] = "1";
            }
        }
        else if (reveal[i] == "*" && i==15)
        {
            if (reveal[i-1] != "*")
            {
                reveal[i-1] = "1";
            }
            if (reveal[i-4] != "*")
            {
                reveal[i-4] = "1";
            }
        }
        after[i] = reveal[i];
    }
    game();
}

int main()
{
    cout << "Welcome to Minesweeper" << endl;
    while (true)
    {
        cout << "Choose the amount of mines(1-5) : ";
        cin >> capacity;
        if (capacity>6 && capacity<1)
        {
            cout << "choose another number" << endl;
        } 
        else
        {
            bombcap();
        }

    }
}