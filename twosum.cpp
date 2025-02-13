#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

// Two Sums 2.0
// Mau masukin berapa angka? 5
// Targetnya berapa?
// Vector = {x,x,x,x,x}
// Target = x
// status = not found / [x,x]

vector<int> nums;
bool confirm = false;
int target;
int len;
int number;
string answer;
string x;

string index(int no, string ans)
{
    int cap[2];
    for (int i=0;i<nums.size()-1; i++)
    {
        for (int j=i+1;j<nums.size(); j++)
        {
            if (nums[i]+nums[j] == no)
            {
                cap[0] = i;
                cap[1] = j;
                confirm = true;
            }
        }
    }
    if (confirm == true)
    {
        ans = "["+to_string(cap[0])+", "+to_string(cap[1])+"]";
    }
    else
    {
        ans = "not found";
    }
    return ans;
    
}

int main()
{
    cout << "mau massukin berapa angka?...";
    cin >> len;
    for(int zz=0; zz < len; zz++)
    {
        cout << "massukin angka ke "+to_string(zz+1)+" : ";
        cin >> number;
        nums.push_back(number);
    }

    for(int x : nums)
    {
        cout << x << " ";
    }

    cout << "massukin target nomor : ";
    cin >> target;
    x = index(target, answer);
    cout << x << endl;
}