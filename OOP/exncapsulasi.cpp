#include <iostream>
#include <windows.h>
using namespace std;

int ambil;

class angpao
{
    private:
        int money;
    public:
        int duit = 0;
        int x;
        void setMoney()
        {
            money = duit;
        }
        int getMoney()
        {
            return money;
        }
        void ambil_duit()
        {
            cout << "duit kamu = " << duit;
        }
};

int main()
{
    angpao dapat;
    cout << " jumlah angpao : ";
    cin >> dapat.x;
    cout << "1. ambil angpao" << endl;
    cout << "2. tidak ambil angpao" << endl;
    cin >> ambil;
    if(ambil==1)
    {
        dapat.duit = dapat.x;
    }
    dapat.ambil_duit();
}