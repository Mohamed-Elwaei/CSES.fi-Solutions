#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
 
 
using namespace std;
#define lli long long int
int n,m;
 
 
void dfs(int i, int j, vector<vector<int>>& M){
    
    if (i < 0 || i >= n || j < 0 || j >= m || !M[i][j])
        return;
    M[i][j] = 0;
    dfs(i+1,j,M); dfs(i-1,j,M); dfs(i,j+1,M); dfs(i,j-1,M);
}
 
 
int main(){
      cin >> n >> m;
    char x;
    vector<vector<int>> M(n, vector<int>(m));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> x;
            M[i][j] = (x == '.') ? 1 : 0; // Assign 1 for floor, 0 for wall
        }
    }
    
    int ans = 0;
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (M[i][j] == 0) continue;
            
            ans++;
            dfs(i,j,M);
            
        }
    }
    cout << ans;
}