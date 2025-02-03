#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
 
using namespace std;
int n;
 
/*
 
 For each node store two values: the maximum length to a leaf node, and the second largest length to a leaf node.
 
 Then for each node, calculate the path if that node was the highest point.
 That path will be the maximum length of one of the children + the maximum length of one of the parents, in a different direction that the root.
 */
 
struct path{
    int length;
    int next;
    
    path(int l=0, int n=0){length = l; next = n;};
};
 
 
vector<vector<int>> G;
vector<pair<path,path>> toLeaf, maxLength;
 
 
 
 
vector<int> ans;
 
 
void dfs(int u, int par){
    path a,b;
    a = {0,0}; b = {0,0};
    
    
    for (int v: G[u]){
        if (v == par) continue;
        dfs(v,u);
        path tmp(toLeaf[v].first.length + 1, v);
        
        if (tmp.length > b.length)
            b = tmp;
        if (b.length > a.length)
            swap(a,b);
    }
    
    toLeaf[u] = {a,b};
}
 
 
 
void dfs2(int u, int par){
    maxLength[u] = toLeaf[u];
    
    
    if (par != -1){
        path parentPath = maxLength[par].first;
        if (parentPath.next == u)
            parentPath = maxLength[par].second;
        
        parentPath.length++;
        if (parentPath.length > maxLength[u].first.length)
            maxLength[u] = {parentPath, maxLength[u].first};
        else if (parentPath.length > maxLength[u].second.length)
            maxLength[u] = {maxLength[u].first, parentPath};
    }
    
    for (int v: G[u])
        if (v != par)
            dfs2(v, u);
    
}
 
 
 
 
 
 
int main() {
    cin >> n;
    G.resize(n+1);
    toLeaf.resize(n+1);
    maxLength.resize(n+1);
    
    for (int i = 0; i < n - 1; i++){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
 
 
    dfs(1,-1);
 
    dfs2(1,-1);
    
    
    for (int i = 1; i <= n; i++)
        cout << maxLength[i].first.length << " ";
 
}
