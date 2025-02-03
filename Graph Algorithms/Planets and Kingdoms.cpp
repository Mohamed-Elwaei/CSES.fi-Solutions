#include <cmath>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <tuple>
 
using namespace std;
#define lli long long int
int n,m;
 
 
 
vector<vector<int>> GF,GR;
vector<int> order, comp;
vector<bool> vis;
 
 
void dfs(int u){
    vis[u] = 1;
    
    for (int v: GF[u]){
        if (!vis[v])
            dfs(v);
    }
    
    order.push_back(u);
}
 
 
void dfs2(int u){
    vis[u] = 1;
    comp.push_back(u);
    
    for (int v: GR[u]){
        if (!vis[v])
            dfs2(v);
    }
}
 
 
 
int dfs3(int u, int v){
    vis[u] = 1;
    
    
    for (int next: GF[u]){
        if (!vis[next] && (next == v || dfs3(next,v)))
            return true;
    }
    
    return false;
}
 
 
 
 
 
int main() {
    cin >> n >> m;
    GF.resize(n+1); GR.resize(n+1);
    vis.resize(n+1,false);
    
    for (int i = 0 ; i < m; i++){
        int u,v; cin >> u >> v;
        
        GF[u].push_back(v);
        GR[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++){
        if (!vis[i]) dfs(i);
    }
    
    
    
    vis.assign(n+1, 0);
    int color = 0;
    
    vector<int> C(n+1,0);
    while (order.size()) {
        int u = order.back();
        order.pop_back();
        
        if (vis[u]) continue;
        
        dfs2(u);
        color++;
        
        for (int v: comp)
            C[v] = color;
        comp.clear();
    }
    
    cout << color << "\n";
    for (int i = 1; i <= n; i++)
        cout << C[i] << " ";
    return 0;
    
}
