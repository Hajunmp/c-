#include <iostream>
using namespace std;
int total = 0;
int berapa;

int hitungratarata(int arr[], int n) 
{
    
    for (int i = 1; i <= n; i++) // i=1
    {
        total += arr[i];
    }
    return total/n;
}

int main()
{
    cout << "berapa nilai siswa : ";
    cin >> berapa;
    int nilai[berapa];
    cout << "Masukkan " << berapa << " nilai siswa: ";
    for (int i = 1; i <= berapa; i++) 
    {
        cin >> nilai[i];
    }
    int rata = hitungratarata(nilai, berapa);
    
    cout << "Rata-rata nilai siswa adalah: " << rata << endl;
    
    return 0;
}
