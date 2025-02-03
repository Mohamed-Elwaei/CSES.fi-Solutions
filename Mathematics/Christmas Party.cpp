#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define lli long long int
int m = 1e9 + 7;
const int max_n = 1e6 + 1;
 
lli D[max_n];
 
 
 
 
 
 
 
 
 
 
 
int main(){
    
    D[0] = 1;
    D[1] = 0;
    
    for (int i = 2; i < max_n; i++){
        D[i] = ((i-1) * ((D[i-1] + D[i-2]) % m)) % m;
    }
    
    
    int n; cin >> n;
    cout << D[n];
    
}
