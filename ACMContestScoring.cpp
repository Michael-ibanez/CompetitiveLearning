/* https://open.kattis.com/problems/acm */
#include <iostream>
#include <vector>

using namespace std;

struct Question{
    bool isCorrect = false;
    int penalty = 0,
        time = 0;
    string problem;
};

int main() {
    Question question[1000];
    int time, totalTime = 0, size = 0, totalCorrect = 0;

    while(cin >> time && time != -1){
        bool alreadyFound = false;
        string rightOrWrong,
                problem;
        Question curr;
        int pos;

        cin >> problem >> rightOrWrong;

        for (int i = 0; i < size; ++i) {
            if(question[i].problem == problem) {
                alreadyFound = true;
                curr = question[i];
                pos = i;
            }
        }

        if(rightOrWrong == "right") {
            int j = 20;
            curr.isCorrect = true;
            curr.problem = problem;
            j *= curr.penalty;
            curr.time = time + j;
            question[size] = curr;
            if(alreadyFound){
                question[pos] = curr;
            }
            else {
                size++;
            }
        }
        else if(rightOrWrong == "wrong"){
            curr.isCorrect = false;
            curr.problem = problem;
            curr.penalty++;
            question[size] = curr;
            if(alreadyFound){
                question[pos] = curr;
            }
            else {
                size++;
            }
        }
    }

    for (int k = 0; k < size; ++k) {
        if(question[k].isCorrect) {
            totalTime += question[k].time;
            totalCorrect++;
        }
    }

    cout << totalCorrect << " " << totalTime << endl;

    return 0;
}
