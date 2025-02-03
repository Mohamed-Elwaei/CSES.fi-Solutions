#include <vector>
#include <set>
#include <iostream>
 
 
using namespace std;
#define lli long long int
 
 
 
 
int main(){
    // If target - coin > 0:
    //  How many ways can target - coin be formed
    
    int n,x; cin >> n >> x;
    lli M = 1e9 + 7;
    
    vector<lli> dp(x+1,0), C(n);
    dp[0] = 1;
    for (auto &c: C) cin >> c;
    
    for (auto& c : C){
        for (int i = 0; i <= x; i++){
            if (i - c >= 0){
                dp[i] = (dp[i] + dp[i - c]) % M;
            }
        }
    }
    
    cout << dp.back();
    
}