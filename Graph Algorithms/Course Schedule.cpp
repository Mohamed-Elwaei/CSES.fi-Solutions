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
 
 
vector<vector<int>> G;
vector<int> ins;
set<int> vis;
 
 
 
 
int main(){
    cin >> n >> m;
    
    queue<int> Q;
    G.resize(n+1);
    ins.resize(n+1,0);
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        
        G[u].push_back(v);
        ins[v]++;
    }
    
    for (int i = 1; i <= n; i++)
        if (ins[i] == 0) Q.push(i);
    
    vector<int> order;
    
    while (Q.size()){
        int u = Q.front(); Q.pop();
        vis.insert(u);
        order.push_back(u);
        
        for (int v: G[u]){
            ins[v]--;
            if (ins[v] == 0)
                Q.push(v);
        }
        
    }
    
    if (vis.size() != n){
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    for (int u: order)
        cout << u << " ";
    return 0;
    
    
}