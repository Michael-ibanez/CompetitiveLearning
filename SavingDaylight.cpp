/* https://open.kattis.com/problems/savingdaylight */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string mon, day, year;
    char col;
    int h1, m1, h2, m2;

    while (cin >> mon >> day >> year >> h1 >> col >> m1 >> h2 >> col >> m2){
        // Find min total of each of them
        int secMin2 = (60 * h2) + m2, secMin1 = (60 * h1) + m1;
        int diff = secMin2 - secMin1;
        int hours = diff / 60, mins = diff % 60;
        cout << mon << " " << day << " " << year << " " << hours << " hours " << mins << " minutes" << endl;
    }
    return 0;
}
