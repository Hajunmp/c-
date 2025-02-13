#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

// Menu
// 1. Add (+)
// 2. Minus (-)
// 3. Multiply (x)
// 4. Divide (/)
//  = 

// First Number = 
// Second Number = 
// Result = 

int pick;
int one;
int two;
int result;
string math;
int x;

int add(int one, int two)
{
    result = one+two;
    return result;
}

int subtract(int one, int two)
{
    result = one-two;
    return result;
}

int multiply(int one, int two)
{
    result = one*two;
    return result;
}

int divide(int one, int two)
{
    result = one/two;
    return result;
}

int main()
{
    while (true)
    {
        
        cout << "\033[2J\033[1;1H";
        cout << "CALCULATOR" << endl;
        cout << "1. Add (+)" << endl;
        cout << "2. Subtract (-)" << endl;
        cout << "3. Multiply (*)" << endl;
        cout << "4. Divide (/)" << endl;
        cout << "=";
        cin >> pick;
        cout << endl << "First Number = ";
        cin >> one;
        cout << "Second Number = ";
        cin >> two;
        if (pick == 1)
        {
            add(one, two);
            math = "+";
        }
        else if(pick == 2)
        {
            subtract(one, two);
            math = "-";
        }
        else if(pick == 3)
        {
            multiply(one, two);
            math = "*";
        }
        else if(pick == 4)
        {
            divide(one, two);
            math = "/";
        }
        
        cout << "result = " << one << math << two << " = " << result << endl;
        cin >> x;
    }
}