#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define lli  long long int
lli n;
 
vector<int> V1,V2;
 
 
int main(){
    cin >> n;
    lli sum = n * (n+1) / 2, target = sum / 2;
    
    
    if (target * 2 != sum){
        cout << "NO\n";
        return 0;
    }
    
    
    for ( ; n >= 1; n--){
        if (target - n >= 0){
            V1.push_back(n);
            target -= n;
        }
        else {
            V2.push_back(n);
        }
    }
    
    
    cout << "YES\n" << V1.size() << "\n";
    
    for (auto &v: V1)
        cout << v << " ";
    cout << "\n" << V2.size() << "\n";
    for (auto &v: V2)
        cout << v << " ";
    
    
    
    
    
    
}