#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
 
using namespace std;
int n;
 
/*
 First root the tree.
 Use a recursive function.
 
 The recursive function will return a tuple of size 2.
 The first element is what would be the maximum size if the root was included.
 The second is what would be the maximum size if the root was not included in the matching.
 A leaf node returns 0,0.
 
 
 In the tuple:
 The first element will be 2  + sum of the first element of all return values - smallest first element of return values.
 The second element is the sum of the first element of the return values of all children.
 
 */
 
vector<vector<int>> G;
vector<pair<int,int>> C;
 
 
 
void dfs(int u, int par){
    int with = 0, without = 0;
    
    for (int v : G[u]){
        if (v == par) continue;
        dfs(v,u);
        
        without += C[v].first;
    }
    
    for (int v:  G[u]){
        if (v != par)
            with = max(with, without - C[v].first + C[v].second + 2);
    }
    C[u] = {with, without};
}
 
 
int main() {
    cin >> n;
    G.resize(n+1);
    C.resize(n+1, {0,0});
    
    for (int i = 0; i < n - 1; i++){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,-1);
    
    cout << max(C[1].first, C[1].second) / 2;
    
    
}
