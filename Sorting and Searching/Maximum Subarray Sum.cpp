#include <map>
#include <iostream>
 
using namespace std;
#define lli long long int
 
bool cmp(pair<int,int>& a, pair<int,int>&b){
    return a.second < b.second;
}
 
 
int main()
{
    lli n,s = 0; cin >> n;
    
    lli ans = -1e9;
    while (n--){
        int x;
        cin >> x;
        s += x;
        ans = max(ans, s);
        s = max(s,0LL);
    }
    cout << ans;
    
}
