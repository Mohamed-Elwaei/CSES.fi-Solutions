#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define lli long long int
int m = 1e9 + 7;
const int max_n = (1e6 + 1) * 2;
 
 
/*
 ans[n] = C(2n,n) - C(2n,n-1)
 
 */
 
lli ans[max_n], factorial[max_n];
 
 
lli power(int a, int b, int mod){
    if (b == 0)
        return 1;
    
    lli u = power(a,b/2,mod);
    
    lli res = (u*u) % mod;
    
    if (b & 1)
        res = (res * a) % mod;
    
    return res;
    
}
lli fermat(int a){
    
    return power(a, m - 2, m);
}
 
 
 
lli C(int n, int k){
    return factorial[n] * fermat(factorial[k] * factorial[n-k] % m) % m;
}
 
 
 
 
 
 
int main(){
    factorial[0] = 1;
    
    for (int i = 1; i < max_n; i++){
        factorial[i] = (factorial[i-1] * i) % m;
    }
   
    int n; cin >> n;
    
    if (n&1) {
        cout << 0;
        return 0;
    }
    n /= 2;
    
    cout << (C(2 * n, n) - C(2 * n, n - 1) + m) % m;
}