#include <iostream>
#include <vector>
using namespace std;

vector<vector<string>> data_user;
string username;
string pass;
string verif;


void insert()
        {
            vector<string> row;
            row.clear();
            row.push_back(username);
            row.push_back(pass);
            row.push_back(verif); //string 
            data_user.push_back(row);
        }
void show()
        {
            cout << data_user.size();
            cout << "Data User = " << "\n";
            cout << "User -- Pass -- Status " << "\n";
            for (int i = 0; i < data_user.size(); i++)
            {
                cout << i + 1 << ". ";
                for (int j = 0; j < 3; j++)
                {
                    cout << "(" << data_user[i][j] << ")";
                }
                cout << "\n";
            }
        }

int main(){
    while (true)
    {
    cout << "name";
    cin >> username;
    cout << "pass";
    cin >> pass;
    cout << "verify";
    cin >> verif;
    insert();
    show();
    }
}