#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
#define lli long long int
 
int n, m, k;
vector<vector<int>> adj; // Adjacency list
vector<vector<int>> capacity; // Capacity matrix
vector<int> parent;
const int INF = 2e9;
 
int s, t;
 
bool bfs() {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
 
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
 
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return true;
                q.push({next, new_flow});
            }
        }
    }
    return false;
}
 
int main() {
    cin >> n >> m >> k;
    s = 0; t = n + m + 1;
    adj.resize(n + m + 2);
    capacity.assign(n + m + 2, vector<int>(n + m + 2, 0));
    parent.resize(n + m + 2);
 
    for (int i = 0; i < k; i++) {
        int girl, boy;
        cin >> girl >> boy;
        boy += n; // Adjust boy index to avoid conflict with girl index
        adj[girl].push_back(boy);
        adj[boy].push_back(girl);
        capacity[girl][boy] = 1;
    }
 
    for (int girl = 1; girl <= n; girl++) {
        adj[s].push_back(girl);
        adj[girl].push_back(s);
        capacity[s][girl] = 1;
    }
 
    for (int boy = n + 1; boy <= n + m; boy++) {
        adj[boy].push_back(t);
        adj[t].push_back(boy);
        capacity[boy][t] = 1;
    }
 
    int flow = 0;
 
    while (bfs()) {
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur]--;
            capacity[cur][prev]++;
            cur = prev;
        }
        flow++;
    }
 
    cout << flow << "\n";
 
    vector<pair<int, int>> matches;
    for (int girl = 1; girl <= n; girl++) {
        for (int boy : adj[girl]) {
            if (capacity[girl][boy] == 0 && boy > n) {
                matches.push_back({girl, boy - n});
                break;
            }
        }
    }
 
    for (auto [girl, boy] : matches) {
        cout << girl << " " << boy << "\n";
    }
 
    return 0;
}