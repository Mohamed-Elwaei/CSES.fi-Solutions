#include <set>
#include <iostream>
#include <vector>
#include <bitset>
 
 
using namespace std;
 
int main()
{
    
    int n,x;
    cin >> n >> x;
    vector<int> C(n);
    for (int i = 0; i < n; i++)
        cin >> C[i];
    sort(C.begin(),C.end());
    
    int ans = 0, i = 0, j = n - 1;
    vector<bool> vis(n,0);
    
    while (i < j){
        if (C[i] + C[j] > x)
            j--;
        else {
            ans++; vis[i++] = vis[j--] = 1;
        }
    }
    
    for(auto c : vis)
        ans += (c == 0);
    cout << ans;
}