#include <iostream>
#include <vector>
using namespace std;
#define lli long long unsigned int
 
 
 
lli solve(int x){
    vector<int> primes;
    vector<int> count;
    
    for (int i = 2; i*i <= x; i++){
        int c = 0;
        while (x % i == 0){
            c++;
            x /= i;
        }
        if (c != 0){
            count.push_back(c);
            primes.push_back(i);
        }
    }
    
    if (x != 1){
        count.push_back(1);
        primes.push_back(x);
    }
    
    lli ans = 1;
    
    for (int i = 0; i <  (int) count.size(); i++){
        ans = ans * (count[i] + 1);
    }
    return ans;
}
 
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    int q; cin >> q;
    
    
    for (int i = 0; i < q; i++){
        int x; cin >> x;
        cout << solve(x) << "\n";
        
    }
 
}