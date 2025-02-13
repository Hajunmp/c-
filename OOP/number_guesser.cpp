// NUMBER GUESSER (Inheritance Concept)
// limit tebakan hanya 5 kali = 1000 score
// ada input untuk nama user
// highscore = siapa paling sedikit tebak paling tinggi


#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <random>
#include <string>
using namespace std;

class player
{
    public:
        string name;
        int guess;
        int guesses =  5;
        int highscore;
        int totalscore = 0;
        char playagain;
        vector<vector<int>> leaderboard; //{ranker[i],highscore}
        vector<string> ranker; //n
        int vsize = leaderboard.size();
        // void sign()
        // {
        //     cout << "What is your name? ";
        //     getline(cin, name);
        //     ranker.push_back(name);
        //     cout << ranker[0] << endl;
        // }
};

class play: public player
{
    public:
        int playing()
        {
            while (true)
            {
                cout << "What is your name? ";
                getline(cin, name);
                ranker.push_back(name);
                cout << ranker[0] << endl;
                int number = rand() % 51;
                cout << "guess a number from 0-50" << endl;
                while (guesses>0)
                {
                    cout << "Number of guesses = " << guesses << endl;
                    cout << number;
                    cout << "Your guess : ";
                    cin >> guess;
                    if (guess==number)
                    {
                        cout << "You have guessed the number!!!" << endl;
                        break;
                        
                    }
                    else if(guess>number)
                    {
                        cout << "Too High!" << endl;
                        guesses -= 1;
                    }
                    else if(guess<number)
                    {
                        cout << "Too Low!" << endl;
                        guesses -= 1;
                    }
                }
                highscore = guesses*200;
                cout << "Would you like to play again?...";
                cin >> playagain;

                
                if(playagain=='n')
                {   
                    // karna ga ada yang dipush sebelumnya
                    // for(int i=0 ;i <leaderboard.size();i++)
                    // {
                    //     leaderboard.push_back({1, 190000});
                    // }
                    leaderboard.push_back({vsize, highscore});
                    break;
                }
                else if(playagain == 'y')
                {
                    leaderboard.push_back({vsize, highscore});
                }
            }
            return totalscore;
        }

        void score()
        {
            cout << "highscore : " << totalscore << endl;
            // cout << ranker[0] << endl;
            // cout << leaderboard.size();
            // cout << leaderboard[0][1];
            for(int i=0;i<ranker.size();i++)
            {
                cout << ranker[leaderboard[i][0]] << ", " << leaderboard[i][1] << endl;
                // cout << ranker[i] << endl;

            }
            
        }
        
};

int main()
{
    srand(time(0));
    play main;
    
    main.playing();
    // cout << "Would you like to play again?...";
    //             cin >> main.playagain;

                
    //             if(main.playagain=='n')
    //             {   
    //                 // karna ga ada yang dipush sebelumnya
    //                 // for(int i=0 ;i <leaderboard.size();i++)
    //                 // {
    //                 //     leaderboard.push_back({1, 190000});
    //                 // }
    //                 main.leaderboard.push_back({main.vsize, main.highscore});
    //             }
    //             else if(main.playagain == 'y')
    //             {
    //                 main.leaderboard.push_back({main.vsize, main.highscore});
    //                 main.sign();
    //                 main.playing();
                // }
    main.score();
}