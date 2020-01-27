/* https://open.kattis.com/problems/lumbercraft */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <map>
#include <list>

using namespace std;

class LumberFarm{
public:
    int x1{}, y1{};
    char letter = ' ';
    LumberFarm(int x1, int y1, char letter) {
        this->x1 = x1;
        this->y1 = y1;
        this->letter = letter;
    }

    // Start from bottom right: bottom to top and right tot left
    pair<int, int> findTree(char map[50][50], int height, int width){
        pair<int, int> ret;
        int smallest = 1000000000;
        for (int j = width-1; j >= 0; j--) {
            for (int i = height-1; i >= 0 ; i--) {
                if (map[i][j] == '!') {
                    int distance = dist(this->x1, this->y1, j, i);
                    if (distance < smallest) {
                        ret.first = i;
                        ret.second = j;
                        smallest = distance;

                    }
                }
            }
        }
        return ret;
    }

    int dist(int x11, int y11, int x2, int y2){
        return pow(x2-x11, 2) + pow(y2-y11, 2);
    }

    bool operator< (const LumberFarm &other) const {
        return letter < other.letter;
    }
};

int main() {
    int moves, height, width;
    map<pair<int, int>, list<char> > removeLumber;
    map<char, double> scoreSheet;
    vector<LumberFarm> Players;
    char map[50][50];

    while (cin >> moves >> height >> width && moves != 0 && height != 0 && width != 0){
        string let;
        int lumberLeft = 0;
        getline(cin, let);
        // Create the maze
        for (int i = 0; i < height; ++i) {
            getline(cin, let);
            for (int j = 0; j < width; ++j) {
                map[i][j] = let[j];
                if(let[j] == '!') {
                    lumberLeft++;
                }
                else if(let[j] >= 'A' && let[j] <= 'Z'){
                    LumberFarm lf(j,i,let[j]);
                    Players.emplace_back(lf);
                    scoreSheet[let[j]] = 0;
                }
            }
        }

        // Play the game
        while(moves > 0 && lumberLeft > 0){
            for( auto mill : Players){
                removeLumber[mill.findTree(map, height, width)].emplace_back(mill.letter);
            }

            // Remove lumber and assign points
            for (const auto& treeSpot : removeLumber) {
                for ( auto mill : treeSpot.second) {
                    scoreSheet[mill] += 1.0/treeSpot.second.size();
                }
                map[treeSpot.first.first][treeSpot.first.second] = '.';
                lumberLeft--;
            }
            removeLumber.clear();
            moves--;
        }


        // Display results
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cout << map[i][j];
            }
            cout << endl;
        }
        for(auto P : scoreSheet){
            cout << P.first << " " << P.second << endl;
        }

        removeLumber.clear();
        scoreSheet.clear();
        Players.clear();
    }
    return 0;
}

