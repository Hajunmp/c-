#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

// 1. Breadsticks = 76.000
// 2. Molten Lava = 91.000
// 3. Banana Split = 87.000
// 4. American Classic = 109.000
// 5. Grilled Beef = 111.000
// 6. Lychee Tea = 15.000
// 7. Peach Tea = 15.000
// 8. Taro Milk = 17.000

// vector int = 2D (index food, price)
// vector string = 1D (food name)


vector<vector<int>> price = {{1, 76000}, {2, 91000}, {3, 87000}, {4, 109000}, {5, 111000}, {6, 15000}, {7, 15000}, {8, 17000}};
vector<string> menu = {"Breadsticks", "Molten Lava", "Banana Split", "American Classic", "Grilled Beef", "Lychee Tea", "Peach Tea", "Taro Milk"};
int money = 300000;
int pick;
int add;
int clearing;

void atm()
{
    cout << "======== ATM ========" << endl;
    cout << "1. Show Money" << endl;
    cout << "2. Add Money" << endl;
    cin >> pick;
    if (pick == 1)
    {
        cout << "Balance : " << money << endl;
        cout << "=";
        cin >> clearing;
    }
    else if (pick == 2)
    {
        cout << "How much money would you like to add?  | ";
        cin >> add;
        money += add;
        cout << "Money successfully added...";
        cin >> clearing;
    }
}

int main()
{
    // Welcome
    while (true)
    {
        cout << "\033[2J\033[1;1H";
        cout << "Welcome to Johnny's" << endl;
        for (int i=0; i<price.size(); i++)
        {
            cout << i+1 << ". " << menu[price[i][0]-1] << " : " << price[i][1] << endl;
        }
        // Welcome
        atm();
    }

    // ATM
    // 1. Show Money
    // 2. Add Money
    // ATM

}