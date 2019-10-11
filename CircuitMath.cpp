/* https://open.kattis.com/problems/circuitmath */
#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    int numOfLines;
    vector<int> place;
    deque<int> holder;
    char alpha = 'A', curr;

    cin >> numOfLines;

    for (int i = 0; i < numOfLines; ++i) {
        string j;
        cin >> j;
        if(j == "T")
           place.emplace_back(1);
        else
            place.emplace_back(0);
    }

    while(cin >> curr){
        if(curr == '*'){
            int one, two;
            one = holder.back();
            holder.pop_back();
            two = holder.back();
            holder.pop_back();

            if(one && two)
                holder.emplace_back(1);
            else
                holder.emplace_back(0);

        }
        else if(curr == '+'){
            int one, two;
            one = holder.back();
            holder.pop_back();
            two = holder.back();
            holder.pop_back();

            if(one || two)
                holder.emplace_back(1);
            else
                holder.emplace_back(0);

        }
        else if(curr == '-'){
            int one;
            one = holder.back();
            holder.pop_back();

            if(one)
                holder.emplace_back(0);
            else
                holder.emplace_back(1);

        }
        else{
            holder.emplace_back(place[curr - 65]);
        }
    }

    if(holder.back() == 1)
        cout << "T" << endl;
    else
        cout << "F" << endl;


    return 0;
}
