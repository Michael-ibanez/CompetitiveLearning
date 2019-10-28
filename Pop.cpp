/* https://open.kattis.com/problems/pop */
/* Math https://www.youtube.com/watch?v=QWIZXRjMspI */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793238463;

class Balloon{
public:
    Balloon() {
        this->popped = false;
    }

    double r{}, x{}, y{}, s{};
    bool popped;
};

struct Shot{
    double px{}, py{}, pz{}, vy{}, vx{}, vz{};
};

// Calculates dot product
double dotProd(double ax, double ay, double az, double bx, double by, double bz){
    return ((ax * bx) + (ay * by) + (az * bz));
}

// Calculates magnitude of a vector
double mag(double ax, double ay, double az){
    return sqrt(pow(ax, 2) + pow(ay, 2) + pow(az, 2));
}

// Calculates angle
double angle(double ax, double ay, double az, double bx, double by, double bz){
    return acos(dotProd(ax,ay,az,bx,by,bz)/mag(bx,by,bz)/mag(ax,ay,az));
}

int main() {
    int numBallons;
    int numShots;

    while(cin >> numBallons && numBallons != 0){
        Balloon balloons[50];
        Shot shots[10];
        for (int i = 0; i < numBallons; ++i) {
            cin >> balloons[i].r >> balloons[i].s >> balloons[i].x >> balloons[i].y;
            balloons[i].s += balloons[i].r;
        }
        // Read in each shot
        cin >> numShots;
        for (int i = 0; i < numShots; ++i) {
            int shot = 0;
            cin >> shots[i].px >> shots[i].py >> shots[i].pz
                >> shots[i].vx >> shots[i].vy >> shots[i].vz;

            // Determine if the shot goes through each balloon not already popped
            for (int j = 0; j < numBallons; ++j) {
                if(!balloons[j].popped){
                    // Calc balloon's vector and the angle of the shot
                    double balloonX = balloons[j].x - shots[i].px,
                           balloonY = balloons[j].y - shots[i].py,
                           balloonZ = balloons[j].s - shots[i].pz,
                           angleCurr = angle(balloonX, balloonY, balloonZ, shots[i].vx, shots[i].vy, shots[i].vz);

                    //cout << "\tAngle " << j << " : " << angleCurr*180/PI << endl;
                    // Make sure the angle is in bounds meaning it is range of shot (< 90)
                    if (angleCurr < PI/2 ) {
                        // Dot prod of balloon and shot over inner product of shot is our shot multiplier
                        double mult = dotProd(balloonX, balloonY, balloonZ, shots[i].vx, shots[i].vy, shots[i].vz)
                                      / dotProd(shots[i].vx, shots[i].vy, shots[i].vz, shots[i].vx, shots[i].vy,
                                          shots[i].vz);
                        // Calc wether the bullet passes through the circle created by the balloon
                        double x = balloonX - (mult * shots[i].vx),
                            y = balloonY - (mult * shots[i].vy),
                            z = balloonZ - (mult * shots[i].vz),
                            r = balloons[j].r,
                            popped = abs(dotProd(x, y, z, x, y, z));
                        //cout << "\t\t" << x << " " << y << " " << z << " : " << r << endl;
                        // If popped is within the equation of x^2 + y^2 + z^2 = r^2
                        if (popped <= pow(r, 2)) {
                            shot++;
                            balloons[j].popped = true;
                        }
                    }
                }
            }
            cout << shot << endl;
        }
    }
    return 0;
}
