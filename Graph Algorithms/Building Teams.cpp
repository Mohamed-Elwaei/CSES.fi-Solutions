#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <tuple>
 
using namespace std;
 
int n,m;
 
vector<vector<int>> G;
vector<int> C;
 
#define RED 1
#define BLUE 2
 
 
bool dfs(int u, int c){
    C[u] = c;
    
    int nextColor = BLUE;
    if (c == BLUE)
        nextColor = RED;
    for (int v: G[u]){
        if (C[v] == C[u]){
            return false;
        }
        
        if (C[v] == 0 && !dfs(v,nextColor)){
            return false;
        }
    }
    
    return true;
    
}
 
 
 
 
int main(void){
    cin >> n >> m;
    
    G.resize(n+1); C.resize(n+1, 0);
    
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    
    
    for (int i = 1; i <= n; i++){
        if (C[i] == 0 && !dfs(i,RED)){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    
    
    for (int i = 1; i <= n; i++)
        cout << C[i] << " ";
    
}
 