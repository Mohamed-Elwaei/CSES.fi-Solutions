#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define lli  long long int
 
 
 
 
 
 
int main(){
    lli n,last = 0,curr;
    cin >> n;
    lli ops = 0;
    while (n--){
        cin >> curr;
        
        ops += max(last - curr, 0LL);
        
        last = max(last, curr);
    }
    
    cout << ops;
}
