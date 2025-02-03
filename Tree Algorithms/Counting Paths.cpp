#include <iostream>
#include <vector>
 
 
using namespace std;
#define max_n 200001
#define LOG 19
 
 
int up[max_n][LOG], n, m;
vector<vector<int>> G;
vector<int> ans, depths;
 
 
 
 
void dfs(int u, int par, int depth = 0){
    
    for (int v: G[u]){
        if (v == par) continue;
        up[v][0] = u;
        depths[v] = depth + 1;
        for (int j = 1; j < LOG; j++){
            up[v][j] = up[up[v][j-1]][j-1];
        }
        dfs(v, u, depth + 1);
    }
}
 
 
 
void dfs2(int u){
    
    for (int v: G[u]){
        if (v == up[u][0]) continue;
        dfs2(v);
        ans[u] += ans[v];
    }
}
 
 
 
int LCA(int u, int v){
    if (depths[u] < depths[v])
        swap(u,v);
    
    int diff = depths[u] - depths[v];
    
    for (int j = 0; j < LOG; j++){
        if ((1 << j) & diff)
            u = up[u][j];
    }
    
    if (u == v)
        return u;
    
    for (int j = LOG - 1; j >= 0; j--){
        if (up[u][j] != up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }
    
    return up[u][0];
}
 
 
 
 
 
 
int main(){
    
    cin >> n >> m;
    G.resize(n+1);
    ans.resize(n+1);
    depths.resize(n+1);
    
    for (int i = 0; i < n - 1; i++){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    dfs(1,-1);
    
    
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        ans[u]++; ans[v]++;
        int lca = LCA(u,v);
        ans[lca]--;
        if (lca != 1)
            ans[up[lca][0]]--;
    }
    
    dfs2(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    
    return 0;
    
}