#include <vector>
#include <set>
#include <iostream>
 
 
using namespace std;
#define lli long long int
 
 
 
lli INF = 1e13;
lli MOD = 1e9 + 7;
int main(){
    
    int n; cin >> n;
    
    
    vector<vector<lli>> M(n, vector<lli>(n,0));
    
    for (int i = 0; i < n; i++){
        for (int c = 0; c < n; c++){
            char x;
            cin >> x;
            M[i][c] = (x == '.');
        }
    }
    
    for (int c = n - 2; c >= 0; c--)
        M[n-1][c] = min(M[n-1][c+1], M[n-1][c]);
    
    for (int r = n - 2; r >= 0; r--)
        M[r][n-1] = min(M[r+1][n-1], M[r][n-1]);
    
    for (int r = n - 2; r >= 0; r--){
        for (int c = n - 2; c >= 0; c--){
            if (M[r][c])
                M[r][c] = (M[r][c+1] + M[r+1][c]) % MOD;
        }
    }
    
    cout << M[0][0];
}