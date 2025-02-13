#include <iostream>
#include <windows.h>
using namespace std;

class mobil
{
    public:
        string warna_mobil = "hitam";
        string warna_ban = "abu abu";
        void method()
        {   
            cout << "mobil" << endl;
            cout << warna_mobil << endl;
            cout << warna_ban << endl;
        }
};


int main()
{
    mobil car;
    cout << car.warna_mobil << endl;
}