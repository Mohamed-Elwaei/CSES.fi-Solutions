#include <iostream>
#include <map>
#include <vector>
#include <cmath>
 
using namespace std;
#define lli long long unsigned int
const int max_n = 1e6 + 1;
 
int divisors[max_n];
 
 
 
 
 
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        
        int limit = (int) sqrt(x);
        
        for (int j = 1; j <= limit; j++){
            if (x % j == 0){
                divisors[j]++;
                
                
                if (j != x/j) divisors[x/j]++;
            }
        }
    }
    
    int i = max_n - 1;
    for (; i >= 1; i--){
        if (divisors[i] > 1) break;
    }
    
    cout << i;
}