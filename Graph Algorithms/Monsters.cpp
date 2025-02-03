#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
using namespace std;
 
 
 
 
/*
 We need to calculate for each cell the minimum required steps for a monster to reach that cell. USE BFS
 
 
 If our hero can reach that cell in a smaller amount of time, then it is possible. Otherwise no. USE DFS
 
 */
#define INF 1e9
 
 
pair<int,int> start;
int n,m;
 
 
 
int G[1000][1000];
 
vector<tuple<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
 
 
 
 
 
 
 
 
 
 
vector<char> path;
set<pair<int,int>> visited;
 
 
vector<tuple<int,int,char>> directions2 = {{1,0,'D'},{-1,0,'U'},{0,1,'R'},{0,-1,'L'}};
 
 
 
 
int dfs(int r, int c, int steps){
    if (steps >= G[r][c])
        return false;
    
    if (r == 0 || r == n-1 || c == 0 || c == m - 1){
        return true;
    }
    
 
    
    visited.insert({r,c});
    
    for (auto& d: directions2){
        int nr,nc,dir;
        tie(nr,nc,dir) = d;
        nr+=r;nc+=c;
        
        path.push_back(dir);
        if (visited.find({nr,nc}) == visited.end() && dfs(nr,nc,steps+1))
            return true;
        path.pop_back();
        
    }
    
    visited.erase({r,c});
    return false;
}
 
 
 
int main(){
    
    cin >> n >> m;
    queue<tuple<int,int,int>> Q;
    
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char x; cin >> x;
            
            G[i][j] = INF;
            switch (x) {
                case 'M':
                    Q.push({i,j,0});
                    G[i][j] = 0;
                    break;
                
                case 'A':
                    start = {i,j};
                    break;
                case '#':
                    G[i][j] = -1;
                    break;
                    
                default:
                    break;
            }
            
        }
    }
    
    while (Q.size()) {
        int r,c,steps;
        tie(r,c,steps) = Q.front();
        Q.pop();
        
        
        for (auto dir: directions){
            int nr, nc;
            tie(nr,nc) = dir; nr += r; nc += c;
            
            if (0 <= nr && nr < n && 0 <= nc && nc < m && G[nr][nc] == INF){
                G[nr][nc] = 1 + steps;
                Q.push({nr,nc,steps + 1});
            }
        }
    }
    
    
    if (!dfs(start.first, start.second, 0)){
        cout << "NO";
        return 0;
    }
    
    cout << "YES\n" << path.size() << "\n";
    for (auto &x : path)
        cout << x;
    
    return 0;
}