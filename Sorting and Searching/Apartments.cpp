#include <set>
#include <iostream>
#include <vector>
 
 
using namespace std;
 
int main()
{
    
    int n,m,k; cin >> n >> m >> k;
    
    vector<int> P(n), H(m);
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> H[i];
    }
    sort(P.begin(), P.end());
    sort(H.begin(), H.end());
    
    int i = 0, j = 0, ans = 0;
    
    while (i < n && j < m) {
        if (P[i] - k > H[j])
            j++;
        else if (H[j] - k > P[i])
            i++;
        else{
            i++;j++; ans++;
        }
    }
    cout << ans;
}