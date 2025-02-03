#include <vector>
#include <set>
#include <iostream>
 
 
using namespace std;
#define lli long long int
 
 
 
lli INF = 1e13;
int main(){
    
    int n; cin >> n;
    
    vector<lli> V(n+1,INF);
    V[0] = 0;
    
    for (int i = 1; i <= n; i++){
        lli num = i;
        
        while (num) {
            V[i] = min(V[i], 1 + V[i - (num % 10)]);
            num /= 10;
        }
    }
    cout << V.back();
}