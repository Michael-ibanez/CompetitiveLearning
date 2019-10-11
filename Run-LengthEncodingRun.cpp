/* https://open.kattis.com/problems/runlengthencodingrun */
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int count = 0;
    char letterCurr, letterPrev, DE, num;

    cin >> DE;
    if(DE == 'E'){
        cin.get();
        while(cin.get(letterCurr)){
            if(count == 0)
                letterPrev = letterCurr;
            if(letterPrev == letterCurr)
                count++;
            else {
                cout << letterPrev << count;
                count = 1;
                letterPrev = letterCurr;
            }
        }
        cout << endl;

    }
    else if(DE == 'D'){
        cin.get();
        while(cin.get(letterCurr) && cin >> count) {
            while(count != 0){
                cout << letterCurr;
                count--;
            }
        }
        cout << endl;
    }

    return 0;
}
