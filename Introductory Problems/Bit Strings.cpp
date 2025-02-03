#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define lli  long long int
 
#define llu unsigned long long int
 
lli M = 1e9 + 7;
 
lli power(lli base, lli exp){
    lli res;
    if (exp == 0)
        return 1;
    else if (exp%2 == 1){
        res = power(base, exp / 2);
        return (base * res * res) % M;
    }
    else {
        res = power(base, exp / 2);
        return (res * res) % M;
    }
    
}
 
 
 
int main(){
    lli n; cin >> n;
    
    cout << power(2, n);
}
