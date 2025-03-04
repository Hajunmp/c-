// DHL
// 1. Register (false=customer & true=admin)

// 2. Login
    // customer
    // 1. Send Package
    // 2. Status

    // admin
    // 1. Dashboard Package
    // 2. User Control

    #include <iostream>
    #include <vector>
    #include <string>
    #include <fstream>
    using namespace std;
    class Db
    {
    private:
        vector<vector<string>> data_user;
        string username;
        string pass;
        bool verif;
    
    public:
        string bool_to_str(bool a)
        {
            string b = a ? "true" : "false";
            return b;
        }
        void set(string a, string b, bool c)
        {
            username = a;
            pass = b;
            verif = c;
        }
        void insert()
        {
            vector<string> row;
            row.clear();
            row.push_back(username);
            row.push_back(pass);
            row.push_back(bool_to_str(verif)); //string 
            data_user.push_back(row);
        }
        void show()
        {
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

        void admin()
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "1. Dashboard Package" << endl;
            cout << "2. User Control" << endl;
        }
        void customer()
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "1. Send Package" << endl;
            cout << "2. Status" << endl;

        }
        void check(string a, string b)
        {
            for (int i = 0; i < data_user.size(); i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if(data_user[i][0]==a)
                    {
                        if(data_user[i][1]==b)
                        {
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            cout << "Welcome, " << data_user[i][0];
                            if(data_user[i][2]=="true")
                            {
                                admin();
                            }
                            else if(data_user[i][2]=="false")
                            {
                                customer();
                            }
                            break;
                        }
                    }
                }
            }
            cout << "Account does not exist" << endl;
        }
    };
    class Regis : public Db
    {
    public:
        string a;
        string b;
        int c;
        bool d;
        int stop;
        bool x;
        Regis()
        {
            while (x=true)
            {
                cout << "|========================|" << endl;
                cout << "|        Register        |" << endl;
                cout << "|========================|" << endl;
                cout << "|Enter 0 to stop or 1 to continue...";
                cin >> stop;
                if (stop==0)
                {
                    cout << "\033[2J\033[1;1H";
                    break;
                }else{

                    cout << "|Username : ";
                    cin >> a;
                    cout << "|Password : ";
                    cin >> b;
                    cout << "(1)Admin or (2)Customer = ";
                    cin >> c;
    
                    if (c==1){
                        d=true;
                    }
                    else if(c==2){
                        d=false;
                    }
    
                    set(a, b, d);
                    insert();
                    show();
                }

            }
        }
    };

    class Login : public Db
    {
    public:
        string a;
        string b;
        bool x;
        void Logging()
        {
            while(x=true)
            {
                cout << "|========================|" << endl;
                cout << "|         Log In         |" << endl;
                cout << "|========================|" << endl;
                cout << "|Username : ";
                cin >> a;
                cout << "|Password : ";
                cin >> b;
                cout << "\033[2J\033[1;1H";
                check(a, b);
            }
        }
    };

    int main()
    {
        Regis a;
        Login b;
        b.Logging();
    }