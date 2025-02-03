#include <cmath>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <tuple>
 
using namespace std;
#define lli long long int
int n,m;
 
vector<set<int>> G;
vector<bool> vis;
 
int main() {
    cin >> n >> m;
    
    G.resize(n+1);
    vis.resize(n+1);
    
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        
        G[u].insert(v);
        G[v].insert(u);
    }
    
    for (int i = 1; i <= n; i++){
        if (G[i].size() & 1){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
 
    
    stack<int> S; S.push(1);
    vector<int> res;
    
    
    while (!S.empty()) {
        int u = S.top();
        int v;
        if (G[u].size() == 0){
            S.pop();
            res.push_back(u);
            vis[u] = 1;
        }
        
        else{
            v = *G[u].begin();
            G[u].erase(v);
            G[v].erase(u);
            S.push(v);
        }
        
    }
    
    for (int i = 1; i <= n; i++){
        if (!G[i].empty()){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    
    
    for (int u : res)
        cout << u << " ";
    
    
    
}