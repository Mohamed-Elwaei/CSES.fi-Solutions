#include <set>
#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
 
using namespace std;
 
 
 
 
int main()
{
    int n; cin >> n;
    vector<pair<int,int> > P(n);
    
    for (int i = 0; i < n; i++){
        int s,e;
        cin >> s >>e;
        P[i] = make_pair(s,e);
    }
    sort(P.begin(), P.end());
    priority_queue<int, vector<int>,greater<int> > Q;
    
    
    Q.push(P[0].second);
    int ans = 0;
    for(int i = 1; i < n; i++){
        if (P[i].first > Q.top()){
            Q.pop();
        }
        Q.push(P[i].second);
        ans = max(ans, (int) Q.size());
    }
    cout << ans;
 
    
}
