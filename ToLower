/* https://open.kattis.com/problems/tolower */

#include<iostream>
#include<fstream>
#include <vector>

using namespace std;

int main() {
    int A, B, numRight = 0, charRight = 0;
    bool flag;
    string holder;

    cin >> A >> B;

    for (int k = 0; k < A; ++k) {
        flag = true;

        for (int i = 0; i < B; ++i) {
            cin >> holder;
            charRight = 0;
            if (holder.length() >= 2) {
                for (int j = 1; j < holder.length(); ++j) {
                    if (holder[j] > 96 && holder[j] < 123)
                        charRight++;
                }

                if (holder.length() != (charRight + 1)) {
                    flag = false;
                }

                if (!flag) {
                    i++;
                    while (i < B) {
                        cin >> holder;
                        i++;
                    }
                }
            }

        }

        if (flag)
            numRight++;
    }
    cout << numRight << endl;
    return 0;
}
