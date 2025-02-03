#include <vector>
#include <map>
#include <iostream>
 
 
using namespace std;
#define lli long long int
 
 
 
 
 
int main()
{
    int n; cin >> n;
    vector<int> V(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    int l= 0;
    
    map<int, int> S;
    int ans = 0;
    for (int r = 0; r < n; r++){
        S[V[r]] += 1;
        
        while (S[V[r]] > 1) {
            S[V[l]] -= 1;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
    
}