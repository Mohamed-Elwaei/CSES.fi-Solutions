#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define lli  long long int
int t;
 
 
 
int main(){
    cin >> t;
    
    
    while (t--){
        lli r,c; cin >> r >> c;
        
        lli n = max(r*r,c*c);
        
        if (n%2 == 1){
            if (c > r){
                cout << n - r + 1 << "\n";
            }
            else {
                cout << n - (2*r - 1) + c << "\n";
            }
        }
        
        else if (n%2 == 0){
            if (r > c)
                cout << n - c + 1 << "\n";
            else
                cout << n - (2*c - 1) + r << "\n";
        }
    }
}
