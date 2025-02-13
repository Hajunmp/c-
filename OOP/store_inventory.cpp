#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <string>
#include <numeric>

using namespace std;

class var
{
    public:
        int index;
        int amount;
        int money = 1000000;
        int price;
        int depositing;
        int no_words;
        string title;
        vector<vector<int>> game_price = {{0, 80000, 1},{1, 100000, 1},{2, 300000, 1},{3, 150000, 1},{4, 100000, 1},{5, 80000, 1}};
        vector<string> games = {"Lethal Company", "Subnautica", "Resident Evil 4", "Poppy Playtime", "Phasmophobia", "Sons of The Forest"}; 
        vector<string> addgame = {"title"};
        int title_index = games.size();  
};

class store: public var
{
    private:
        int bank;
    public:
        void inventory()
        {
            cout << "title ~ price ~ stock" << endl;
            cout << "====================================" << endl;
            for(int i=0; i<games.size(); i++)
            {
                cout << i+1 << ". " << games[game_price[i][0]] << " ~ $" << game_price[i][1] << " ~ " << game_price[i][2] << endl;
            }
        }
        void add()
        {
            cout << "Add a game to buy or sell..." << endl;
            cout << "How many words in the title?...";
            cin >> no_words;
            for(int i=1;i<no_words+1;i++)
            {
                addgame.push_back("title"+to_string(i));
            }
        

            cout << "Game Title: ";
            for(int i=1;i<no_words+1;i++)
            {
                cin >> addgame[i];
                addgame[i] = addgame[i]+" ";
            }
            
            title = accumulate(begin(addgame)+1, end(addgame), title);
            // title = addgame[1]+" "+addgame[2];
            cout << "Game Price : ";
            cin >> price;
            games.push_back(title);
            game_price.push_back({title_index, price, 0});
        }
        void buy()
        {
            cout << "Which game would you like to buy? : ";
            cin >> index;
            cout << "How many? : ";
            cin >> amount;
            if (money >= game_price[index-1][1]*amount)
            {
                money -= game_price[index-1][1]*amount;
                game_price[index-1][2] += amount;
                cout << "Games successfully bought" << endl;
            }
            else if (money < game_price[index-1][1]*amount)
            {
                cout << "Not Enough Money" << endl;
            }
        }
        void sell()
        {
            cout << "Which game would you like to sell? : ";
            cin >> index;
            cout << "How many? : ";
            cin >> amount;
            if (game_price[index-1][2] >= amount)
            {
                money += game_price[index-1][1]*amount;
                game_price[index-1][2] -= amount;
                cout << "Games successfully sold" << endl;
            }
            else
            {
                cout << "Not Enough Stock" << endl;
            }
        }
        void deposit()
        {
            cout << "How much money would you like to deposit?";
            cin >> depositing;
            money += depositing;
            cout << "money successfully stored" << endl;
        }
        void setBank()
        {
            bank = money;
        }
        int getBank()
        {
            return bank;
        }
        void cash()
        {
            cout << "Your Money = " << money << endl;
        }
};
int choose;

int main()
{
    store steam;
    while(true)
    {
        cout << "Welcome to Steam Store" << endl;
        steam.cash();
        steam.inventory();
        cout << "====================================" << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Add " << endl;
        cout << "2. Buy " << endl;
        cout << "3. Sell" << endl;
        cout << "4. deposit" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice : ";
        cin >> choose;
        if (choose == 1)
        {
            steam.add();
        }
        else if(choose == 2)
        {
            steam.buy();
        }
        else if(choose == 3)
        {
            steam.sell();
        }
        else if(choose == 4)
        {
            steam.deposit();
        }
        else if(choose == 5)
        {
            cout << "\033[2J\033[1;1H";
            break;
        }
        cout << "\033[2J\033[1;1H";
    }
}