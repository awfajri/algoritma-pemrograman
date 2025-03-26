#include <iostream>
using namespace std;

int main()
{
    string NIM;
    string Name;
    float taskscore;
    float midtestscore;
    float finaltestscore;

    cout << "NIM kamu berapa: ";
    cin >> NIM;
    cout << "nama kamu? ";
    cin >> Name;
    cout << "Taskscore kamu berapa?";
    cin >> taskscore;
    cout << "mid test score kamu berapa?";
    cin >> midtestscore;
    cout << "final test score kamu berapa?";
    cin >> finaltestscore;

    float finalscore = (taskscore * 20 / 100) + (midtestscore * 30 / 100) + (finaltestscore * 50 / 100);
    cout << "\nNih " << Name << ". Jadi, Final score kamu " << finalscore;
    return 0;
}