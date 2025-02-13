// CRUD
// Create, Read, Update, Delete

// Mau Berapa Nilai ?
// Nilai 1 - 
// dst

// 1. Rubah Nilai
// 2. Rata Rata Nilai
// 3. Nilai Terkecil
// 4. Nilai Terbesar

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

int berapa;
int pilih;
int ganti;
int gantinilai;
int clearing;

int rubah(int nilai3[])
{
    for(int i=0; i<berapa; i++)
    {
        cout << i+1 << ". " << nilai3[i] << endl;
    }
    cout << "rubah yang mana : ";
    cin >> ganti;
    cout << "nilai : ";
    cin >> gantinilai;
    nilai3[ganti-1] = gantinilai;
}

void ratarata(int nilai3[])
{
    int total = 0;
    for(int i=0;i<berapa;i++)
    {
        total += nilai3[i];
    }
    int rata = total/berapa;
    cout << "rata rata nilai siswa : " << rata << endl;
}

void minimum(int mini[])
{
    cout << "minimum nilai siswa : " << *min_element(mini, mini+berapa);
}

void maximum(int maxi[])
{
    cout << "maximum nilai siswa : " << *max_element(maxi, maxi+berapa);
}

void menu(int nilai2[])
{
    while (true)
    {
        cout << "\033[2J\033[1;1H";
        cout << "1. Rubah Nilai" << endl;
        cout << "2. Rata Rata Nilai" << endl;
        cout << "3. Nilai Terkecil" << endl;
        cout << "4. Nilai Terbesar" << endl;
        cout << " Pilihan : ";
        cin >> pilih;
        if (pilih == 1)
        {
            rubah(nilai2);
        }
        else if(pilih == 2)
        {
            ratarata(nilai2);
        }
        else if(pilih == 3)
        {
            minimum(nilai2);
        }
        else if(pilih == 4)
        {
            maximum(nilai2);
        }
        cout << endl << "====================" << endl;
        cin >> clearing;
    }
}


int main()
{
    cout << "berapa nilai siswa : ";
    cin >> berapa;
    int nilai[berapa];
    cout << "masukkan nilai nilai siswa" << endl;
    for (int i=0;i<berapa;i++)
    {
        cout << i+1 << ". ";
        cin >> nilai[i];
    }
    menu(nilai);
}