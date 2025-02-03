#include <cmath>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <tuple>
 
using namespace std;
#define lli long long int
int n,m;
 
vector<vector<int>> GF,GR, cond_graph;
vector<int> coins, order, comps;
vector<bool> vis;
 
vector<lli> coins_scc;
 
vector<int> node_ssc;
 
int color = 0;
lli ans = 0LL;
 
 
 
void dfs1(int u){
    vis[u] = 1;
    
    for (int v: GF[u])
        if (!vis[v])
            dfs1(v);
    
    order.push_back(u);
}
 
 
void dfs2(int u){
    vis[u] = 1;
    comps.push_back(u);
    
    for (int v: GR[u]){
        if (!vis[v])
            dfs2(v);
    }
}
 
 
 
 
lli dfs3(int u){
    vis[u] = 1;
    lli ans = coins_scc[u];
    
    for (int v: cond_graph[u]){
        if (!vis[v])
            dfs3(v);
        coins_scc[u] = max(coins_scc[u], ans + coins_scc[v]);
    }
    
    return coins_scc[u];
}
 
 
 
 
 
 
int main() {
    cin >> n >> m;
    
    GF.resize(n); GR.resize(n);
    coins.resize(n);
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }
    
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        u--;v--;
        GF[u].push_back(v);
        GR[v].push_back(u);
    }
    
    vis.resize(n, false);
    
    for (int i = 0; i < n; i++){
        if (!vis[i])
            dfs1(i);
    }
    
    
    vis.assign(n, false);
    reverse(order.begin(),order.end());
    node_ssc.resize(n);
    
    for (int u: order){
        if (!vis[u]){
            dfs2(u);
            
            lli comp_profit = 0LL;
            
            
            for (int v: comps){
                comp_profit += coins[v];
                node_ssc[v] = color;
            }
            color++;
            
            coins_scc.push_back(comp_profit);
            comps.clear();
        }
    }
    
    
    
    cond_graph.resize(color);
    
    
    vector<int> ins(color);
    for (int u = 0; u < n; u++){
        for (int v: GF[u]){
            int root_u = node_ssc[u], root_v = node_ssc[v];
            
            if (root_u != root_v){
                cond_graph[root_u].push_back(root_v);
                ins[root_v]++;
            }
        }
    }
    
    queue<pair<int,lli>> Q;
    vis.assign(color, 0);
    lli ans = 0LL;
    for (int i = 0; i < color; i++){
        if (!vis[i])
            ans = max(ans,dfs3(i));
    }
    
   
    
    cout << ans;
}