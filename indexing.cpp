#include <iostream>
#include <windows.h>
using namespace std;

// Two Sums
// Array(sum) , Int(target)

// sum = [9,4,7,1]
// target = 10 = No Result
// target = 13 = [0,1]
// target = 8 = [2,3]
// target = 7 = No Result


string name = "Nithin";

int main()
{
    for(int i=0; i<name.size(); i++)
    {
        cout << "\033[2J\033[1;1H";
        if (tolower(name[i])=='a')
        {
            cout << "you got an A" << endl;
            break;
        }
        else 
        {
            cout << "you got no A" << endl;
        }
    }
}