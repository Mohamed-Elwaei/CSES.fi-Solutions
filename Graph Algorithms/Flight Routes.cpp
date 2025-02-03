#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <set>
 
 
 
using namespace std;
#define lli long long int
#define INF 1e14
 
/*
 
 We are interested in the k cheapest routes.
 
 So if there was a way to visit a certain node more than k times. We only care about the first k times.
 Use Djikstra, set a counter for each node. When a node is visited decrement the counter. If the counter is 0. Ignore the node.
 */
 
int n,m,k;
 
vector<vector<pair<int,int>>> G;
 
int main(){
    cin >> n >> m >> k;
    G.resize(n+1);
    for (int i = 0; i < m; i++){
        int u,v,w; cin >> u >> v >> w;
        G[u].push_back({v,w});
    }
    
    priority_queue<tuple<lli,int>, vector<tuple<lli,int>>, greater<tuple<lli,int>>> Q;
    vector<int> vis(n+1,0);
    Q.push({0,1});
    vector<lli> res;
    
    
    while (!Q.empty()){
        lli dist; int u;
        tie(dist,u) = Q.top(); Q.pop();
        
        if (vis[u] >= k) continue;
        vis[u]++;
        if (u == n) res.push_back(dist);
        
        for (auto e: G[u]){
            int v,w; tie(v,w) = e;
            Q.push({w + dist, v});
        }
    }
    
    
    for (lli x: res) cout << x << " ";
    return 0;
    
}