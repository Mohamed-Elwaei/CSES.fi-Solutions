#include <iostream>
#include <vector>
using namespace std;
#define lli long long int
int n = 1e9 + 7;
 
 
 
lli power(int a, int b){
    if (b == 0)
        return 1LL;
    
    
    lli u = power(a, b/2) % n;
    
    lli res = (u * u) % n;
    if (b & 1)
        res = (res * a) % n;
        
    return res;
}
 
 
 
 
int main(){
    int q; cin >> q;
    
    for (int i = 0; i < q; i++){
        int a,b; cin >> a >> b;
        
        cout << power(a,b) << "\n";
    }
}
