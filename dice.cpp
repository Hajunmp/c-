#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

string start;
string z;
int main()
{
    while (true)
    {
        int count = 1;
        cout << "\033[2J\033[1;1H";
        cout << "Dice Game" << endl;
        cout << "Type X to exit and anything else to roll the dice" << endl;
        cin >> start;
        if (start != "X")
        {
            while (count < 7)
            {
                cout << "\033[2J\033[1;1H";
                
                
                int face = rand() % 6;
                switch(face)
                {
                    case 0:
                        cout << "__________" << endl;
                        cout << "|        |" << endl;
                        cout << "|    *   |" << endl;
                        cout << "|        |" << endl;
                        cout << " --------" << endl;
                        break;
                    case 1:
                        cout << "__________" << endl;
                        cout << "|        |" << endl;
                        cout << "| *    * |" << endl;
                        cout << "|        |" << endl;
                        cout << " --------" << endl;
                        break;
                    case 2:
                        cout << "__________" << endl;
                        cout << "|       *|" << endl;
                        cout << "|    *   |" << endl;
                        cout << "| *      |" << endl;
                        cout << " --------" << endl;
                        break;
                    case 3:
                        cout << "__________" << endl;
                        cout << "| *    * |" << endl;
                        cout << "|        |" << endl;
                        cout << "| *    * |" << endl;
                        cout << " --------" << endl;
                        break;
                    case 4:
                        cout << "__________" << endl;
                        cout << "| *     *|" << endl;
                        cout << "|    *   |" << endl;
                        cout << "| *     *|" << endl;
                        cout << " --------" << endl;
                        break;
                    case 5:
                        cout << "__________" << endl;
                        cout << "| *    * |" << endl;
                        cout << "| *    * |" << endl;
                        cout << "| *    * |" << endl;
                        cout << " --------" << endl;
                        break;
                    
                }
                Sleep(500);
                count++;
            }
            cout << "type anything..." << endl;
            cin >> z;
        }
        else
        {break;}
    }
}