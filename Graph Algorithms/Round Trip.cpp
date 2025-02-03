#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <tuple>
 
using namespace std;
 
int n,m;
 
vector<vector<int>> G;
 
vector<bool> V;
vector<int> P;
 
int cycle_start, cycle_end;
int dfs(int u, int par){
    V[u] = 1;
    
    for (int v: G[u]){
        if (v == par)
            continue;
        else if (V[v] == 1){
            cycle_start = v;
            cycle_end = u;
            
            return true;
        }
        P[v] = u;
        if (dfs(v,u))
            return true;
    }
    return false;
    
}
 
 
int main(){
 
    cin >> n >> m;
    
    G.resize(n+1);
    V.resize(n+1,0);
    P.resize(n+1);
    
    
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    vector<int> path;
    for (int i = 1; i <= n; i++){
        if (!V[i] && dfs(i,-1)){
            path.push_back(cycle_start);
            while (cycle_end != cycle_start) {
                path.push_back(cycle_end);
                cycle_end = P[cycle_end];
                
            }
            path.push_back(cycle_end);
            
            cout << path.size() << "\n";
            for (int x: path)
                cout << x << " ";
            return 0;
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
    
}