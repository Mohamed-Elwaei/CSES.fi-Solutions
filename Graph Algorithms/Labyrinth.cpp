#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <tuple>
 
using namespace std;
 
char M[1000][1000];
char steps[1000][1000];
bool vis[1000][1000];
 
pair<int,int> S,E;
 
vector<tuple<int,int,char>> directions = {{1,0,'D'},{-1,0,'U'},{0,1,'R'},{0,-1,'L'}};
 
int main(void){
    int n,m; cin >> n >> m;
    
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> M[i][j];
            if (M[i][j] == 'A')
                S = {i,j};
            else if (M[i][j] == 'B')
                E = {i,j};
            vis[i][j] = 0;
        }
    }
    
    
    
    queue<pair<int,int>> Q;
    
    vis[S.first][S.second] = 1;
    Q.push({S.first, S.second});
    
    
    while (Q.size()){
        int r,c;
        tie(r,c) = Q.front(); Q.pop();
        
        if (make_pair(r, c) == E)
            break;
        
        for (auto& d: directions){
            int dr,dc; char dir;
            tie(dr,dc,dir) = d;
            int nr = r + dr, nc = c + dc;
            
            if (vis[nr][nc] || nr < 0 || nr >= n || nc < 0 || nc >= m || M[nr][nc] == '#')
                continue;
            vis[nr][nc] = 1;
            Q.push({nr,nc});
            steps[nr][nc] = dir;
        }
    }
    
    
    if (vis[E.first][E.second] == 0){
        cout << "NO";
        return 0;
    }
    
    vector<char> P;
    
    while (E != S) {
        int r,c;
        r = E.first; c = E.second;
        P.push_back(steps[r][c]);
        
        
        
        switch (steps[r][c]) {
            case 'U':
                r++;
                break;
            case 'D':
                r--;
                break;
            case 'L':
                c++;
                break;
            case 'R':
                c--;
                break;
        }
        
        E = {r,c};
    }
 
    reverse(P.begin(), P.end());
    
    cout << "YES\n" << P.size() << "\n";
    for (auto c: P)
        cout << c;
    
}
 