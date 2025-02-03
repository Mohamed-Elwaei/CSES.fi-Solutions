#include <vector>
#include <set>
#include <iostream>
 
 
using namespace std;
#define lli long long int
 
//Knapsack Problem: Dimensions are total price x, and the books we have
// 2-D DP problem
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,x; cin >> n >> x;
    
    vector<int> C(n), P(n);
    for (int i = 0; i < n; i++) cin >> C[i];
    for (int i = 0; i < n; i++) cin >> P[i];
    
    vector<vector<int>> V(n+1, vector<int>(x+1,0));
    
    for (int r = 1; r <= n; r++){
        for (int c = 1; c <= x; c++){
            V[r][c] = V[r-1][c];
            
            if (c - C[r-1] >= 0)
                V[r][c] = max(V[r][c], V[r-1][c - C[r-1]] + P[r - 1]);
            
        }
    }
    
    cout << V[n][x];
}