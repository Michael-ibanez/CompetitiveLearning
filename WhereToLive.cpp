/* https://open.kattis.com/problems/wheretolive */
#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int cities;

    while(cin >> cities && cities != 0){
        double sumA = 0, sumB = 0;
        for (int i = 0; i < cities; ++i) {
            int x, y;
            cin >> x >> y;
            sumA += x;
            sumB += y;
        }

        sumA /= cities;
        sumB /= cities;

        cout << round(sumA-0.000000000001) << " " << round(sumB-0.000000000001) << endl;
    }

    return 0;
}
