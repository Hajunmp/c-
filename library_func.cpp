#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

string books[5];
int pick;
int update;
string book;
bool confirm;
int x;

void view()
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
    cin >> x;
}
void change()
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
    cout << "=";
    cin >> x;
}

void remove()
{
    for (int i=0;i<5;i++)
    {
        cout << i+1 << "." << books[i] << endl;
    }
    cout << "Remove Book : ";
    cin >> update;
    books[update-1] = "";
    cout << "=";
    cin >> x;
}

int main()
{
    while (true)
    {
        cout << "\033[2J\033[1;1H";
        cout << "LIBRARY" << endl;
        cout << "1.Books" << endl;
        cout << "2.Update Book" << endl;
        cout << "3.Remove Book" << endl;
        cout << "=============== ";
        cin >> pick;
        if (pick == 1)
        {
            view();
            
        }
        else if (pick ==2)
        {
            change();
        }
        else if (pick == 3)
        {
            remove();
        }
        else
        {
            cout << "Please pick a number from the list" << endl << "=";
            cin >> x;
        }
    }
}