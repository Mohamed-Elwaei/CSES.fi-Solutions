#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#define lli long long int
 
 
using namespace std;
int n;
 
 
/*
 
 Brute Force: O(n^2)
  Root the tree n times, and do a dfs to find out the sum of distances to all nodes from the root.
 
 
 Intuition:
    As we move through the tree we get closer to certain nodes, and farther from certain nodes.
    If we choose the ith node, we get closer to all of the nodes rooted at the ith node, and further from all other nodes.
    We can keep track of how many nodes we are closer to and farther from and update the score accordingly.
 
 
 Optimal:
 Let score be the sum of distances from a node to all other nodes
 We root the tree arbitrarily. Let's say that node 1 is the root.
 Calculate the score for node 1.
 
 
 
 score[ith child] = score[parent] - + size[root] - 2 * size[ith child]
 We need to calculate the size of each subtree. We would calculate the score for the root node as a
 
 
 
 */
 
 
 
vector<vector<int>> G;
vector<int> treeSize;
vector<lli> score;
 
 
void dfs(int u, int par, int depth = 0){
    
    
    score[1] += depth;
    
    for (int v: G[u]){
        if (v != par){
            dfs(v,u, depth + 1);
            treeSize[u] += treeSize[v];
        }
    }
}
 
 
 
void dfs2(int u, int par){
    
    if (par != -1){
        score[u] = score[par] + treeSize[1] - (2 * treeSize[u]);
    }
    
    for (int v: G[u])
        if (v != par)
            dfs2(v,u);
}
 
 
 
int main() {
    cin >> n;
    
    G.resize(n+1);
    treeSize.resize(n+1,1);
    score.resize(n+1);
    
    for (int i = 0; i < n - 1; i++){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    dfs(1,-1);
    
    dfs2(1,-1);
    
    
    for (int i = 1; i <= n; i++){
        cout << score[i] << " ";
    }
    
 
 
}