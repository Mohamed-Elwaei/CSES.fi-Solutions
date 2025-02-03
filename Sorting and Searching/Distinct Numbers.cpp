#include <set>
#include <iostream>
 
 
 
using namespace std;
 
int main()
{
 
    int n,x;
    cin >> n;
    
    set<int> S;
    
    while (n--) {
        cin >> x;
        S.insert(x);
    }
    
    cout << S.size();
}