#include <map>
#include <iostream>
 
using namespace std;
 
 
bool cmp(pair<int,int>& a, pair<int,int>&b){
    return a.second < b.second;
}
 
 
int main()
{
    int n,x; cin >> n >> x;
    
    map<int, int> mp;
    
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        if(mp.find(x - a) != mp.end()){
            cout << mp[x - a] + 1 <<" " << i + 1 << "\n";
            return 0;
        }
        mp.insert({a, i});
    }
    cout << "IMPOSSIBLE";
    
}
