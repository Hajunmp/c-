#include <iostream>
#include <cmath>

using namespace std;

class BMI
{
    public:
        double height;
        double weight;
        int bodymass;
        int weightgoal;
        int final;
        int age;
        int speed;
        int duration;
        int MET;
        int hours;
        int burn;
        int burning;
        int work;
        int cont;
        void calc()
        {
            cout << "Body-Mass index" << endl;
            cout << "Height (m): ";
            cin >> height;
            cout << "Weight (kg): ";
            cin >> weight;
            bodymass = weight/pow(height, 2);
            cout << "Your BMI is : " << bodymass << "kg/m^2" << endl;
        }

};

class below19 : public BMI
{
    public:
        below19()
        {
            calc();
            cout << "=====================" << endl;
            cout << "RESULTS : " << endl;
            if(bodymass<=18.5)
            {
                cout << "Underweight" << endl;
            }
            else if(bodymass>18.5 && bodymass<=25)
            {
                cout << "Normal" << endl;
            }
            else if(bodymass>25 && bodymass<=30)
            {
                cout << "Overweight" << endl;
            }
            else if(bodymass>30 && bodymass<=35)
            {
                cout << "Class I Obesity" << endl;
            }
            else if(bodymass>35 && bodymass<=40)
            {
                cout << "Class II Obesity" << endl;
            }
            else if(bodymass>40)
            {
                cout << "Class III Obesity" << endl;
            }
        }
};

class below30 : public BMI
{
    public:
        below30()
        {
            calc();
            cout << "=====================" << endl;
            cout << "RESULTS : " << endl;
            if(bodymass<=18.5)
            {
                cout << "Underweight" << endl;
            }
            else if(bodymass>18.5 && bodymass<=24.5)
            {
                cout << "Normal" << endl;
            }
            else if(bodymass>24.5 && bodymass<=29)
            {
                cout << "Overweight" << endl;
            }
            else if(bodymass>29 && bodymass<=35)
            {
                cout << "Class I Obesity" << endl;
            }
            else if(bodymass>35 && bodymass<=40)
            {
                cout << "Class II Obesity" << endl;
            }
            else if(bodymass>40)
            {
                cout << "Class III Obesity" << endl;
            }
            
        }
};

class below40 : public BMI
{
    public:
        below40()
        {
            calc();
            cout << "=====================" << endl;
            cout << "RESULTS : " << endl;
            if(bodymass<=18)
            {
                cout << "Underweight" << endl;
            }
            else if(bodymass>18 && bodymass<=24)
            {
                cout << "Normal" << endl;
            }
            else if(bodymass>24 && bodymass<=29)
            {
                cout << "Overweight" << endl;
            }
            else if(bodymass>29 && bodymass<=34)
            {
                cout << "Class I Obesity" << endl;
            }
            else if(bodymass>34 && bodymass<=39)
            {
                cout << "Class II Obesity" << endl;
            }
            else if(bodymass>39)
            {
                cout << "Class III Obesity" << endl;
            }
            
        }
};

class above40 : public BMI
{
    public:
        above40()
        {
            calc();
            cout << "=====================" << endl;
            cout << "RESULTS : " << endl;
            if(bodymass<=17)
            {
                cout << "Underweight" << endl;
            }
            else if(bodymass>17 && bodymass<=24)
            {
                cout << "Normal" << endl;
            }
            else if(bodymass>24 && bodymass<=28)
            {
                cout << "Overweight" << endl;
            }
            else if(bodymass>28 && bodymass<=34)
            {
                cout << "Class I Obesity" << endl;
            }
            else if(bodymass>34 && bodymass<=39)
            {
                cout << "Class II Obesity" << endl;
            }
            else if(bodymass>39)
            {
                cout << "Class III Obesity" << endl;
            }
            
        }
};

// 1. Harus melangkah (???) step
// 2. Harus angkat beban (??) KG
// 3. etc

class goal : public BMI
{
    public:
        void count_final(double a){
            cout << "Weight Goal : ";
            cin >> weightgoal;
            if(weightgoal>a)
            {
                final = weightgoal-a;
                burning = final*7700;
                cout << "You need a total of " << burning  << " increase in calories" << endl;
            }
            else if(weightgoal<a)
            {
                final = a-weightgoal;
                burning = final*7700;
                cout << "You need a total of " << burning << " calorie deficit" << endl;
                cout << "(7700 calories per 1kg of fat)" << endl;
            }
        }
        void exercise(double a){
            cout << "====================================" << endl;
            cout << "Join Our Exercise Program?" << endl; 
            cout << "1. Join" << endl;
            cout << "2. Exit" << endl;
            cout << "Choice : ";
            cin >> work;
            if (work==1)
            {
                while(burning>0)
                {
                    cout << "\033[2J\033[1;1H";
                    cout << "EXERCISE PROGRAM" << endl;
                    cout << "========================" << endl;
                    cout << burning << " calories needed to burn" << endl;
                    cout << "Choose Your Running Speed" << endl;
                    cout << "1. 8.0 km/h" << endl;
                    cout << "2. 9.7 km/h" << endl;
                    cout << "3. 11.3 km/h" << endl;
                    cout << "4. 12.9 km/h" << endl;
                    cout << "5. 14.5 km/h" << endl;
                    cout << "choice : ";
                    cin >> speed;
                    if (speed == 1)
                    {
                        MET = 6;
                    }
                    else if(speed==2)
                    {
                        MET = 8;
                    }
                    else if(speed==3)
                    {
                        MET = 10;
                    }
                    else if(speed==4)
                    {
                        MET = 11.5;
                    }
                    else if(speed==5)
                    {
                        MET = 12.8;
                    }
                    cout << "duration(minutes) : ";
                    cin >> duration;
                    hours = duration/60;
                    burn = MET*a*duration;
                    cout << burn << " calories burnt" << endl;
                    cout << "Enter 0 to continue...";
                    cin >> cont;
                    burning -= burn;
                }
                cout << endl;
                cout << "Goal Has Been Fulfilled" << endl;
            }
            
        }
        goal()
        {
            cout << "Welcome to HealthGlow" << endl;
            cout << "=====================" << endl;
            cout << "BMI CALCULATIONS" << endl;
            cout << "Age : ";
            cin >> age;
            if(age<=19)
            {
                below19 user;
                count_final(user.weight);  
                exercise(user.weight);              
            }
            else if(age>19 && age<=30)
            {
                below30 user;
                count_final(user.weight); 
                exercise(user.weight);  
            }
            else if(age>30 && age<=40)
            {
                below40 user;
                count_final(user.weight);
                exercise(user.weight);   
            }
            else if(age>40)
            {
                above40 user;
                count_final(user.weight);
                exercise(user.weight);   
            }
        }
};

int age;

int main()
{
    goal user1;
}