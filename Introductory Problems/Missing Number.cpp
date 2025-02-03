#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define lli  long long int
 
 
lli n;
 
 
 
int main(){
    cin >> n;
    
    lli sum = n * (n + 1) / 2;
    
    while (--n)
    {
        int x; cin >> x;
        sum -= x;
    }
    cout << sum;
}