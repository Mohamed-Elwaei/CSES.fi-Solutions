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
    int n,x;
    cin >> n >> x;
    vector<int> coins(n,0);
    
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    
    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;
    
    for (int i = 1; i <= x; i++) {
        for(auto& coin: coins)
            if ( i - coin >= 0)
                dp[i] = min(dp[i], 1 + dp[i - coin]);
    }
    
    if (dp.back() == 1e9) 
        cout << -1;
    else
        cout << dp.back();
    
    
}