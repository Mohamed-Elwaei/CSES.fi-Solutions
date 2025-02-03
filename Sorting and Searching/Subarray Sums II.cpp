#include <vector>
#include <map>
#include <iostream>
 
 
using namespace std;
#define lli long long int
/*
 5 7
 2 -1 3 5 -2
 
 PS = 2 1 4 9 7
 
 
 
 5 1
 1 -1 1 -1 1
 
 
 */
 
int main()
{
    int n, x; cin >> n >> x;
    vector<int> V(n);
    map<lli, lli> PS; //Map each sum to how many subarrays beginning at 0 have that sum
    PS[0] = 1;
    
    lli sum = 0, ans = 0;
    for (int i = 0; i < n; i++){
        cin >> V[i];
        sum += V[i];
        if (PS.find(sum - x) != PS.end()) {
            ans += PS[sum - x];
        }
        PS[sum] += 1;
    }
    
    
    cout << ans;
    
    
    
}