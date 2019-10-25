#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const double PI = 3.141592653589793238463;

struct Point{
    int x1, y1;
    double angle;
};

int main() {
    int points;

    while(cin >> points && points != 0){
        vector<Point> shape;
        bool stillGood = true;
        for (int i = 0; i < points; ++i) {
            Point in{};
            cin >> in.x1 >> in.y1;
            shape.emplace_back(in);
        }

        // Calc all the shape's angles
        for (int i = 0; i < points; ++i) {
            Point one = shape[i % points],
                center = shape[(i + 1) % points],
                two = shape[(i + 2) % points];
            int v1x = one.x1 - center.x1,
                v1y = one.y1 - center.y1,
                v2x = two.x1 - center.x1,
                v2y = two.y1 - center.y1;

            shape[(i + 1) % points].angle = atan2(v2y, v2x) - atan2(v1y, v1x);

            if (shape[(i + 1) % points].angle < 0)
                shape[(i + 1) % points].angle = 2 * PI + shape[(i + 1) % points].angle;

            shape[(i + 1) % points].angle *= 180 / PI;
        }

        while(stillGood && points >= 4) {
            double smallest = 180;
            int pos = 0;
            double total = 0;

            // Find smallest angle
            for (int i = 1; i <= points; ++i) {
                if (smallest > shape[(i) % points].angle) {
                    smallest = shape[(i) % points].angle;
                    pos = (i) % points;
                }
                //cout << "Angle " << i % points << " is " << shape[i % points].angle << endl;
                total += shape[i % points].angle;
            }
            int oneN = pos - 1,
                oneP = pos + 1,
                twoN = pos - 2,
                twoP = pos + 2;

            if (pos == 0){
                oneN = points - 1;
                twoN = points - 2;
            }
            if(pos == 1){
                twoN = points - 1;
            }

            //cout << "Total is " << total << endl;
            //cout << "Smallest is at " << pos << " : " << smallest << endl;

            // Smallest is now at pos : i % points
            // Try to remove smallest angle from vector if there are 4 or more points still
            // If it creates no smaller angles then continue on and repeat
            // if angle is pos then check pos -2, pos-1, pos+1 and pos-1, pos+1, and pos+2

            int v1x = shape[oneN % points].x1 - shape[oneP % points].x1,
                v1y = shape[oneN % points].y1 - shape[oneP % points].y1,
                v2x = shape[twoP % points].x1 - shape[oneP % points].x1,
                v2y = shape[twoP % points].y1 - shape[oneP % points].y1,

                v3x = shape[twoN % points].x1 - shape[oneN % points].x1,
                v3y = shape[twoN % points].y1 - shape[oneN % points].y1,
                v4x = shape[oneP % points].x1 - shape[oneN % points].x1,
                v4y = shape[oneP % points].y1 - shape[oneN % points].y1;


            double angle2 = atan2(v2y, v2x) - atan2(v1y, v1x), angle1 = atan2(v4y, v4x) - atan2(v3y, v3x);

            if (angle1 < 0)
                angle1 = 2 * PI + angle1;

            if (angle2 < 0)
                angle2 = 2 * PI + angle2;

            angle1 *= 180 / PI;
            angle2 *= 180 / PI;

            //cout << "\tNew Angle " << oneN % points << " is : " << angle1 << endl;
            //cout << "\tNew Angle " << (pos) % points << " is : " << angle2 << endl << endl;

            if (angle1 > smallest && angle2 > smallest) {
                shape[oneN % points].angle = angle1;
                shape[oneP % points].angle = angle2;
                shape.erase(shape.begin() + pos);
                points--;
            } else {
                stillGood = false;
            }

        }

        cout << points;
        for (auto a : shape) {
            cout << " " << a.x1 << " " << a.y1;
        }
        cout << endl;
    }


    return 0;
}
