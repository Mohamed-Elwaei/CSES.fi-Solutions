#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
 
using namespace std;
#define lli long long int
 
int n, m;
vector<vector<lli>> G;
vector<vector<lli>> C;
vector<int> P;
int INF = 2e9;
 
 
int s, t;
vector<bool> vis;
 
void dfs(int u){
    vis[u] = 1;
    
    for (int v: G[u])
        if (!vis[v] && C[u][v])
            dfs(v);
    
}
 
 
lli bfs() {
    fill(P.begin(), P.end(), -1);
    P[s] = -2;
    queue<pair<int, lli>> Q;
    Q.push({s, INF});
 
    while (!Q.empty()) {
        int from = Q.front().first;
        lli flow = Q.front().second;
        Q.pop();
 
        for (lli to : G[from]) {
            if (P[to] == -1 && C[from][to]) {
                lli new_flow = min(flow, C[from][to]);
                P[to] = from;
                if (to == t) return new_flow;
                Q.push({to, new_flow});
            }
        }
    }
    return 0;
}
 
int main() {
    cin >> n >> m;
    s = 0; t = n - 1;
    C.resize(n, vector<lli>(n, 0));
    G.resize(n);
    P.resize(n, -1);
 
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v; w = 1;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u); // Adding reverse edges to the graph
        C[u][v] += w; C[v][u] += w;
    }
 
    lli flow = 0;
    lli new_flow;
    while ((new_flow = bfs())) {
        flow += new_flow;
        int cur = t;
 
        while (cur != s) {
            int prev = P[cur];
            C[prev][cur] -= new_flow;
            C[cur][prev] += new_flow;
            cur = prev;
        }
    }
 
    vis.resize(n,false);
    dfs(s);
    
    
    vector<pair<int,int>> edges;
    for (lli u = 0; u < n; u++){
        if (!vis[u]) continue;
        for (lli v: G[u]){
            if (!vis[v]){
                edges.push_back({u+1,v+1});
            }
        }
    }
    
    cout << flow << "\n";
    for (auto [u,v] : edges)
        cout << u << " " << v << "\n";
    
    
    return 0;
}
 