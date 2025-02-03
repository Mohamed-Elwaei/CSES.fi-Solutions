#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <functional>
#include <bit>
 
using namespace std;
#define lli long long int
#define INF 1e14
#define pb push_back
int n,q;
 
 
 
int T[30][(int) 2e5+1];
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++){
        cin >> T[0][i];
    }
    
    
    for (int i = 1; i < 30; i++){
        for (int j = 1; j <= n; j++){
            T[i][j] = T[i-1][T[i-1][j]];
        }
    }
    
    
    for (int i = 0; i < q; i++){
        int successor,node; cin >> node >> successor;
        
        while (successor) {
            int bit = successor & -successor;
            successor -= bit;
            bit = bit_width((unsigned int) bit) - 1;
            
            node = T[bit][node];
        }
        cout << node << "\n";
    }   
}