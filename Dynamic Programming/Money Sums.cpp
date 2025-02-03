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
    int n; cin >> n;
    vector<int> C(n);
    lli rows = 0;
    for (auto &c: C) {
        cin >> c;
        rows += c;
    }
    vector<vector<int>> DP(rows+1, vector<int>(n,0));
    
    for (int i = 0; i < n; i++) DP[0][i] = 1;
    DP[C[0]][0] = 1;
    
    for (int r = 1; r <= rows; r++){
        for (int c = 1; c < n; c++){
            DP[r][c] = DP[r][c-1];
            if (r - C[c] >= 0)
                DP[r][c] |= DP[r - C[c]][c-1];
        }
    }
    
    lli distinctSums = -1;
    for (auto& v: DP) distinctSums += v.back();
    
    cout << distinctSums << "\n";
    for (int r = 1; r <= rows; r++)
        if (DP[r].back())
            cout << r << " ";
    
}