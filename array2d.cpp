#include <iostream>
#include <windows.h>
using namespace std;

string subjects[5][3];
string sub;
char Qchange;
int daysub;
int changesub;
string newsub;


void show()
{
    cout << "Monday   | " << subjects[0][0] << " ," << subjects[0][1] << " ," << subjects[0][2] << endl;
    cout << "Tuesday  | " << subjects[1][0] << " ," << subjects[1][1] << " ," << subjects[1][2] << endl;
    cout << "Wednesday| " << subjects[2][0] << " ," << subjects[2][1] << " ," << subjects[2][2] << endl;
    cout << "Thursday | " << subjects[3][0] << " ," << subjects[3][1] << " ," << subjects[3][2] << endl;
    cout << "Friday   | " << subjects[4][0] << " ," << subjects[4][1] << " ," << subjects[4][2] << endl;
}

void change()
{
    cout << "Day(1-5) : ";
    cin >> daysub;
    cout << "Subject(1-3) : ";
    cin >> changesub;
    cout << "Change subject to : ";
    cin >> newsub;
    subjects[daysub-1][changesub-1] = newsub;
}

int main()
{
    cout << "Schedule" << endl ;
    for (int i = 0; i<5; i++)
    {
        cout << "\033[2J\033[1;1H";
        cout << "DAY " << i+1 << endl;
        for (int j = 0; j<3; j++)
        {
            cout << "Subject " << j+1 << " : ";
            cin >> sub;
            subjects[i][j] = sub;
        }
    }
    while (true)
    {
        cout << "\033[2J\033[1;1H";
        show();
        cout << endl << "Would you like to change anything?(Y/N)  | ";
        cin >> Qchange;
        tolower(Qchange);
        if (Qchange == 'y')
        {
            change();
        }
        else
        {
            break;
        }
    }
}