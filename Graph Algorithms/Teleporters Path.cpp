#include <cmath>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <tuple>
 
 
using namespace std;
#define lli long long int
 
/*
 First verify there is an eulerian path:
 Either each node has indegree == outdegree or (1 node has indegree - outdegree = 1 and another outdegree - indegree = 1).
 In the second case, make sure node 1 has one more outdegree and node n has one more indegree
 
 
 Then find the eulerian path. Hierholzer's algorithm.
 
 
 */
 
 
int n,m;
vector<vector<int>> G;
vector<int> ins,outs;
 
 
 
 
 
int main() {
    
    cin >> n >> m;
    
    G.resize(n+1);
    ins.resize(n + 1); outs.resize(n + 1);
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
        ins[v]++; outs[u]++;
    }
    
    int x = 0;
    bool bad = false;
    
    for (int i = 1; i <= n; i++){
        if (outs[i] - ins[i] == 1){
            if (i != 1){
                bad = 1;
            }
            x++;
        }
        else if (ins[i] - outs[i] == 1){
            if (i != n){
                bad = 1;
            }
            x++;
        }
    }
    
    if(x != 2)
        bad = 1;
    if (bad){
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    
    if (outs[1] > ins[1]){
        outs[n]++; ins[1]++;
        G[n].push_back(1);
    }
    
    stack<int> S;
    vector<int> res;
    
    S.push(1);
    
    while (!S.empty()) {
        int u = S.top();
        if (G[u].empty()){
            res.push_back(u);
            S.pop();
        }
        else {
            S.push(G[u].back());
            G[u].pop_back();
            outs[u]--; ins[S.top()]--;
        }
    }
    
    
    for (int i = 0; i <= n; i++){
        if (ins[i] || outs[i]){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    
    int i = 0;
    reverse(res.begin(), res.end());
    for (i = 0; i < (int) res.size() - 1; i++){
        if (res[i] == n && res[i+1] == 1){
            break;
        }
    }
    
    
    for (int j = i + 1; j < (int) res.size(); j++){
        cout << res[j] << " ";
    }
    for (int j = 1; j <= i; j++){
        cout << res[j] << " ";
    }
    
}