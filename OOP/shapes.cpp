#include <iostream>

using namespace std;
int choice;

class shapes
{
    public:
        int height;
        void tall()
        {
            cout << "Height of shape : ";
            cin >> height;
        }
};

class square : public shapes
{
    public:
        square()
        {
            tall();
            int a = 0;
            while (a <= height/2)
            {
                int j = 0;
                while (j <= height)
                {
                    cout << "x";
                    j = j+1;
                }
                a = a+1;
                cout << endl;
            }
        }

};

class rectangle : public shapes
{
    public:
        rectangle()
        {
            int a = 0;
            while (a <= height)
            {
                int j = 0;
                while (j <= height*2)
                {
                    cout << "x";
                    j = j+1;
                }
                a = a+1;
                cout << endl;
            }
        }
};

class triangle : public shapes
{
    public:
        triangle()
        {
            int a = 0;
            while (a <= height)
            {
                int j = 0;
                while (j <= a)
                {
                    cout << "x";
                    j = j+1;
                }
                a = a+1;
                cout << endl;
            }
        }
};

class parallelogram : public shapes
{
    public:
        parallelogram()
        {
            int a = 0;
            while (a <= height)
            {
                int i = 0;
                while (i <= a)
                {
                    cout << " ";
                    i = i+1;
                }
                int j = 0;
                while (j <= 10)
                {
                    cout << "x";
                    j = j+1;
                }
                a = a+1;
                cout << endl;
            }
        }
};

class diamond : public shapes
{
    public:
        diamond()
        {
            int a = 0;
            while (a <= 5)
            {
                int i = 5;
                while (a <= i)
                {
                    cout << " ";
                    i = i-1;
                }
    
                int j = 0;
                while (j <= a)
                {
                    cout << "x";
                    j = j+1;
                }
    
                int k = 0;
                while (k <= a)
                {
                    cout << "x";
                    k = k+1;
                }
                a = a+1;
                cout << endl;
            }
    
            int b=0;
            while (b <= 5)
            {
                int i = 0;
                while (i <= b)
                {
                    cout << " ";
                    i = i+1;
                }
    
                int j = 5;
                while (b <= j)
                {
                    cout << "x";
                    j = j-1;
                }
    
                int k = 5;
                while (b <= k)
                {
                    cout << "x";
                    k = k-1;
                }
                b = b+1;
                cout << endl;
            }
        }
};

class heart : public shapes
{
    public:
        heart()
        {
            int a = 0;
            while (a <= 2)
            {
                int i = 2;
                while (a <= i)
                {
                    cout << " ";
                    i = i-1;
                }
    
                int j = 0;
                while (j <= a)
                {
                    cout << "x";
                    j = j+1;
                }
    
                int k = 0;
                while (k <= a)
                {
                    cout << "x";
                    k = k+1;
                }
    
                int l = 1;
                while (a <= l)
                {
                    cout << "  ";
                    l = l-1;
                }
    
                int m = 0;
                while (m <= a)
                {
                    cout << "x";
                    m = m+1;
                }
    
                int n = 0;
                while (n <= a)
                {
                    cout << "x";
                    n = n+1;
                }
    
                a = a+1;
                cout << endl;
            }
    
            int b=0;
            while (b <= 5)
            {
                int i = 0;
                while (i <= b)
                {
                    cout << " ";
                    i = i+1;
                }
    
                int j = 5;
                while (b <= j)
                {
                    cout << "x";
                    j = j-1;
                }
    
                int k = 5;
                while (b <= k)
                {
                    cout << "x";
                    k = k-1;
                }
                b = b+1;
                cout << endl;
            }
        }
};

int main()
{
    cout << "pick a shape" << endl;
    cout << "1. square" << endl << "2. rectangle" << endl << "3. triangle" << endl << "4. parallelogram" << endl << "5. diamond" << endl << "6. heart" << endl;
    cout << "Choice : ";
    cin >> choice;
    if (choice==1)
    {
        square x;
    }
    else if (choice==2)
    {
        rectangle x;
    }
    else if (choice==3)
    {
        triangle x;
    }
    else if (choice==4)
    {
        parallelogram x;
    }
    else if (choice==5)
    {
        diamond x;
    }

    else if (choice==6)
    {
        heart x;
    }
}