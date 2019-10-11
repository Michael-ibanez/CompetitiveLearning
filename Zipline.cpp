/* https://open.kattis.com/problems/zipline */
#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <array>
#include <cmath>
#include <iomanip>

using namespace std;


int main() {
    int zipLineConfigs;
    cin >> zipLineConfigs;

    for (int i = 0; i < zipLineConfigs; ++i) {
        double width, pole1, pole2, rider;
        double minDist = 0, maxDist = 0, eff1, eff2;
        cin >> width >> pole1 >> pole2 >> rider;
        minDist = sqrt(pow(width,2) + pow(abs(pole1-pole2), 2));
        eff1 = (pole1-rider)/(pole2-rider+pole1-rider);
        eff2 = (pole2-rider)/(pole1-rider+pole2-rider);
        maxDist = sqrt( pow(pole1-rider,2) + pow(width*eff1,2)) + sqrt(pow(pole2-rider,2)+ pow(width*eff2,2));
        if(rider == pole1 || rider == pole2)
            cout << fixed << setprecision(8) << minDist << " " << minDist << endl;
        else
            cout << fixed << setprecision(8) << minDist << " " << maxDist << endl;
    }

    return 0;
}
