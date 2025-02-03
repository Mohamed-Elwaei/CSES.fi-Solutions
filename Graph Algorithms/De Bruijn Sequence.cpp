#include <cmath>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <tuple>
 
using namespace std;
#define lli long long int
int n, k = 2;
 
int mask = 0;
 
 
vector<vector<int>> G;
 
 
vector<int> cycle;
 
 
 
 
int main() {
    cin >> n;
    if (n == 1){
        cout << 10; return 0;
    }
    
    for (int i = 0; i < n - 1; i++)
        mask |= (1 << i);
    G.resize((1 << (n - 1)));
    
    
    
    for (int i = 0; i < 1 << (n - 1); i++){
        
        int first = (i << 1) & mask;
        int second = first | 1;
        
        G[i].push_back(first); G[i].push_back(second);
        
    }
    
    stack<int> S;
    
    S.push(0);
    vector<int> cycle;
    
    while (!S.empty()) {
        int u = S.top();
        
        if (G[u].empty()){
            S.pop();
            cycle.push_back(u);
        }
        else{
            S.push(G[u].back());
            G[u].pop_back();
        }
        
    }
    reverse(cycle.begin(), cycle.end());
    
    
    for (int i = 0; i < n - 1; i++)
        cout << 0;
    for (int i = 1; i < cycle.size(); i++){
        cout << (cycle[i] & 1);
    }
    
    return 0;
}