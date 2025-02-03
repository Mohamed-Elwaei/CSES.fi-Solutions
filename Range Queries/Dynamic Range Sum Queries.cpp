#include <iostream>
#include <vector>
#include <bit>
using namespace std;
#define lli  long long int
 
int n,q;
 
vector<lli> T,A;
 
lli sum(int node, int node_low, int node_high, int q_low, int q_high, int v){
    if (q_high < node_low || q_low > node_high){
        return 0;
    }
    else if (q_low <= node_low && node_high <= q_high){
        if (v != 0)
            T[node] = v;
        return T[node];
    }
    int mid = (node_high - node_low) / 2 + node_low;
    lli s = sum(2*node, node_low, mid, q_low, q_high, v) + sum(2*node+1, mid + 1, node_high, q_low, q_high, v);
    T[node] = T[node * 2] + T[node * 2 + 1];
    return s;
}
 
 
 
int main(){
    
    cin >> n >> q;
    
    A.resize(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    n = bit_ceil((unsigned int) n);
    T.resize(2*n);
    
    for (int i = 0; i < (int) A.size() ; i++)
        T[i+n] = A[i];
    
    for (int i = n - 1; i >= 1; i--){
        T[i] = T[2*i] + T[2*i + 1];
    }
    
    while (q--) {
        int type; cin >> type;
        
        if (type == 1){
            int k,u; cin >> k >> u;
            sum(1,0,n-1,k-1,k-1,u);
        }
        else{
            int a,b; cin >> a >> b;
            cout << sum(1,0,n-1,--a,--b,0) << "\n";
        }
            
        
    }
    
    return 0;
    
}