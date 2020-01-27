#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Box{
public:
    double x1{}, x2{}, y1{},y2{};
    string name{};
    Box() {
    }

    bool insideBox(double xCoor, double yCoor){
        return (xCoor >= x1 && xCoor <= x2 && yCoor >= y1 && yCoor <= y2);
    }
};

int main() {
    int boxes;

    while (cin >> boxes && boxes != 0){
        int peanuts;
        Box boxHolder[boxes];
        for (int j = 0; j < boxes; ++j) {
            cin >> boxHolder[j].x1 >> boxHolder[j].y1 >> boxHolder[j].x2 >> boxHolder[j].y2 >> boxHolder[j].name;
        }

        cin >> peanuts;
        for (int i = 0; i < peanuts; ++i) {
            double x1, y1;
            bool flag = false;
            string currName, found;
            cin >> x1 >> y1 >> currName;

            for (int j = 0; j < boxes && !flag; ++j) {
                flag = boxHolder[j].insideBox(x1, y1);
                if(flag)
                    found = boxHolder[j].name;
            }

            if(flag)
                if(currName == found)
                    cout << currName << " correct" << endl;
                else
                    cout << currName << " " << found << endl;
            else
                cout << currName << " floor" << endl;
        }
        cout << endl;

    }
    return 0;
}
