#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int lines;

    while (cin >> lines && lines != 0){
        vector<int> numDiv;
        vector<int> numArr;
        int bottomBound = 0, upperBound = 50001, maxDiv = -1;

        for (int i = 0; i < lines; ++i) {
            string sign, non;
            int num;
            cin >> sign >> non >> num;

            if(sign == "less"){
                if(upperBound > num)
                    upperBound = num;
            }
            else if(sign == "greater"){
                if(bottomBound < num)
                    bottomBound = num;
            }
            else{
                if(maxDiv < num)
                    maxDiv = num;
                numDiv.emplace_back(num);
            }
        }

        if(upperBound == 50001) {
            cout << "infinite" << endl;
        }
        else {
            for(int i = bottomBound + 1; i < upperBound; i++){
                bool flag = true;
                for(auto j = 0; j < numDiv.size() && flag; j++){
                    if(i % numDiv[j] != 0 )
                        flag = false;
                }
                if(flag)
                    numArr.emplace_back(i);
            }

            if ((upperBound <= bottomBound + 1) || numArr.empty()) {
                cout << "none" << endl;
            }
            else{
                sort(numArr.begin(), numArr.end());
                for( int a : numArr)
                    cout << a << " ";
                cout << endl;
            }
        }
    }

    return 0;
}
