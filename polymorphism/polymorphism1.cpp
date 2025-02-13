#include <iostream>

using namespace std;

class calculator
{
    public:
        int a;
        int b;
        void getnumber()
        {
            cout << "massukin angka ke satu : ";
            cin >> a ;
            cout << "massukin angka ke dua  : ";
            cin >> b ;
            // x = a;
            // y = b;
        }
};

class add : public calculator
{
    public:
        void calculate()
        {
             
        }
};

class subtract : public calculator
{
    public:
        int calculate()
        {
            return a-b;
        }
};
class multiply : public calculator
{
    public:
        int calculate()
        {
            return a*b;
        }
};
class divide : public calculator
{
    public:
        int calculate()
        {
            if(b!=0)
            {
                return a/b;
            }
            else if(b==0)
            {
                return 0;
            }
        }
};
int pick;


int main()
{
    cout << "polymorphism" << endl;
    calculator math;
    math.getnumber();
    cout << "1. add" << endl;
    cout << "2. subtract" << endl;
    cout << "3. multiply" << endl;
    cout << "4. divide" << endl;
    cout << "~~~";
    cin >> pick;
    if(pick==1)
    {
        add math;
        math.calculate();
    }
}