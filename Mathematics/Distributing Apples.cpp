#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define lli  long long int
const int max_n = (1e6 + 1) * 2;
 
int m = 1e9 + 7;
 
lli factorial[max_n];
 
int F[26];
 
lli power(int a, int b, int m) {
    if (b == 0)
        return 1;
 
    lli u = power(a, b / 2, m);
    lli res = (u * u) % m;
 
    if (b & 1)
        res = (res * a) % m;
    return res;
}
 
lli fermat(int a, int m) {
    return power(a, m - 2, m);
}
 
lli C(int n, int k) {
    if (k > n || k < 0) return 0;
    lli res = factorial[n];
    res = res * fermat((int) factorial[k], m) % m;
    res = res * fermat((int) factorial[n - k], m) % m;
    return res;
}
 
int main() {
    factorial[0] = 1;
    for (int i = 1; i < max_n; i++) {
        factorial[i] = (factorial[i - 1] * i) % m;
    }
 
    int n,k; cin >> n >> k;
    
    cout << C(n+k-1,k);
    
}