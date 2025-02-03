#include <set>
#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
 
using namespace std;
 
 
bool cmp(pair<int,int>& a, pair<int,int>&b){
    return a.second < b.second;
}
 
 
int main()
{
    int n; cin >> n;
    vector<pair<int, int> > P(n);
    
    for (int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        P[i] = make_pair(a, b);
    }
    
    sort(P.begin(), P.end(), cmp);
    
    int e = P[0].second;
    int ans = 1;
    
    for (int i = 1; i < n; i++){
        if (P[i].first >= e)
        {
            e = P[i].second;
            ans++;
        }
    }
    
    cout << ans;
    
    
}