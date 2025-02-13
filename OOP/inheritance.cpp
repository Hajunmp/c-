#include <iostream>
#include <windows.h>
using namespace std;

class parent
{
    public:
        int duit;
    int ask(){
        cout << "how many?";
        cin >> duit;
        return duit;
    }
};

class child: public parent
{
    public:
        int ambil;
        int ambil_angpao()
        {
            cout << "1. ambil angpao" << endl;
            cout << "2. tidak ambil angpao" << endl;
            cin >> ambil;
            if(ambil==1)
            {
                cout << "duit = " << duit;
            }
            else if(ambil==2)
            {
                duit = 0;
                cout << "duit = " << duit;
            }
        }
};

int main(){
    child a;
    a.ask();
    a.ambil_angpao();
}