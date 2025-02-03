#include <vector>
#include <iostream>
 
using namespace std;
#define lli long long int
 
bool cmp(pair<int,int>& a, pair<int,int>&b){
    return a.second < b.second;
}
 
 
int main()
{
    lli n,sum = 0; cin >> n;
    
    vector<lli> V(n);
    cin >> V[0];
    
    for (int i = 1; i < n; i++){
        cin >> V[i];
    }
    
    sort(V.begin(), V.end());
    
    lli mid = V[n/2], ans = 0;
    
    for (auto &x: V)
        ans += abs(x - mid);
    cout << ans;
   
}