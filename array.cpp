#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;


// int number[3] = {3, 5, 6};
// string game[3];



// int main(){
//     game[0] = "Valorant";
//     game[2] = "Minecraft";
    
//     // cout << number[0] << endl;
//     // cout << number[1] << endl;
//     // cout << number[2] << endl;
//     for (int i = 0; i<3; i++)
//     {
//         cout << i+1 << "." << game[i] << endl;
//     }
// }

string books[5];
int pick;
int update;
string book;
int z;
bool confirm = 0;

int main()
{

    while (true)
    {
        int lenbook = sizeof(books)/sizeof(books[0]);
        cout << "\033[2J\033[1;1H";
        cout << lenbook;
        cout << "LIBRARY" << endl;
        cout << "1.Books" << endl;
        cout << "2.Update Book" << endl;
        cout << "3.Remove Book" << endl;
        cout << "=============== ";
        cin >> pick;
        if (pick == 1)
        {
            for (int i=0;i<5;i++)
            {
                if (books[i] == "")
                {
                    confirm = false;
                }
                else
                {
                    confirm = true;
                    break;
                }
            }
            for (int i=0;i<5;i++)
            {
                if (confirm == true)
                {
                    cout << i+1 << "." << books[i] << endl;
                }
                else
                {
                    cout << "There are no books" << endl;
                }
            }
            cout << "=";
            cin >> z;
            
        }
        else if(pick == 2)
        {
            for (int i=0;i<5;i++)
            {
                cout << i+1 << "." << books[i] << endl;
            }
            cout << "Update Book : ";
            cin >> update;
            cout << "Book Name : ";
            cin >> book;
            books[update-1] = book;
            cout << "=";
            cin >> z;
            
        }
        else if(pick == 3)
        {
            for (int i=0;i<5;i++)
            {
                cout << i+1 << "." << books[i] << endl;
            }
            cout << "Remove Book : ";
            cin >> update;
            books[update-1] = "";
            cout << "=";
            cin >> z;
            
        }
    }
}