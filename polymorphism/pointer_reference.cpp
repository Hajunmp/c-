#include <iostream>

using namespace std;

string food = "pizza";
string &meal = food;

int main()
{
    cout << &food << endl;
    cout << meal << endl;
}