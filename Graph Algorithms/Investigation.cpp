#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <functional>
 
using namespace std;
#define lli long long int
#define INF 1e14
#define pb push_back
int n,m, M = 1e9 + 7;
#
 
 
/*
 A node v has ways : a1 + a2 ... + ak
 where ai is the ith node that points to v
 
 */
 
vector<vector<pair<int,lli>>> G;
 
 
 
int main(){
    cin >> n >> m;
    G.resize(n+1);
    vector<lli> dist(n+1, INF);
    
    for (int i = 0; i < m; i++){
        int u,v,w; cin >> u >> v >> w;
        G[u].push_back({v,w});
    }
    
    vector<int> min_flights(n+1,1e9);
    vector<int> max_flights(n+1,0);
    vector<int> ways(n+1,0);
    ways[1] = min_flights[1] = max_flights[1] = 0;
    
    //Tuple contains distance, vertex
 
    priority_queue<pair<lli,int>, vector<pair<lli,int>>, greater<pair<lli,int>>> Q;
    Q.push({0,1});
    min_flights[1] = max_flights[1] = dist[1] = 0;
    ways[1] = 1;
    
    vector<bool> processed(n+1,0);
     
    while (Q.size()){
        int u = Q.top().second;
        Q.pop();
        if (processed[u]) continue;
        processed[u] = 1;
        
        
        for (auto [v,w]: G[u]){
            
            if (dist[u] + w < dist[v]){
                ways[v] = ways[u];
                min_flights[v] = min_flights[u] + 1;
                max_flights[v] = max_flights[u] + 1;
                dist[v] = dist[u] + w;
                Q.push({dist[v],v});
            }
            else if (dist[u] + w == dist[v]){
                ways[v] = (ways[u] + ways[v]) % M;
                min_flights[v] = min(min_flights[v], min_flights[u] + 1);
                max_flights[v] = max(max_flights[v], max_flights[u] + 1);
                
            }
        }
    }
        
    printf("%lld %d %d %d", dist[n],ways[n], min_flights[n], max_flights[n]);
        
    
    
    
}