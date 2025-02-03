#include <iostream>
#include <vector>
#include <set>
#include <queue>
 
using namespace std;
 
vector<int> V;
vector<vector<int>> G;
vector<int> P;
queue<int> Q;
 
 
 
 
 
 
int main(void){
    int n,m; cin >> n >> m;
    
    V.resize(n+1, 0);
    P.resize(n+1);
    G.resize(n+1);
    
    
    Q.push(1);
    P[1] = -1;
    
    
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    
    
    V[1] = 1;
    while (Q.size()) {
        int node = Q.front();
        Q.pop();
        
        
        
        
        for (int neigh: G[node]){
            if (V[neigh])
                continue;
            V[neigh] = 1;
            P[neigh] = node;
            Q.push(neigh);
        }
    }
    
    
    vector<int> path;
    
    int end = n;
    
    if (!V[end]){
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    
    while (end != -1) {
        path.push_back(end);
        end = P[end];
    }
    
    reverse(path.begin(), path.end());
    
    cout << path.size() << "\n";
    for (int node: path)
        cout << node << " ";
}
 