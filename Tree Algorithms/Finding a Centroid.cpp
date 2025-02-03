#include <iostream>
#include <vector>
using namespace std;
#define lli long long int
 
int n;
vector<int> S;
vector<vector<int>> G;
 
 
 
 
void dfs_sz(int u, int par){
    S[u] = 1;
    
    for (int v: G[u]){
        if (v == par) continue;
        
        dfs_sz(v, u);
        S[u] += S[v];
    }
}
 
 
int centroid = -1;
 
void find_centroid(int u, int par){
    int max_sz = n - S[u];
    
    for (int v: G[u]){
        if (v == par) continue;
        
        find_centroid(v, u);
        max_sz = max(max_sz, S[v]);
    }
    
    if (max_sz <= n / 2)
        centroid = u;
}
 
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    G.resize(n+1); S.resize(n+1);
    
    for (int i = 0; i < n - 1; i++){
        int u,v; cin >> u >> v;
        
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    
    dfs_sz(1,-1);
    find_centroid(1,-1);
    
    cout << centroid;
    
}
