#include <vector>
#include <set>
#include <iostream>
 
 
using namespace std;
#define lli long long int
 
 
 
 
 
int main()
{
    int n,x;
    cin>>n;
    multiset<int>s;
    for (int i = 0; i < n; i++){
        cin >> x;
        auto it = s.upper_bound(x);
        
        if (it == s.end()) {
            s.insert(x);
        }
        else {
            s.erase(it);
            s.insert(x);
        }
    }
    cout << s.size();
    
}