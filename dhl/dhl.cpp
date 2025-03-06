// DHL
// 1. Register (false=customer & true=admin)

// 2. Login
    // customer
    // 1. Send Package
    //  =  Nama Penerima, Alamat, Barang, Berat
    // 2. Status
    //  =  User, Nama Penerima, Alamat, Barang, Berat, Status(boarding, otw, arrive, broke)

    // admin
    // 1. Dashboard Package
    //  = mengatur status package
    // 2. User Control
    //  = liat semua akun customer

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

        int admin()
        {
            int choose;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "1. Dashboard Package" << endl;
            cout << "2. User Control" << endl;
            cout << "3. Exit" << endl;
            cin >> choose;
            if (choose==1)
            {

            }
            else if (choose==3)
            {
                return 0;
            }
        }
        int customer()
        {
            int choose;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "1. Send Package" << endl;
            cout << "2. Status" << endl;
            cout << "3. Exit" << endl;
            cin >> choose;
            if (choose==1)
            {
                
            }
            else if (choose==3)
            {
                return 0;
            }
        }
        int check(string a, string b)
        {
            bool exist = false;
            for (int i = 0; i < data_user.size(); i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << "\033[2J\033[1;1H";
                    if(data_user[i][0]==a)
                    {
                        if(data_user[i][1]==b)
                        {
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            cout << "Welcome, " << data_user[i][0] << endl;

                            if(data_user[i][2]=="true")
                            {
                                return 1;
                            }
                            else if(data_user[i][2]=="false")
                            {
                                return 0;
                            }
                        }
                    }
                }
            }
            if (exist==false)
            {
                return 2;
            }
        }
    };

    class user : public Db
    {
    public : 
        
    };
    class Regis : public user
    {
    public:
        int stop;
        bool x;
        void regis()
        {
            string a;
            string b;
            int c;
            bool d;
            while (x=true)
            {
                cout << "\033[2J\033[1;1H";
                cout << "|========================|" << endl;
                cout << "|        Register        |" << endl;
                cout << "|========================|" << endl;
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
                cout << "|Enter 0 to stop or 1 to continue...";
                cin >> stop;
                
                if (stop==0){
                    cout << "\033[2J\033[1;1H";
                    break;
                }
                else{
                    continue;
                }
            }
        }
        void logging()
        {
            string a;
            string b;
            int c;
            bool x;
            while(x=true)
            {
                cout << "\033[2J\033[1;1H";
                cout << "|========================|" << endl;
                cout << "|         Log In         |" << endl;
                cout << "|========================|" << endl;
                cout << "|Username : ";
                cin >> a;
                cout << "|Password : ";
                cin >> b;
                if (check(a, b)==1)
                {
                    if(admin()==0)
                    {
                        break;
                    }
                }
                else if(check(a, b)==0)
                {
                    if(customer()==0)
                    {
                        break;
                    }
                }
                else if(check(a, b)==2)
                {
                    cout << "Account does not exist" << endl;
                    cout << "Enter 0 to go back...";
                    cin >> c;
                    break;
                }
            }
        }
        void menu(){
            int choose;
            while(true)
            {
                cout << "\033[2J\033[1;1H";
                cout << "|=========================|" << endl;
                cout << "|        Main Menu        |" << endl;
                cout << "|=========================|" << endl;
                cout << "|1. Register " << endl;
                cout << "|2. Log In " << endl;
                cout << "|3. Exit " << endl;
                cout << "|=========================|" << endl;
                cin >> choose;
                if(choose==1)
                {
                    regis();
                }
                else if(choose==2)
                {
                    logging();
                }
                else if(choose==3)
                {
                    break;
                }
            }
        }
    };

    int main()
    {
        Regis a;
        a.menu();
    }