#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
vector<int> link, Size;
 
 
 
int find(int x){
    if (x == link[x])
        return x;
    return (x = find(link[x]));
}
 
 
void U(int a, int b){
    a = find(a);
    b = find(b);
    
    if (a != b){
        if (Size[a] < Size[b])
            swap(a,b);
        
        link[b] = a;
        Size[a] += Size[b];
    }
}
 
 
 
int main(void){
    
    int n,m; cin >> n >> m;
    
    link.resize(n+1); Size.resize(n+1);
    
    for (int i = 1; i <= n; i++){
        link[i] = i;
        Size[i] = 1;
    }
    
    
    for (int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        U(a,b);
    }
    
    set<int> comps;
    
    for (int i = 1; i <= n; i++)
        comps.insert(find(link[i]));
    int k = (int) comps.size() - 1;
    
    
    cout << k << "\n";
    
    for (int i = 1; i <= n; i++){
        int a,b;
        a = find(link[1]);
        b = find(link[i]);
        
        if (a != b){
            cout << a << " " << b << "\n";
            U(a,b);
        }
            
    }
}
