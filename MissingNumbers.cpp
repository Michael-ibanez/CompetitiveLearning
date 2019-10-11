/* https://open.kattis.com/problems/missingnumbers */
#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    int numOfLines, counter;
    vector<int> numsMissed;
    bool flag = true;

    cin >> numOfLines;

    for (int i = 0; i < numOfLines; ++i) {
        int num;
        cin >> num;
        numsMissed.emplace_back(num);
    }

    int front = 1;
    for (auto a: numsMissed) {
        while(front < a) {
            cout << front << endl;
            front++;
            flag = false;
        }
        front++;
    }
    if(flag)
        cout << "good job" << endl;

    return 0;
}
