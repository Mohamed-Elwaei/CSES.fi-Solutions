#include <iostream>
#include <vector>
#include <bit>
using namespace std;
#define lli  long long int
int n,q;
 
               
               
int main(){
    cin >> n >> q;
    vector<vector<int>> M(n+1,vector<int>(n+1,0));
    char x;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> x;
            M[i][j] =  (x == '*') + M[i-1][j] + M[i][j-1] - M[i-1][j-1];
        }
    }
    
    while (q--){
        int y1,x1,y2,x2; cin >> y1 >> x1 >> y2 >> x2;
        
        cout << M[y2][x2] - M[y1 - 1][x2] - M[y2][x1 - 1] + M[y1 - 1][x1 - 1] << "\n";
    }
    
}