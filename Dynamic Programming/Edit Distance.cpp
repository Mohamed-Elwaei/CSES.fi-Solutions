#include <vector>
#include <iostream>
#include <string>
 
using namespace std;
#define lli long long int
 
 
lli MOD = 1e9 + 7;
int main(){
    string a,b; cin >> a >> b;
    
    int n = (int) a.size(),  m = (int) b.size();
    
    
    vector<vector<int>> DP(n+1, vector<int>(m+1,-1));
    
    for (int i = 0; i <= m; i++) DP[0][i] = i;
    for (int j = 0; j <= n; j++) DP[j][0] = j;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
        {
            if (a[i-1] == b[j-1])
                DP[i][j] = DP[i-1][j-1];
            else
                DP[i][j] = 1 + min(DP[i-1][j], min(DP[i][j-1], DP[i-1][j-1]));
        }
    }
    
    cout << DP[n][m];
}