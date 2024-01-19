#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph {

    public:
    vector<T> adj[6];

    void createEdges(int u,int v,int direction) {
        adj[u].push_back(v);

        if(!direction) {
            adj[v].push_back(u);
        }

    }

    
        void AdjListDisplay() {
        for (int i = 0; i < 6; ++i) { // Adjust the loop limit based on your needs
            if (!adj[i].empty()) {
                cout << i << "-" << " ";
                for (auto j : adj[i]) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }
    }
    

};

int main() {
    int m,n;
    cout << "Enter m and n" << endl;
    cin >> m >> n;

    graph<int> g;

    cout << "Enter the data of edges " << endl;

    for(int i = 1; i < m; i++) {
        int u,v;
        cin >> u >> v;
        
        g.createEdges(u,v,0);
    }

    cout << "Your graph implemented by AdjacencyList is" << endl;
    g.AdjListDisplay();
}