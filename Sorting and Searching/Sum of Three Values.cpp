#include <vector>
#include <iostream>
 
 
 
using namespace std;
#define lli long long int
 
 
 
 
 
int main()
{
    lli n,t; cin >> n >> t;
    
    vector<pair<lli,lli>> V(n);
    
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        V[i] = make_pair(x, i+1);
    }
    
    sort(V.begin(), V.end());
    
    for (auto it = V.begin(); it != V.end(); it++){
        for (auto it2 = it + 1; it2 != V.end(); it2++){
            lli a = (*it).first, b = (*it2).first , c = t - a - b;
            
            auto it3 = lower_bound( it2 + 1, V.end(), make_pair(c,0ll));
            
            if (it3 == V.end() || (*it3).first != c)
                continue;
            
            cout << (*it).second << " " << (*it2).second << " " << (*it3).second ;
            return 0;
            
            
        }
    }
    
    cout << "IMPOSSIBLE";
}