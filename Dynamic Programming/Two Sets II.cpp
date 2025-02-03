#include <vector>
#include <iostream>
#include <string>
 
using namespace std;
#define lli long long int
 
 
lli MOD = 1e9 + 7;
 
 
/*
 Input n;
 
 Sum = n * (n + 1) / 2
 
 Find how many sets sum up to  (sum / 2) and divide by two.
 
 Dimensions are n and the target.
 
 */
 
int main(){
    
    int n; cin >> n;
    lli t = n * (n + 1) / 2;
    if (t % 2){
        cout << 0;
        return 0;
    }
    t /= 2;
    vector<vector<lli>> DP(n+1,vector<lli>(t+1,0));
    for (int i = 0; i <= n; i++)
        DP[i][0] = 1;
    
    for (int r = 1; r <= n; r++){
        for (int c = 1; c <= t; c++){
            DP[r][c] = DP[r-1][c];
            
            if (c - r >= 0)
                DP[r][c] = ((DP[r][c] + DP[r-1][c - r])) % MOD;
        }
    }
    cout << DP[n-1][t] ;
    
}