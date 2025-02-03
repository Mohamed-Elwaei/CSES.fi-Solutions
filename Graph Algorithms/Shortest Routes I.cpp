#include <iostream>
#include <vector>
#include <queue>
#include <functional>
 
using namespace std;
#define lli long long int
#define INF 1e14
 
int n,m;
vector<vector<pair<int,int>>> G;
vector<lli> D;
vector<int> V;
 
 
int main(){
    cin >> n >> m;
    
    G.resize(n+1);
    D.resize(n+1,INF);
    V.resize(n+1, 0);
    
    
    for (int i = 0; i < m; i++){
        int u,v,w; cin >> u >> v >> w;
        
        G[u].push_back({v,w});
    }
    
    
    D[1] = 0;
    
    priority_queue<pair<lli,int>, vector<pair<lli,int>>, greater<pair<lli,int>>> Q;
    
    Q.push({0LL,1});
    
    while (!Q.empty()){
        int u = Q.top().second;
        Q.pop();
        
        if (V[u]) continue;
        V[u] = 1;
        
        for (auto edge: G[u]){
            int v = edge.first , w = edge.second;
            
            if (D[u] + w < D[v]){
                D[v] = D[u] + w;
                Q.push({D[v],v});
            }
        }
    }
    
    
    for (int i = 1; i <= n; i++)
        cout << D[i] << " ";
}