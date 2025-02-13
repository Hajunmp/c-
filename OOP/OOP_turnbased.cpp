#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

class fighter
{
    public:
        string name;
        int chance;
        int p_attack;
        int p_health = 100;
        int turn;
        int use = 3;
        void show()
        {
            cout << name << endl;
            cout << "--------------------------" << endl;
            cout << "Attack : 5-15"<< endl;
            cout << "Health : " << p_health << endl;
            cout << "(*Maximum Health = 120*)" << endl;
        }
        void skills()
        {
            cout << "=========================" << endl;
            cout << "1. serang" << endl;
            cout << "2. atk boost (uses : "+to_string(use)+")" << endl;
            cout << "3. bertahan(+10 Health)" << endl;
            cout << "pilih (1-3)...";
            cin >> turn;
            if (turn == 1)
            {
                chance = rand() %3;
                if(chance==0)
                {
                    p_attack = 5;
                }
                else if (chance==1)
                {
                    p_attack = 10;
                }
                else if (chance==2)
                {
                    p_attack = 15;
                    cout << chance << endl;
                    cout << "Critical Hit!!!" << endl;
                    
                }
            }
            else if (turn==2)
            {
                if(use>0)
                {
                    p_attack = 25;
                    use -= 1;
                }
                else
                {
                    cout << "no more uses";
                    p_attack = 10;
                }
            }
            else if (turn==3)
            {
                p_attack = 0;
                if (p_health<120)
                {
                    p_health += 25;
                    cout << endl << "Health +10!!!" << endl;
                }
                else
                {
                    cout << endl << "Max Health!!!" << endl;
                }
            }
        }
};

class tank
{
    public:
        string name;
        int chance;
        int p_attack;
        int turn;
        int p_health = 200;
        int use = 3;
        void show()
        {
            cout << name << endl;
            cout << "--------------------------" << endl;
            cout << "Attack : 5-10"<< endl;
            cout << "Health : " << p_health << endl;
            cout << "(*Maximum Health = 120*)" << endl;
        }
        void skills()
        {
            cout << "1. serang" << endl;
            cout << "2. def boost (uses : "+to_string(use)+")" << endl;
            cout << "3. bertahan(+10 Health)" << endl;
            cout << "pilih (1-3)...";
            cin >> turn;
            if (turn == 1)
            {
                chance = rand() %2;
                if(chance==0)
                {
                    p_attack = 5;
                }
                else if (chance==1)
                {
                    p_attack = 10;
                }
            }
            else if (turn==2)
            {
                if(use>0)
                {
                    p_health += 25;
                    use -=1;
                }
                else
                {
                    cout << "no more uses";
                    p_attack = 10;
                }
            }
            else if (turn==3)
            {
                p_attack = 0;
                if (p_health<120)
                {
                    p_health += 25;
                    cout << endl << "Health +10!!!" << endl;
                }
                else
                {
                    cout << endl << "Max Health!!!" << endl;
                }
            }
        }
};

class assassin
{
    public:
        string name;
        int chance;
        int p_attack;
        int p_health = 80;
        int use = 3;
        int turn;
        void show()
        {
            cout << name << endl;
            cout << "--------------------------" << endl;
            cout << "Attack : 10-25"<< endl;
            cout << "Health : " << p_health << endl;
            cout << "(*Maximum Health = 120*)" << endl;
        }
        void skills()
        {
            cout << "1. serang" << endl;
            cout << "2. sneak atk (uses : "+to_string(use)+")" << endl;
            cout << "3. bertahan(+10 Health)" << endl;
            cout << "pilih (1-3)...";
            cin >> turn;
            if (turn == 1)
            {
                chance = rand() %3;
                if(chance==0)
                {
                    p_attack = 10;
                }
                else if (chance==1)
                {
                    p_attack = 15;
                }
                else if (chance==2)
                {
                    p_attack = 25;
                    cout << chance << endl;
                    cout << "Critical Hit!!!" << endl;
                    
                }
            }
            else if (turn==2)
            {
                if(use>0)
                {
                    p_attack = 35;
                    use-=1;
                }
                else
                {
                    cout << "no more uses";
                    p_attack = 10;
                }
            }
            else if (turn==3)
            {
                p_attack = 0;
                if (p_health<120)
                {
                    p_health += 25;
                    cout << endl << "Health +10!!!" << endl;
                }
                else
                {
                    cout << endl << "Max Health!!!" << endl;
                }
            }
        }
};

class enemy
{
    public:
        string type = "musuh";
        int e_attack = 15;
        int e_health = 100;
        void show()
        {
            cout << type << endl;
            cout << "--------------------------" << endl;
            cout << "Attack : " << e_attack << endl;
            cout << "Health : " << e_health << endl;
        }
};

int type;
int clear;

int main()
{
    srand(time(0));
    enemy musuh;
    cout << "choose your character type" << endl;
    cout << "1. fighter" << endl;
    cout << "2. tank" << endl;
    cout << "3. assassin" << endl;
    cin >> type;
    if(type==1)
    {
        fighter user;
        cout << "Name : ";
        cin >> user.name;
        while(true)
        {
                // user.chance = rand() %3;
                // srand(time(0));
                // system("cls");
            cout << "\033[2J\033[1;1H";
            user.show();
            cout << "=========================" << endl;
            musuh.show();
            if (user.p_health <1)
            {
                cout << "GAME OVER";
                break;
            }
            if (musuh.e_health <1)
            {
                cout << "YOU WIN!!!";
                break;
            }
            user.skills();
            
            musuh.e_health -= user.p_attack;
            cout << endl;
            cout << "Enemy Health -" + to_string(user.p_attack) << endl;
            user.p_health -= musuh.e_attack;
            cout << "Player Health -15" << endl;
                
            cout << "...";
            cin >> clear;
        }
    }
    else if(type==2)
    {
        tank user;
        cout << "Name : ";
        cin >> user.name;
        while(true)
        {
                // user.chance = rand() %3;
                // srand(time(0));
            cout << "\033[2J\033[1;1H";
            user.show();
            cout << "=========================" << endl;
            musuh.show();
            if (user.p_health <1)
            {
                cout << "GAME OVER";
                break;
            }
            if (musuh.e_health <1)
            {
                cout << "YOU WIN!!!";
                break;
            }
            user.skills();
                
            musuh.e_health -= user.p_attack;
            cout << endl;
            cout << "Enemy Health -" + to_string(user.p_attack) << endl;
            user.p_health -= musuh.e_attack;
            cout << "Player Health -15" << endl;
                
            cout << "...";
            cin >> clear;
        }
    }
    else if(type==3)
    {
        assassin user;
        cout << "Name : ";
        cin >> user.name;
        while(true)
        {
                // user.chance = rand() %3;
                // srand(time(0));
            cout << "\033[2J\033[1;1H";
            user.show();
            cout << "=========================" << endl;
            musuh.show();
            if (user.p_health <1)
            {
                cout << "GAME OVER";
                break;
            }
            if (musuh.e_health <1)
            {
                cout << "YOU WIN!!!";
                break;
            }
            user.skills();
                
            musuh.e_health -= user.p_attack;
            cout << endl;
            cout << "Enemy Health -" + to_string(user.p_attack) << endl;
            user.p_health -= musuh.e_attack;
            cout << "Player Health -15" << endl;
                
            cout << "...";
            cin >> clear;
        }
    }

}