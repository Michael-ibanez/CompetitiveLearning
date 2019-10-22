/* https://open.kattis.com/problems/halloweemirrors */
#include <iostream>
#include <cmath>

using namespace std;
struct Mirror{
    int x1, x2, y1, y2;
};

struct Person{
    int x1, y1, count = 0;
};

int dotProd(int v1x, int v1y, int v2x, int v2y){
    return (v1x * v2x) + (v1y * v2y);
}

int main() {
    int mirrors, standingLocations;

    while(cin >> mirrors && mirrors != 0){
        Mirror MirrorLoc[100];
        Person PersonLoc[100];

        // Read in each location of mirrors
        for (int i = 0; i < mirrors; ++i) {
            cin >> MirrorLoc[i].x1 >> MirrorLoc[i].y1 >> MirrorLoc[i].x2 >> MirrorLoc[i].y2;
        }

        // Read in number of people
        cin >> standingLocations;

        // Read in each location of people
        for (int j = 0; j < standingLocations; ++j) {
            cin >> PersonLoc[j].x1 >> PersonLoc[j].y1;
        }

        // Find how many people can see their reflection in the mirrors by running through each mirror
        // and seeing if its point lies in the path of the mirror
        for (int k = 0; k < standingLocations; ++k) {
            for (int i = 0; i < mirrors; ++i) {
                int v1x = MirrorLoc[i].x2 - MirrorLoc[i].x1,
                    v1y = MirrorLoc[i].y2 - MirrorLoc[i].y1,
                    v2x = MirrorLoc[i].x1 - MirrorLoc[i].x2,
                    v2y = MirrorLoc[i].y1 - MirrorLoc[i].y2,
                    p1x = PersonLoc[k].x1 - MirrorLoc[i].x1,
                    p1y = PersonLoc[k].y1 - MirrorLoc[i].y1,
                    p2x = PersonLoc[k].x1 - MirrorLoc[i].x2,
                    p2y = PersonLoc[k].y1 - MirrorLoc[i].y2;

                int prod1 = dotProd(v1x, v1y, p1x, p1y),
                    prod2 = dotProd(v2x, v2y, p2x, p2y);

                if(prod1 >= 0 && prod2 >= 0 )
                    PersonLoc[k].count++;
            }
            cout << PersonLoc[k].count << endl;
        }
        cout << endl;
    }

    return 0;
}
