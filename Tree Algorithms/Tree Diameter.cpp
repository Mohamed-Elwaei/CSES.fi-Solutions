#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
 
using namespace std;
int n;
 
/*
 
 Use an array called depths.
 Depths[i] has the maximum length from node i to any leaf node.
 */
 
vector<vector<int>> G;
vector<int> depths;
 
 
 
 
int ans = 0;
void dfs(int u, int par){
    depths[u] = 0;
    int a = -1, b = -1;
    
    for (int v : G[u]){
        if (v == par) continue;
        
        dfs(v,u);
        depths[u] = max(depths[u], 1 + depths[v]);
        
        b = max(b, depths[v]);
        
        if (a < b)
            swap(a,b);
        
        
 
    }
    
 
    ans = max(ans, 2 + a + b);
    
}
 
 
 
 
int main() {
    cin >> n;
    G.resize(n+1);
    depths.resize(n+1);
    
    for (int i = 0; i < n - 1; i++){
        int u,v; cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    
    dfs(1,-1);
    
    cout << ans;
 
}