#include <cmath>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <tuple>
 
using namespace std;
#define lli long long int
int n,m;
 
 
vector<int> par, size_;
vector<tuple<int,int,int>> E;
 
int find(int u){
    if (u != par[u])
        return par[u] = find(par[u]);
    return u;
}
 
 
void U(int u, int v){
    u = find(u); v = find(v);
    
    if (u != v){
        if (size_[u] < size_[v])
            swap(u,v);
        
        par[v] = u;
        size_[u] += size_[v];
    }
    
}
 
int main() {
    
    cin >> n >> m;
    
    E.resize(m);
    for (int i = 0; i < m; i++){
        int u,v,w; cin >> u >> v >> w;
        E[i] = {w,u,v};
    }
    
    sort(E.begin(), E.end());
    par.resize(n+1);
    size_.resize(n+1,1);
    
    for (int i = 1; i <= n; i++) par[i] = i;
    lli cost = 0;
    
    for (auto [w,u,v]: E){
        u = find(u);
        v = find(v);
        
        if (u == v) continue;
        
        U(u,v);
        cost+=w;
    }
    
    
    set<int> comps;
    for (int i = 1; i <= n; i++){
        comps.insert(find(i));
        if (comps.size() > 1){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << cost;
}