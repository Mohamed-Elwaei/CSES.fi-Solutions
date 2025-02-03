#include <vector>
#include <iostream>
 
 
using namespace std;
#define lli long long int
 
 
lli MOD = 1e9 + 7;
int main(){
    int n,m; cin >> n >> m;
    vector<int> V(n);
    for (int i = 0; i < n; i++) cin >> V[i];
    
    vector<vector<lli>> DP(n, vector<lli>(m+1,0));
    
    if (V[0])
        DP[0][V[0]] = 1;
    else
        for (int i = 1; i <= m; i++) DP[0][i] = 1;
    
    for (int i = 1; i < n; i++)
        if (V[i])
            for (int j = max(1, V[i] - 1); j <= min(m, V[i] + 1); j++)
                DP[i][V[i]] = (DP[i][V[i]] + DP[i-1][j]) % MOD;
        
        else
            for (int j = 1; j <= m; j++)
                for (int k = max(1, j - 1); k <= min(m, j + 1); k++)
                    DP[i][j] = (DP[i][j] + DP[i-1][k]) % MOD;
        
    lli ans = 0;
    for (auto &v: DP.back())
        ans = (ans + v) % MOD;
    cout << ans;
}