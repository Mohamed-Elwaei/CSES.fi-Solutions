#include <vector>
#include <queue>
#include <iostream>
 
 
 
using namespace std;
#define lli long long int
 
 
 
 
 
int main()
{
    /* Each task decays at the same rate: dy/dx = -1 for all tasks.
     We should try to stop as many tasks as possible from decaying.
     We keep picking tasks with the shortest duration*/
    lli n; cin >> n;
    vector<pair<lli,lli> > V(n);
    
    for (int i = 0; i < n; i++){
        lli a,b;
        cin >> a >> b;
        V[i] = make_pair(a, b);
    }
    sort(V.begin(), V.end());
    
    lli time = 0l;
    lli reward = 0l;
    for (auto& p: V){
        time += p.first;
        reward += p.second - time;
    }
    cout << reward;
     
}
