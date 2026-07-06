#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

static int Number_assign()
{
    char diffi;
    cout << "Choose difficulty (E[0-50],M[0-100],H[0-500]) : ";
    cin >> diffi;
    if (diffi == 'E') {
        return rand() % 50 + 1;
    } else if (diffi == 'M') {
        return rand() % 100 + 1;
    } else if (diffi == 'H') {
        return rand() % 500 + 1;
    } else {
        return Number_assign();
    }
}

static void W_L(int target, int attempts = 0)
{
    int Given_Number;
    cout << "Guess the number : ";
    cin >> Given_Number;
    attempts++;
    if (Given_Number == target) {
        cout << "Win\n";
        cout << "Attempts : " << attempts << '\n';
    }
    else {
        if (attempts >= 10) {
            cout << "Loss\n";
            cout << "Attempts : " << attempts << '\n';
        }
        if (Given_Number > target) {
            cout << "Too High...\n";
        }
        else {
            cout << "Too low...\n";
        }
        cout << "Attempts : " << attempts << '\n';
        W_L(target, attempts);
    }
}

int main()
{
    bool a;
    do {
        cout << "Shall we start the Game(Yes(1)/No(0)) : ";
        cin >> a;
        if (!a) break;
        srand(static_cast<unsigned>(time(0)));
        int target = Number_assign();
        W_L(target, 0);
    } while (true);
    return 0;
}