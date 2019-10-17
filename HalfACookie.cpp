/* https://open.kattis.com/problems/halfacookie */
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {
    double r, x, y, PI = 3.14159265358979323846;

    while( cin >> r >> x >> y){
        double distance;
        distance = sqrt(pow(x,2.0) + pow(y,2.0));
        if(pow(distance,2.0) < pow(r,2.0)){
            double circleArea, pieceOne, pieceTwo, height;
            circleArea = PI * pow(r,2.0);
            height = r - distance;
            pieceOne = pow(r,2.0) * acos((r - height)/r) - (r - height) * sqrt(2*r*height-pow(height,2.0));
            pieceTwo = circleArea - pieceOne;
            if(pieceOne > pieceTwo)
                cout << fixed << setprecision(6) << pieceOne << " " << pieceTwo << endl;
            else
                cout << fixed << setprecision(6) << pieceTwo << " " << pieceOne << endl;
        }
        else{
            cout << "miss" << endl;
        }
    }

    return 0;
}
