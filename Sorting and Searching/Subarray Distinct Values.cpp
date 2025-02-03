#include <vector>
#include <map>
#include <iostream>
 
 
using namespace std;
#define lli long long int
 
 
/*
 5 2
 1 2 3 1 1
 
 ans = 0 + 1 + 2 + 3
 ans += r - l + 1;
 
 
 */
 
 
int main()
{
    int n, k; cin >> n >> k;
    vector<int> V(n);
    
    for (int i = 0; i < n; i++) cin >> V[i];
    
    map<int,int> MP; // Map each number to its ocurrences in the window;
    int l = 0;
    
    lli ans = 0;
    for (int r = 0; r < n; r++){
        MP[V[r]] += 1;
        
        while (l < r && MP.size() > k){
            MP[V[l]] -= 1;
            if (MP[V[l]] == 0) MP.erase(V[l]);
            l++;
            
        }
        ans += (r - l + 1) ;
    }
    cout << ans;
}
