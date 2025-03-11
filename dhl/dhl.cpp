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
    //  = bisa menghapus akun dan update (password) akun customer

    #include <iostream>
    #include <vector>
    #include <string>
    #include <fstream>
    using namespace std;

    class Db
    {
    private:
    //register
        vector<vector<string>> data_user;
        string username;
        string pass;
        bool verif;

    //package
        vector<vector<string>> package;
        string receiver;
        string address;
        string object;
        string weight;
        string status;
    
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
                            username = data_user[i][0];
                            pass = data_user[i][1];

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
        void set2(string a, string b, string c, string d)
        {
            receiver = a;
            address = b;
            object = c;
            weight = d;
            status = "boarding";
        }
        void insert2()
        {
            vector<string> row;
            row.clear();
            row.push_back(username);
            row.push_back(pass);
            row.push_back(receiver);
            row.push_back(address);
            row.push_back(object);
            row.push_back(weight);
            row.push_back(status);
            package.push_back(row);
        }
        void package_status()
        {
            cout << "\033[2J\033[1;1H";
            bool exist = false;
            int stop;
            cout << "Package info = " << "\n";
            cout << "User -- pass -- receiver -- address -- object -- weight -- Status " << "\n";
            for (int i = 0; i < package.size(); i++)
            {
                if(package[i][0]==username)
                {   
                    if(package[i][1]==pass)
                    {
                        exist = true;
                        for (int j = 0; j < 7; j++)
                        {
                            cout << "(" << package[i][j] << ")";
                        }
                        cout << "\n";
                    }
                }
            }
            if (exist == false)
            {
                cout << "No Packages..." << endl;
            }
            cout << "Enter 0 to continue...";
            cin >> stop;
            cout << "\033[2J\033[1;1H";
            return;
        }

        void dashboard()
        {
            int num;
            int choose;
            int stop;
            bool x;
            while(x=true)
            {
                cout << "Package info = " << "\n";
                cout << "User -- pass -- receiver -- address -- object -- weight -- Status " << "\n";
                for (int i = 0; i < package.size(); i++)
                {
                    cout << i+1 << ". ";
                    for (int j = 0; j < 7; j++)
                    {
                        cout << "(" << package[i][j] << ")";
                    }
                    cout << "\n";
                }
                cout << "Change user no. ";
                cin >> num;
                cout << "\033[2J\033[1;1H";
                cout << "|========================|" << endl;
                cout << "|      Update Status     |" << endl;
                cout << "|========================|" << endl;
                cout << "| user : " << package[num-1][0] << endl;
                cout << "| status : " << package[num-1][6] << endl;
                cout << "|------------------------|" << endl;
                cout << "| 1. Boarding            |" << endl;
                cout << "| 2. On the Way          |" << endl;
                cout << "| 3. Arrived             |" << endl;
                cout << "| 4. Broken              |" << endl;
                cout << "|========================|" << endl;
                cout << "| Choice : ";
                cin >> choose;
                if(choose==1)
                {
                    package[num-1][6] = "Boarding";   
                }
                else if(choose==2)
                {
                    package[num-1][6] = "On the Way";   
                }
                else if(choose==3)
                {
                    package[num-1][6] = "Arrived";   
                }
                else if(choose==4)
                {
                    package[num-1][6] = "Broken";   
                }
                cout << "Status Successfully Updated!" << endl;
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

        void userlist()
        {
            int stop;
            bool x;
            while (x=true)
            {
                int a=0;
                cout << "\033[2J\033[1;1H";
                cout << "|========================|" << endl;
                cout << "|      List of Users     |" << endl;
                cout << "|========================|" << endl;
                cout << "|Accounts :              |" << endl;
                for(int i=0; i<data_user.size(); i++)
                {
                    if(data_user[i][2]=="false")
                    {
                        cout << a+1 << ". ";
                        for(int j=0; j<2; j++)
                        {
                            cout << "(" << data_user[i][j] << ")";
                        }
                        a+=1;
                        cout << endl;
                    }
                }

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

        void user_control()
        {
            int stop;
            bool x;
            while (x=true)
            {
                cout << "\033[2J\033[1;1H";
                cout << "|=======================|" << endl;
                cout << "|      User Control     |" << endl;
                cout << "|=======================|" << endl;
                cout << "|1. List of Us           |" << endl;
                
            }
        }
    };

    class user : public Db
    {
    public : 

        int admin()
        {
            int choose;
            bool x;
            while(x=true)
            {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "1. Dashboard Package" << endl;
                cout << "2. User Control" << endl;
                cout << "3. Exit" << endl;
                cin >> choose;
                if (choose==1)
                {
                    dashboard();
                }
                else if (choose==2)
                {
                    user_control();
                }
                else if (choose==3)
                {
                    return 0;
                }
            }
        }
        void send_package()
        {
            string a;
            string b;
            string c;
            string d;
            bool x;
            int stop;
            while(x=true)
            {
                cout << "\033[2J\033[1;1H";
                cout << "|=======================|" << endl;
                cout << "|      Send Package     |" << endl;
                cout << "|=======================|" << endl;
                cout << "| Receiver : ";
                cin >> a;
                cout << "| Address : ";
                cin >> b;
                cout << "| Object : ";
                cin >> c;
                cout << "| Weight : ";
                cin >> d;
                set2(a, b, c, d);
                insert2();
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
        int customer()
        {
            int choose;
            bool x;
            while(x=true)
            {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "1. Send Package" << endl;
                cout << "2. Status" << endl;
                cout << "3. Exit" << endl;
                cin >> choose;
                if (choose==1)
                {
                    send_package();
                }
                else if (choose==2)
                {
                    package_status();
                }
                else if (choose==3)
                {
                    return 0;
                }
            }
        }
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