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
        }
};

class add : public calculator
{
    public:
        int calculate()
        {
             return a+b;
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
            if (b==0) 
            {
                return 0;
            }
            return a/b;
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
        add maths;
        maths.a = math.a;
        maths.b = math.b;
        cout << maths.a << " + " << maths.b << " = " << maths.calculate();
    }
    else if(pick==2)
    {
        subtract maths;
        maths.a = math.a;
        maths.b = math.b;
        cout << maths.a << " - " << maths.b << " = " << maths.calculate();
    }
    else if(pick==3)
    {
        multiply maths;
        maths.a = math.a;
        maths.b = math.b;
        cout << maths.a << "*" << maths.b << " = " << maths.calculate();
    }
    else if(pick==4)
    {
        divide maths;
        maths.a = math.a;
        maths.b = math.b;
        if (maths.calculate() == 0)
        {
            cout << "Cannot divide by 0" << endl;
        }
        else if (maths.calculate() != 0)
        cout << maths.a << "/" << maths.b << " = " << maths.calculate();
    }
}