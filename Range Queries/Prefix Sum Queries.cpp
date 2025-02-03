#include <iostream>
#include <vector>
#include <bit>
using namespace std;
#define lli  long long int
int n,q;
/*
 Segment tree that uses the maximum for an interval.
 
 We update a single node.
 */
#define INF 1e9
 
 
vector<pair<lli,lli>> V,T;
 
pair<lli,lli> G(int node, int node_low, int node_high, int a, int b){
    if (a <= node_low && node_high <= b)
        return T[node];
    if (a > node_high || b < node_low)
        return {0,0};
    int mid;
    pair<lli,lli> left,right;
    mid = (node_low + node_high) / 2;
    left = G(node*2, node_low, mid, a, b);
    right = G(node*2 + 1, mid + 1, node_high, a, b);
    
    return make_pair(max(left.first, left.second + right.first), left.second + right.second);
}
 
 
void update(int node, int node_low, int node_high, int k, int u){
    if (node_low > k || node_high < k)
        return ;
    
    if (node_low == node_high){
        if (node_low == k)
            T[node] = make_pair(max(0, u), u);
        return;
    }
    
    int mid = (node_low + node_high) / 2;
    update(node * 2, node_low, mid, k, u);
    update(node * 2 + 1, mid + 1, node_high, k, u);
    
    T[node] = make_pair(max(T[node*2].first, T[node*2].second + T[node*2 + 1].first), T[node*2].second + T[node*2 + 1].second);
}
 
               
               
int main(){
    cin >> n >> q;
    V.resize(n);
    
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        V[i] = make_pair(max(0,x), x);
    }
    n = bit_ceil((unsigned int) n);
    T.resize(2*n);
    for (int i = 0; i < V.size(); i++){
        T[i+n] = V[i];
    }
    
    
    
    for (int i = n - 1; i >= 1; i--){
        T[i] = make_pair(max(T[i*2].first, T[i*2].second + T[i*2 + 1].first), T[i*2].second + T[i*2 + 1].second);
    }
    
    
    for (int i = 0; i < q; i++){
        int type; cin >> type;
        
        if (type == 2){
            int a,b; cin >> a >> b;
            cout << G(1, 0, n-1, --a, --b).first << "\n";
        }
        else{
            int k,u; cin >> k >> u;
            update(1, 0, n - 1, --k, u);
        }
        
    }
}