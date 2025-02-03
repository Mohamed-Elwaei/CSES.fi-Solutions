#include <vector>
#include <iostream>
 
 
using namespace std;
#define lli long long int
 
bool cmp(pair<int,int>& a, pair<int,int>&b){
    return a.second < b.second;
}
 
 
int main()
{
    int n;
    cin >> n;
    
    int ans = 1;
    vector<int> V(n+1,0);
    V[0] = 1;
    while (n--){
        int x; cin >> x;
        if(!V[x-1])
            ans++;
        V[x] = 1;
    }
    cout << ans;
    
    
}
