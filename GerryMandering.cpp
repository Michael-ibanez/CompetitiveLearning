/ * https://open.kattis.com/problems/gerrymandering */ 
#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <array>
#include <cmath>

using namespace std;

struct Vote{
    int totalA = 0;
    int totalB = 0;
};

int main() {
    int precints, districts, totalVotes = 0;
    Vote theVotes[1001];
    double effiGap = 0,wastedA = 0, wastedB = 0;
    cin >> precints >> districts;

    for (int i = 0; i < precints; ++i) {
        int district, A, B;
        cin >> district >> A >> B;
        theVotes[district].totalA += A;
        theVotes[district].totalB += B;
        totalVotes += A;
        totalVotes += B;
    }

    // Do work for each district
    for (int j = 0; j < districts; ++j) {
        Vote curr = theVotes[j+1];
        int wastedCurrA = 0, wastedCurrB = 0;
        int neededToWin = ((curr.totalA + curr.totalB) / 2) + 1;
        if( curr.totalA > curr.totalB){
            cout << "A ";
            wastedCurrA = curr.totalA - neededToWin;
            wastedCurrB = curr.totalB;
            wastedA += wastedCurrA;
            wastedB += wastedCurrB;
            cout << wastedCurrA << " " << wastedCurrB << endl;
        }
        else {
            cout << "B ";
            wastedCurrA = curr.totalA;
            wastedCurrB = curr.totalB - neededToWin;
            wastedA += wastedCurrA;
            wastedB += wastedCurrB;
            cout << wastedCurrA << " " << wastedCurrB << endl;
        }
    }

    effiGap = abs(wastedA - wastedB) / totalVotes;

    cout << effiGap << endl;


    return 0;
}
