#include <vector>
#include <set>
#include <iostream>
 
 
using namespace std;
#define lli long long int
 
 
 
 
int main(void){
    int n,a,b; cin >> n >> a >> b;
    vector<int> V(n);
    vector<lli> PS(n+1);
    PS[0] = 0;
    for (int i = 0; i < n; i++){
        cin >> V[i];
        PS[i+1] = PS[i] + V[i];
    }
    
    multiset<lli> S;
    lli res = -1e19;
    
    for (int i = a; i <= n; i++){
        S.insert(PS[i - a]);
        if (i > b)
            S.erase(S.find(PS[i - b - 1]));
        
        res = max(res, PS[i] - *S.begin());
    }
    cout << res;
    
    
