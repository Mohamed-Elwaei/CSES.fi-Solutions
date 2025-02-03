#include <cmath>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <tuple>
 
using namespace std;
#define lli long long int
int n,m;
 
vector<vector<int>> GF,GR;
/*
 3 5
 + 1 + 2
 - 1 + 3
 + 4 - 2
 
 + 1 + 2
 
 - 1 => + 2
 - 2 => + 1
 
 */
 
vector<int> order;
vector<bool> vis;
vector<int> comps;
int color = 0;
 
void dfs1(int u){
    vis[u] = 1;
    
    for (int v: GF[u]){
        if (!vis[v])
            dfs1(v);
    }
    
    
    order.push_back(u);
}
 
 
void dfs2(int u){
    comps[u] = color;
    vis[u] = 1;
    
    for (int v: GR[u]){
        if (!vis[v])
            dfs2(v);
    }
    
    return;
}
 
 
 
 
 
 
 
 
int main() {
    cin >> n >> m;
    
    GF.resize(m*2); GR.resize(m*2);
    
    for (int i = 0; i < n ; i++){
        int t1,t2;
        char s1,s2;
        
        cin >> s1 >> t1 >> s2 >> t2;
        t1--;t2--;
        
        if (s1 == '+') t1 += m;
        if (s2 == '+') t2 += m;
        
        for(int i = 1; i <= 2; i++){
        if (t1 >= m){
            GF[t1 - m].push_back(t2);
            GR[t2].push_back(t1 - m);
        }
        else{
            GF[t1 + m].push_back(t2);
            GR[t2].push_back(t1 + m);
        }
            swap(t1,t2);
        }
    }
    
    vis.resize(m*2);
    
    for (int i = 0; i < m*2; i++){
        if (!vis[i]){
            dfs1(i);
        }
    }
    reverse(order.begin(), order.end());
    
    
    vis.assign(m*2, false);
    comps.resize(m*2);
    for (int u: order){
        if (!vis[u]){
            color++;
            dfs2(u);
        }
    }
    
    vector<bool> assignments(m);
    
    for (int i = 0; i < m; i++){
        if (comps[i] == comps[i+m]){
            cout << "IMPOSSIBLE";
            return 0;
        }
        assignments[i] = comps[i] < comps[i+m];
    }
    
    
    for (bool a : assignments)
        cout << (a ? "+":"-") << " ";
    return 0;
}
