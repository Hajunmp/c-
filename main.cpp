#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// int i=0;
// int choice;
// int until;
// int main()
// {
//     cout << "ODD EVEN generator" << endl << "1. odd" << endl << "2. even" << endl << "pilihan : ";
//     cin >> choice ;
//     cout << "mau sampai angka berapa? : ";
//     cin >> until ;
//     if (choice == 1)
//     {
//         while (i<until)
//         {
//             i++;
//             cout << i << endl;
//             i++;
//         };
//     }
//     else if (choice == 2)
//     {
//     while (i<until)
//         {
//             cout << i << endl;
//             i+=2;
//         };
//     }
// }

int turns = 0;
int guess;

int main()
{
    int angka = rand() % 21;

    cout << "Guessing Number" << endl << "You Have 5 Chances To Guess The Number (1-20)" << endl;
    while (turns < 5)
    {
        cout << endl << "Guess : ";
        cin >> guess;
        if (guess>angka)
        {
            cout << "Too High";
        }
        else if (guess<angka)
        {
            cout << "Too Low";
        }
        else if (guess==angka)
        {
            cout << "Correct!";
            break;
        }
        turns++;
    }
}