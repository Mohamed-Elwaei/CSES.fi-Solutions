#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <functional>
 
using namespace std;
#define lli long long int
#define INF 1e14
#define pb push_back
int n,m;
 
 
/*
 A node v has ways : a1 + a2 ... + ak
 where ai is the ith node that points to v
 
 */
 
vector<vector<int>> G;
vector<int> ins;
vector<lli> ways;
vector<bool> vis;
 
lli M = 1e9 + 7;
 
 
void dfs(int u, vector<vector<int>>& G2){
    vis[u] = 1;
    for (int v: G[u]){
        if (vis[v]) continue;
        G2[u].push_back(v);
        ins[v]++;
        dfs(v,G2);
    }
}
 
 
 
 
int main(){
    int n,m;
    
    cin >> n >> m;
    G.resize(n+1);
    ins.resize(n+1);
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
    }
    ways.resize(n+1,0);
    ways[1] = 1;
    
    queue<int> Q;
    Q.push(1);
    vis.resize(n+1);
    while (Q.size()) {
        int u = Q.front(); Q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        
        for (int v: G[u]){
            ins[v]++;
            Q.push(v);
        }
    }
    
    Q.push(1);
    
    while (Q.size()) {
        int u = Q.front(); Q.pop();
        
        for (int v : G[u]){
            ins[v]--;
            ways[v] = (ways[v] + ways[u]) % M;
            if (ins[v] == 0){
                Q.push(v);
            }
        }
    }
    
    cout << ways[n];
    
 
}