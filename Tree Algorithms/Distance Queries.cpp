#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
 
#define lli long long int
#define max_n 200009
#define LOG 20
 
int n,q, root = 1;
vector<int> depths;
vector<vector<int>> G;
 
int up[max_n][LOG];
 
 
 
/*
 For each query: find the distance between nodes a and b.
 
 dist(a,b) = depth[a] - LCA(a,b) + depth[b] - LCA(a,b).
 
 Root does not matter.
 */
 
 
 
int LCA(int a, int b){
    if (depths[a] < depths[b])
        swap(a,b);
    
    
    int lvlDiff = depths[a] - depths[b];
    
    
    for (int j = 0; j < LOG; j++){
        if ((1 << j) & lvlDiff){
            a = up[a][j];
        }
    }
    
    //Now a is at the same depth as b.
    
    if (a == b)
        return a;
    
    
    
    /*
     Now that a and b are at the same depth. If the kth ancestor is the same for both then, we know that any ancestor higher than the kth ancestor is the same.
     We then shrink our interval. This is very similar to a binary search.
     */
    for (int j = LOG - 1; j >= 0; j--){
        if (up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    
    
    
    
    return up[a][0];
}
int dist(int a,int b){
    return depths[a]  + depths[b] - (2*depths[LCA(a,b)]);
}
void dfs(int u, int par, int depth = 0){
    depths[u] = depth;
    
    for (int v: G[u]){
        if (v == par){
            continue;
        }
        
        
        up[v][0] = u;
        
        for (int j = 1; j < LOG; j++){
            up[v][j] = up[up[v][j-1]][j-1];
        }
        
 
        dfs(v,u,depth + 1);
    }
    
}
 
 
 
 
 
 
 
 
 
int main(){
    cin >> n >> q;
    depths.resize(n+1);
    G.resize(n+1);
    
    depths[root] = 0;
    
    for (int i = 0; i < n - 1; i++){
        int u,v; cin >> u >> v;
        
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    
    dfs(root, -1);
    
    
    
    
    for (int i = 0; i < q; i++){
        int u,v; cin >> u >> v;
        
        
        cout << dist(u,v) << "\n";
    }
    
}