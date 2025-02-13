#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
using namespace std;

// Notes 
// 1. Buat Catatan
// 2. Hapus Catatan

string text;
string nama;
string isi;
char lagi;
bool lagibuat = false;
int pilihan;
int i=1;

void buat()
{
    cout << "\033[2J\033[1;1H";
    while (lagibuat=true)
    {
        cout << "nama catatan : ";
        cin >> nama;
        cout << "isi catatan : ";
        cin >> isi;

        ofstream file(nama+".txt");

        file << isi;

        file.close();

        cout << "buat lagi?(Y/N)...";
        cin >> lagi;
        if (lagi == 'n')
        {
            break;
        }
    }
}

void hapus()
{
    cout << "\033[2J\033[1;1H";
    cout << "file to remove : ";
    cin >> nama;
    if (remove(( nama.begin(),nama.end(),".txt" )) != 0)
        perror( "Error deleting file");
    else
        puts( "File Successfully deleted");
}

int main()
{

    while(true)
    {
        cout << "\033[2J\033[1;1H";
        cout << "1. Buat Catatan" << endl;
        cout << "2. Lihat Catatan" << endl;
        cout << "3. Hapus Catatan" << endl;
        cout << "===================" << endl;
        cout << "Pilihan(1-3) : ";
        cin >> pilihan;
        if (pilihan==1)
        {
            buat();
        }
        else if(pilihan==2)
        {

        }
        else if(pilihan==3)
        {
            hapus();
        }
        else
        {
            continue;
        }
    }
}