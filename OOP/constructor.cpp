#include <iostream>
#include <windows.h>
using namespace std;

class human
{
    public:
        int highscore;
        int health;
        human(int x, int heart)
        {
            highscore =  x;
            health = heart;
            cout << "high score : " << x << endl;
            cout << "---------------------" << endl;
            cout << "attack : 10" << endl;
            cout << "health : " << heart << endl;
        }
};
class enemy
{
    public:
        int health;
        enemy(int h)
        {
            health = h;
            cout << "Enemy" << endl;
            cout << "---------------------" << endl;
            cout << "Attack : 15" << endl;
            cout << "Health : " << h << endl;
        }
};
int serang;
char again;

void stat(int yy, int zz, int hearts)
{
    human a(yy, hearts);
    cout << "=============" << endl;
    enemy b(zz);
    cout << "=============" << endl;
}

int main()
{
    int y = 0;
    int pheart = 100;
    int z = 100;
    while (true)
    {
        cout << "\033[2J\033[1;1H";
        if (pheart<1)
        {
            cout << "GAME OVER" << endl;
            cout << "High Score : " << y << endl;
            break;
        }
        if (z<1)
        {
            stat(y, z, pheart);
            cout << "You win!" << endl;
            cout << "again?(Y/N)";
            cin >> again;
            if(again=='n')
            {
                break;
            }
            else
            {
                z = 100;
                cout << "\033[2J\033[1;1H";
            }
        }
        stat(y, z, pheart);
        cout << "1. serang" << endl;
        cout << "2. bertahan" << endl;
        cin >> serang;
        if (serang==1)
        {
            z -=10;
            y +=10;
            pheart -= 15;
        }
        else
        {
            if (pheart>110)
            {
                pheart = 120;
            }
            else
            {
                pheart += 10;
            }
        }
    }
}