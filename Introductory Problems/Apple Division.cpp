#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bit>
 
 
using namespace std;
#define lli  long long int
#define INF 1e14
 
int n;
 
 
 
 
int main(){
    cin >> n;
    
    vector<int> V(n);
    for (int i = 0; i < n; i++){
        cin >> V[i];
    }
    
    
    
    lli ans = INF;
    
    
    for (int i = 0; i < (1 << n) - 1; i++){
        
        lli s1 = 0LL;
        lli s2 = 0LL;
        
        for (int j = 0; j < n; j++){
            if (i & (1 << j))
                s1 += V[j];
            else
                s2 += V[j];
        }
        
        ans = min(ans, abs(s1 - s2));
    }
    
    
    cout << ans;
    
    
    
    
    
}