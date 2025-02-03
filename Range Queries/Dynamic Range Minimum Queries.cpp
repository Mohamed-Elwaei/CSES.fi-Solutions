#include <iostream>
#include <vector>
#include <bit>
using namespace std;
#define lli  long long int
#define INF 1e9
 
int n,q;
 
vector<int> T,A;
 
 
int M(int node, int node_low, int node_high, int q_low, int q_high){
    if (q_low > node_high || q_high < node_low)
        return INF;
    else if (q_low <= node_low && node_high <= q_high)
        return T[node];
    
    int mid = (node_high + node_low) / 2;
    
    return min( M( 2*node, node_low, mid, q_low, q_high), M(2*node + 1, mid + 1, node_high, q_low, q_high));
}
void update(int node, int node_low, int node_high, int q_low, int q_high, int newVal){
    if (q_low > node_high || q_high < node_low)
        return ;
    else if (q_low <= node_low && node_high <= q_high){
        T[node] = newVal;
        return;
    }
    int mid = (node_high + node_low) / 2;
    
    update(2 * node, node_low, mid, q_low, q_high, newVal);
    update(2*node + 1, mid + 1, node_high, q_low, q_high, newVal);
    
    T[node] = min(T[node*2] , T[node*2 + 1]);
}
 
 
               
               
int main(){
    cin >> n >> q;
    
    A.resize(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    n = bit_ceil((unsigned int) n);
    T.resize(2 * n);
    for (int i = 0; i < n; i++)
        T[n + i] = A[i];
    
    for (int i = n - 1; i >= 1; i--)
        T[i] = min(T[2*i],T[2*i+1]);
    
    while (q--){
        int type; cin >> type;
        
        if (type == 1){
            int k,u; cin >> k >> u;
            k--;
            update(1,0,n-1,k,k,u);
        }
        else{
            int a,b; cin >> a >> b;
            a--; b--;
            
            cout << M(1,0,n-1,a,b) << "\n";
        }
    }
    
    
}