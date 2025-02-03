#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bit>
 
 
using namespace std;
#define lli  long long int
 
 
set<string> permutations;
 
int n;
string s,perm = "";
map<char, int> counter;
 
 
 
 
void dfs(){
    if (perm.size() == n){
        permutations.insert(perm);
        return;
    }
    
    for (auto& letter: counter){
        if (letter.second > 0){
            counter[letter.first] -= 1;
            perm += letter.first;
            dfs();
            perm.pop_back();
            counter[letter.first] += 1;
        }
    }
}
 
int main(){
    cin >> s;
    n = (int) s.length();
    
    for (char c: s)
        counter[c]++;
    
    dfs();
    
    cout << permutations.size() << "\n";
    
    for (auto perm: permutations)
        cout << perm << "\n";
    
    return 0;
    
    
    
}