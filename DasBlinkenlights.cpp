/* https://open.kattis.com/problems/dasblinkenlights */
#include <iostream>

using namespace std;

int main() {

    int a, b, time, addA, addB;
    bool flag = false;

    cin >> a >> b >> time;

    addA = a;
    addB = b;

    while(a <= time && b <= time){
        if(a == b) {
            flag = true;
            break;
        }
        while(a < b) {
            a += addA;
        }
        while(b < a) {
            b += addB;
        }
    }

    if(flag)
        cout << "yes" << endl;
    else
        cout << "no" << endl;





    return 0;
}
