/* https://open.kattis.com/problems/weakvertices */ 
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Edge {
public:
    explicit Edge(int aTo = 0) : to(aTo){}
    int to;
};

class Graph {
    public:

    explicit Graph(int numVertices);

    void addEdge(int from, int to){
        this->theList[from].push_back(Edge(to));
    }

    bool find(int source){
        bool weak = true;

        for (auto i = this->theList[source].begin(); i != this->theList[source].end(); ++i){
            for(auto j = this->theList[i->to].begin(); j != this->theList[i->to].end(); ++j){
                for(auto k = this->theList[j->to].begin(); k != this->theList[j->to].end(); ++k){
                    if(k->to == source)
                        weak = false;
                }
            }
        }
        return weak;
    }

    private:
    vector<list<Edge> > theList;
    int numVertices;
};

Graph::Graph(int numVertices) : theList(numVertices){
    this->numVertices = numVertices;
}


int main() {
    int vertices, each, ran;
    string line;

    while(cin >> vertices && vertices != -1) {
        Graph curr(vertices);
        vector<int> weakVertices;
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cin >> each;
                if(each)
                    curr.addEdge(i,j);
            }
        }

        for (int i = 0; i < vertices; ++i) {
            if(curr.find(i))
                weakVertices.push_back(i);
        }
        
        sort(weakVertices.begin(),weakVertices.end());

        for (int i = 0; i < weakVertices.size(); ++i) {
            cout << weakVertices[i] << " ";
        }

        cout << endl;

    }
    return 0;
}
/*

9
0 1 1 1 0 0 0 0 0
1 0 0 0 0 0 1 0 0
1 0 0 1 0 1 0 0 0
1 0 1 0 0 1 1 0 0
0 0 0 0 0 0 1 1 0
0 0 1 1 0 0 0 0 0
0 1 0 1 1 0 0 1 0
0 0 0 0 1 0 1 0 1
0 0 0 0 0 0 0 1 0
-1

 */
