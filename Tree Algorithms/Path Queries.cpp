#include <iostream>
#include <vector>
using namespace std;
 
#define lli long long int
 
int n, m;
vector<vector<int>> G;
vector<lli> BIT;
vector<int> S, E, V;
 
int timer = 1;
 
void dfs(int u, int par) {
    S[u] = timer++;
    for (int v : G[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
    E[u] = timer++;
}
 
void update(int index, int delta) {
    while (index <= 2 * n) {
        BIT[index] += delta;
        index += (index & -index);
    }
}
 
lli sum(int index) {
    lli result = 0;
    while (index >= 1) {
        result += BIT[index];
        index -= (index & -index);
    }
    return result;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    G.resize(n + 1);
    S.resize(n + 1);
    E.resize(n + 1);
    V.resize(n + 1);
    BIT.resize(2 * n + 1, 0);
    
    for (int i = 1; i <= n; i++)
        cin >> V[i];
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    dfs(1, -1);
    
    for (int i = 1; i <= n; i++) {
        update(S[i], V[i]);
        update(E[i], -V[i]);
    }
    
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            int diff = x - V[s];
            update(S[s], diff);
            update(E[s], -diff);
            V[s] = x;
        } else if (type == 2) {
            int s;
            cin >> s;
            cout << sum(S[s]) << "\n";
        }
    }
 
    return 0;
}