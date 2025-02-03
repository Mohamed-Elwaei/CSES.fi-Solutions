#include <set>
#include <iostream>
#include <vector>
#include <bitset>
 
using namespace std;
 
 
bool cmp(pair<int,int>& a, pair<int,int>& b){
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
 
 
 
int main()
{
    
    int n,m;
    cin >> n >> m;
    multiset<int, greater<int> > tickets;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        tickets.insert(x);
    }
    
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        auto res = tickets.lower_bound(x);
        if (res == tickets.end())
            cout << -1 << "\n";
        else{
            cout << *res << "\n";
            tickets.erase(res);
        }
    }
    
}