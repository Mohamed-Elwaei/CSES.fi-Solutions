#include <vector>
#include <map>
#include <iostream>
#include <set>
 
 
using namespace std;
#define lli long long int
 
/*
 8 15
 3 2 5 8 1 3 2 3
 
 1 2 2 3 3 3 5 8
 
 
 Compute all possible sums of two in this array.
 Map each "two sum" to an array of pairs, where each pair is the index of the two numbers. Store the Map in a variable mp.
 
 Go over all the two sums in the array, do a binary search on the map to see if there is another two sum that sums up to target. If there is, make sure that the indices do not overlap, i.e four different indices
 */
 
 
 
int main()
{
    lli n,t; cin >> n >> t;
    
    vector <lli> V(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    
    
    map<lli, vector<pair<lli,lli>>> MP;
    for (lli i = 0; i < n; i++){
        for (lli j = i + 1; j < n; j++){
            MP[V[i] + V[j]].push_back(make_pair(i, j));
        }
    }
    
    for (lli i = 0; i < n; i++){
        for (lli j = i + 1; j < n; j++){
            lli d = t - (V[i] + V[j]);
            auto it = MP.lower_bound(d);
            if (it == MP.end() || (*it).first != d)
                continue;
            
            set<lli> S;
            S.insert(i); S.insert(j);
            
            for (auto& p : (*it).second)
                if (S.find(p.first) == S.end() && S.find(p.second) == S.end()) {
                    cout << i + 1 << " " << j + 1 << " " << p.first + 1 << " " << p.second + 1;
                    return 0;
                }
            
            
        }
    }
    cout << "IMPOSSIBLE";
}