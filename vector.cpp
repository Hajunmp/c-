#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

vector<string> books;
int pick;
int clearing;
string title;
int update;
bool doing = false;
char again;

void view()
{
    if (books.size()>0)
    {
        for (int i=0;i<books.size();i++)
        {
            cout << i+1 << "." << books[i] << endl;
        }
        cout << "=";
        cin >> clearing;
    }
    else
    {
        cout << "There are no books...";
        cin >> clearing;
    }
}

void add()
{
    while (doing = true)
    {
        cout << "\033[2J\033[1;1H";
        cout << "Book Title : ";
        cin >> title;
        books.push_back(title);
        cout << "Book has been added..." << endl << endl;
        cout << "Would you like to add another book?(Y/N)  | ";
        cin >> again;
        if (again == 'y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
}

void change()
{
    if (books.size()>0)
    {
        while (doing = true)
        {
            cout << "\033[2J\033[1;1H";
            for (int i=0;i<books.size();i++)
            {
                cout << i+1 << "." << books[i] << endl;
            }
            cout << "Book index : ";
            cin >> update;
            cout << "Book Name : ";
            cin >> title;
            books[update-1] = title;
            cout << "Book has been updated..." << endl << endl;
            cout << "Would you like to update another book?(Y/N)  | ";
            cin >> again;
            if (again == 'y')
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        cout << "There are no books...";
        cin >> clearing;
    }
}

void remove()
{
    if (books.size()>0)
    {
        while (doing = true)
        {
            if (books.size()<1)
            {
                break;
            }
            
            for (int i=0;i<books.size();i++)
            {
                cout << i+1 << "." << books[i] << endl;
            }
        
            cout << "Remove Book : ";
            cin >> update;
            
            
            books.erase(books.begin() + (update-1));
            
            cout << "Book has been removed..." << endl << endl;
            cout << "Would you like to remove another book?(Y/N)  | ";
            cin >> again;
            if (again == 'y')
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        cout << "There are no books in the library... ";
        cin >> clearing;
    }
}


int main()
{
    while (true)
    {
        cout << "\033[2J\033[1;1H";
        cout << "LIBRARY" << endl;
        cout << endl << "====================" << endl;
        cout << "1. View Books" << endl;
        cout << "2. Add Books" << endl;
        cout << "3. Update Books" << endl;
        cout << "4. Remove Books" << endl;
        cout << "====================" << endl;
        cout << "Choice : ";
        cin >> pick;
        if (pick == 1)
        {
            view();
        }
        else if (pick == 2)
        {
            // if true then what, false then what
            add();
        }
        else if (pick == 3)
        {
            change();
        }
        else if (pick == 4)
        {
            remove();
        }
    }
}