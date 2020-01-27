/* https://open.kattis.com/problems/flexible */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int M, P;
    vector<int> L, R;

    cin >> M >> P;

    L.push_back(0);
    L.push_back(M);
    for (int i = 0; i < P; ++i) {
        int j;
        cin >> j;
        L.push_back(j);
    }

    sort(L.begin(),L.end());

    for (int k = 0; k < L.size(); ++k) {
        for (int i = k+1; i < L.size(); ++i) {
            R.push_back(abs(L[k] - L[i]));
        }
    }

    sort(R.begin(),R.end());
    R.erase( unique( R.begin(), R.end() ), R.end() );

    for (int l = 0; l < R.size(); ++l) {
        cout << R.at(l) << " ";
    }
    cout << endl;

    return 0;
}
