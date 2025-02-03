#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
 
using namespace std;
int n;
 
vector<vector<int>> G;
 
vector<int> C;
 
 
void dfs(int u){
    C[u] = 1;
    
    for (int v: G[u]){
        dfs(v);
        C[u] += C[v];
    }
    
}
 
int main() {
    cin >> n;
    
    G.resize(n+1);
    C.resize(n+1);
    
    for (int v = 2; v <= n; v++){
        int u; cin >> u;
        G[u].push_back(v);
        
    }
    dfs(1);
    
    for (int i = 1; i <= n; i++)
        cout << C[i] - 1 << " ";
    
    
}