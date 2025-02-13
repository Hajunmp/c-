#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    string name;

    cout << "Personality Test" << endl << endl << "What is your name? : ";
    cin >> name;
    cout << "\033[2J\033[1;1H";

    int animal;
    cout << "Choose your animal partner :" << endl;
    cout << "1. Eagle" << endl;
    cout << "2. Dog" << endl;
    cout << "3. Horse" << endl;
    cout << "(1-3)=";
    cin >> animal;
    cout << "\033[2J\033[1;1H";

    int color;
    cout << "Choose your color : " <<endl;
    cout << "1. White" << endl;
    cout << "2. Black" << endl;
    cout << "3. Gray" << endl;
    cout << "(1-3)=";
    cin >> color;
    cout << "\033[2J\033[1;1H";

    int place;
    cout << "Where are you going for adventuring?" << endl;
    cout << "1. Desert" << endl;
    cout << "2. Tundra" << endl;
    cout << "3. Jungle" << endl;
    cout << "(1-3)=";
    cin >> place;
    cout << "\033[2J\033[1;1H";

    cout << "Hello " << name << "," << endl;

    if (animal == 1)
    {
        cout << "<eagles have been seen as a symbol of beauty, bravery, courage, honour, pride, determination, and grace>";
    }
    else if (animal == 2)
    {
        cout << "<Dogs have been labelled with their Playfulness, Chase-proneness, Curiosity/Fearlessness, Sociability and Aggressiveness>";
    }
    else
    {
        cout << "<Horses are categorized as social, aloof, challenging, and fearful>";
    }
    cout << endl;
    if (color == 1)
    {
        cout << "<White color is associated with calm and serene>";
    }
    else if (color == 2)
    {
        cout << "<Black color indicates that you are authoritative, independent, determined, strong-willed, risk-taker kind of individual>";
    }
    else
    {
        cout << "<Gray suugests you areself-sufficient, unemotional dedicated worker in your business life and a lonely indecisive person in your private life>";
    }
    cout << endl;
    if (place == 1)
    {
        cout << "<The desert represents barriers, obstacles and challenges>";
    }
    else if (place == 2)
    {
        cout << "<Tundra suggests very flashy, loving to show off and hog the spotlight>";
    }
    else
    {
        cout << "<The Jungle is characterized by being outgoing, imaginative, and creative>";
    }
}