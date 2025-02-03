#include <vector>
#include <iostream>
#include <set>
 
using namespace std;
#define lli long long int
 
bool cmp(pair<int,int>& a, pair<int,int>&b){
    return a.second < b.second;
}
 
 
int main()
{
    lli n; cin >> n;
    vector<lli> V(n);
    
    for(lli i = 0; i < n; i++)
        cin >> V[i];
    sort(V.begin(), V.end());
    
    
    lli sm = 1l;
    
    for (auto &v: V)
        if (v > sm)
            break;
        else
            sm += v;
    cout << sm;
    
    
    
}