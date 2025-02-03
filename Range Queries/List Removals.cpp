#include <iostream>
#include <vector>
#include <set>
#include <bit>
 
using namespace std;
#define lli  long long int
 
 
int n;
 
vector<pair<int,int>> T;
vector<int> V;
 
 
 
int F(int node, int node_low, int node_high, int k){
    if (node_low > k || node_high < k)
        return 0;
    else if (node >= n){
        if (node_low == k){
            T[node] = make_pair(0,0);
            return V[node - n];
        }
        return 0;
    }
    
    int ans = max(F(node * 2, node_low, node_high - T[node].second,  k),
                  F(node * 2 + 1, node_low + T[node].first, node_high, k));
    
    T[node] = make_pair(T[node*2].first + T[node*2].second, T[node*2 + 1].first + T[node*2 + 1].second);
    
    return ans;
}
 
 
 
int main(){
    cin >> n;
    V.resize(n);
    
    for (auto& v: V) cin >> v;
    
    n = bit_ceil((unsigned int) n);
    
    T.resize(2 * n, make_pair(1, 0));
    
    for (int i = 0; i < V.size(); i++){
        T[i+n] = make_pair(1, 0);
    }
    
    for (int i = n - 1; i >= 1; i--){
        T[i] = make_pair(T[i*2].first + T[i*2].second, T[i*2 + 1].first + T[i*2 + 1].second);
    }
    
    
    for (int i = 0; i < V.size(); i++){
        int k; cin >> k;
        cout << F(1, 1, T[1].first + T[1].second, k) << " ";
    }
}