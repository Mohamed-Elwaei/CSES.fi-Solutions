#include <vector>
#include <iostream>
#include <string>
 
using namespace std;
#define lli long long int
 
 
lli MOD = 1e9 + 7;
 
/*
 2D DP problem.
 Dimensions are a, and b; F(a,b)
 
 Base Case happens if one of these sides is one;
 
 F(a,1) = a - 1
 F(1,b) = b - 1
 
 We get a mirror, at halfway. We can cut vertically, or horizontally.
 */
 
int INF = 1e9;
 
int main(){
    int a,b; cin >> a >> b;
    if (a > b) swap(a,b);
    
    
    //a is the rows, b is the columns
    vector<vector<int>> DP(a+1,vector<int>(b+1,INF));
    
    for (int i = 1; i <= a; i++)
        DP[i][1] = i - 1;
    for (int j = 1; j<= b; j++)
        DP[1][j] = j - 1;
    for (int i = 1; i <= min(a,b); i++)
        DP[i][i] = 0;
    
    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= b; j++){
            if (DP[i][j] != INF) continue;
            
            for (int k = 1; k < i; k++) //Cutting Horizontally
                DP[i][j] = min(DP[i][j], (1 + DP[k][j] + DP[i - k][j]));
            for (int k = 1; k < j; k++)
                DP[i][j] = min(DP[i][j], (1 + DP[i][k] + DP[i][j - k]));
        }
    }
    
    cout << DP.back().back();
}
