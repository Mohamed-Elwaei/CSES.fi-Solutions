#include <iostream>
#include <vector>
#include <bit>
using namespace std;
#define lli  long long int
 
int n,q;
 
vector<lli> T,A;
 
 
void update(int node, int node_low, int node_high, int a, int b , int u){
    if (node_low > b || node_high < a)
        return ;
    else if (a <= node_low && node_high <= b){
        T[node] += u;
        return;
    }
    else{
        int mid = (node_low + node_high) / 2;
        update(node*2, node_low, mid, a, b, u);
        update(node*2 + 1, mid + 1, node_high, a , b, u);
    }
    
}
 
 
lli G(int node, int node_low, int node_high, int k){
    if (k < node_low || k > node_high)
        return 0;
    else if (node_low == k && node_high == k)
        return  T[node];
    
    int mid = (node_low + node_high) / 2;
    lli sum = G(node*2, node_low, mid, k) + G(node*2 + 1, mid + 1, node_high, k);
    return sum + T[node];
}
 
 
               
               
int main(){
    cin >> n >> q;
    
    A.resize(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    n = bit_ceil((unsigned int) n);
    T.resize(2 * n);
    
    for (int i = 0; i < n; i++)
        T[i+n] = A[i];
    
    
    while (q--){
        int type; cin >> type;
        
        if (type == 1){
            int a,b,u; cin >> a >> b >> u;
            a--;b--;
            update(1, 0, n-1, a, b, u);
        }
            
        else {
            int k; cin >> k;
            k--;
            cout << G(1, 0, n-1, k) << "\n";
            
        }
    }
    
    
    
}