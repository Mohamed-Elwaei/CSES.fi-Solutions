#include <iostream>
#include <vector>
#include <queue>
#include <functional>
 
using namespace std;
#define lli long long int
#define INF 1e14
#define pb push_back
int n,m;
 
 
vector<vector<int>> G;
int cycle_start = -1 ,cycle_end = -1;
vector<int> P;
vector<int> C;
 
 
 
 
bool dfs(int u){
    C[u] = 1;
    
    for (int v: G[u]){
        if (C[v] == 0){
            P[v] = u;
            if (dfs(v))
                return true;
        }
        else if (C[v] == 1){
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }
    
    
    C[u] = 2;
    return false;
}
 
 
 
int main(){
    
    cin >> n >> m;
    
    G.resize(n+1); C.resize(n+1); P.resize(n+1, -1);
    
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        
        G[u].push_back(v);
    }
    
    for (int u = 1; u <= n; u++){
        if (C[u] == 0 && dfs(u))
            break;
    }
    
    if (cycle_start == -1){
        cout << "IMPOSSIBLE";
        return 0;
    }
    else{
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int u = cycle_end; u != cycle_start; u = P[u])
            cycle.push_back(u);
        
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << "\n";
        for (int v: cycle)
            cout << v << " ";
        return 0;
        
    }
}