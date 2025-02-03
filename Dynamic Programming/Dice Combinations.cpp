#include <vector>
#include <iostream>
 
/*
 n = 1, F(1) = 1
 n = 2, F(2) = 1 * F(1), 2 * F(0)
 n = 3, F(3) = 1 * F(2), 2 * F(1), 3 * F(0)
 n = 4, F(4) = 1 * F(3), 2 * F(2), 3 * F(1), 4 * F(0)
 
 
 */
 
 
using namespace std;
int main()
{
    int M = 1e9 + 7, N;
    
    cin >> N;
    vector<int> dp(N+1, 0);
    dp[0] = 1;
    
    for (int i = 1; i <= N; i++) {
        for (int j = i - 1; j >= max(0, i - 6); j--) {
            (dp[i] += dp[j]) %= M;
        }
    }
    cout << dp[N] << "\n";
    
}