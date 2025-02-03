#include <iostream>
#include <vector>
#include <cmath>
#define MAXN 200010
#define LOG 18
 
using namespace std;
 
int n, q;
vector<int> adj[MAXN];
int up[MAXN][LOG]; // up[v][j] is 2^j-th ancestor of v
int depth[MAXN];
 
void dfs(int v, int parent) {
    up[v][0] = parent;
    for (int i = 1; i < LOG; i++) {
        if (up[v][i-1] != -1) {
            up[v][i] = up[up[v][i-1]][i-1];
        } else {
            up[v][i] = -1;
        }
    }
    for (int u : adj[v]) {
        if (u != parent) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}
 
int getKthAncestor(int u, int k) {
    for (int i = 0; i < LOG && u != -1; i++) {
        if ((1 << i) & k) {
            u = up[u][i];
        }
    }
    return u;
}
 
int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    u = getKthAncestor(u, depth[u] - depth[v]);
    if (u == v) {
        return u;
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
 
int main() {
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
        adj[i].push_back(boss);
    }
 
    depth[1] = 0;
    dfs(1, -1);
 
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
 
    return 0;
}
