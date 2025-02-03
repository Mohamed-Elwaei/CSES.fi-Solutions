#include <vector>
#include <map>
#include <iostream>
 
 
using namespace std;
#define lli long long int
/*
 5
 3 1 2 7 4 2
 3 4 6 13 17 19
 
 sum mod 5 = 0 :
 sum mod 5 = 1 : 1
 sum mod 5 = 2 : 1
 sum mod 5 = 3 : 2
 sum mod 5 = 4 : 2
 
 ans = 1 + 1
 */
 
int main()
{
    int n; cin >> n;
    vector<int> V(n,0); //At index i, this will map how many prefix sums have sum % 5 = i;
    V[0] = 1;
    
    
    lli sum = 0, ans = 0;
    for (int i = 0; i < n; i++){
        lli x;
        cin >> x;
        sum = ((sum + x) % n + n) % n;
        ans += V[sum];
        V[sum] += 1;
    }
    
    cout << ans;
    
    
}