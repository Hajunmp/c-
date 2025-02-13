// Latihan OOP
// Turn Based Gaming 100

// Player Name = 
// Attack - Health
// 1. Serang (rand / pilihan serang)
// 2. Bertahan (tambahin 10)

// Enemy
// Attack (rand) - Health 


#include <iostream>
#include <windows.h>
using namespace std;

class calculate
{
    public:
        int angka1;
        int angka2;
        string symbol;
        int calc(int a, string sym, int b)
        {
            if (sym == "+")
            {
                return a+b;
            }
            else if (sym == "-")
            {
                return a-b;
            }
            else if (sym == "*")
            {
                return a*b;
            }
            else if (sym == "/")
            {
                if (b != 0)
                {
                    return a/b;
                }
                if (b == 0)
                {
                   return 0;
                }
            }
        }
};

int main()
{
    calculate eq;
    cout << " massukan angka 1 : ";
    cin >> eq.angka1;
    cout << "massukan angka 2 : ";
    cin >> eq.angka2;
    cout << "massukan simbol : ";
    cin >> eq.symbol;
    cout << "hasil : " << eq.calc(eq.angka1,eq.symbol,eq.angka2);
}