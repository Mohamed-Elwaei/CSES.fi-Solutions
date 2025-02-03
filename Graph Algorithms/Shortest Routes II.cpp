#include <iostream>
#include <vector>
#include <queue>
#include <functional>
 
using namespace std;
#define lli long long int
#define INF 1e14
 
int n,m,q;
vector<vector<lli>> M;
 
 
 
int main(){
    cin >> n >> m >> q;
    
    M.resize(n+1, vector<lli>(n+1,INF));
 
    for (int i = 1; i <= n; i++)
        M[i][i] = 0;
    
    
    for (int i = 0 ; i < m; i++){
        int u,v,w; cin >> u >> v >> w;
        M[u][v] = M[v][u] = min(M[u][v], (lli) w);
    }
    
    
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
            }
        }
    }
    
    for (int i = 0; i < q; i++){
        int u,v; cin >> u >> v;
        if (M[u][v] != INF)
            cout << M[u][v] << "\n";
        else
            cout << -1 << "\n";
    }
    
}
 