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
    
    par.resize(n+1); size_.resize(n+1,1);
    for (int i = 1; i <= n; i++) par[i] = i;
    
    
    int components = n;
    int largest = 1;
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        u = find(u);
        v = find(v);
        
        
        if (u != v){
            components -= 1;
            U(u,v);
            largest = max({largest, size_[u], size_[v]});
        }
        printf("%d %d\n",components,largest);
        
    }
    
}