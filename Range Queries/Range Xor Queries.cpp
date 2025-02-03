#include <iostream>
#include <vector>
#include <bit>
using namespace std;
#define lli  long long int
 
int n,q;
 
vector<lli> T,A;
 
 
//XOR(n,0) = n always. so 0 is the identity element.
 
lli XOR(int node, int node_low, int node_high, int q_low, int q_high){
    if (node_low > q_high || q_low > node_high)
        return 0;
    else if (q_low <= node_low && node_high <= q_high)
        return T[node];
    
    int mid = (node_high + node_low) / 2;
    return XOR(node*2, node_low, mid, q_low, q_high) ^ XOR(node*2 + 1, mid + 1, node_high, q_low, q_high);
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
    
    
    for (int i = n - 1; i >= 1; i--){
        T[i] = T[i*2] ^ T[i*2 + 1];
    }
    
    
    while (q--){
        int a, b; cin >> a >> b;
        a--;b--;
        cout << XOR(1, 0, n-1, a, b) << "\n";
    }
}