/* https://open.kattis.com/problems/evenup */
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int num, curr;
    deque<int> Stack;

    cin >> num;

    for (int i = 0; i < num; ++i) {
        cin >> curr;
        curr = curr % 2;
        if(Stack.empty() || (curr != Stack.front())) {
            Stack.emplace_front(curr);
        }
        else {
            Stack.erase(Stack.begin());
        }
    }

    cout << Stack.size() << endl;


    return 0;
}
