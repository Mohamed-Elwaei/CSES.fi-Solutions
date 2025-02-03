#include <iostream>
#include <vector>
#include <map>
#include <bit>
 
using namespace std;
#define lli  long long int
 
 
 
/*
 Example
 Input:
 
 AAAACACBA
 Output:
 
 AACABACAA
 
 A: 6, C: 2, B: 1.
 
 B has to be in the middle.
 
 [C,A,A,A]   B [A,A,A,C]
 
 */
 
 
 
 
int main(){
    std::string s; cin >> s;
    int n = (int) s.length();
    
    
    map<char, int> M;
    
    vector<char> V(n);
    
    for (auto ch: s)
        M[ch]++;
    
    int odd = 0;
    for (auto &p: M){
        odd += (p.second & 1);
    }
    
    if ((n % 2 == 0 && odd > 0) || (n % 2 == 1 && odd != 1)){
        cout << "NO SOLUTION";
        return 0;
    }
    
    
    if (n % 2 == 1){
        
        char middle;
        for (auto p : M)
            if (p.second % 2 == 1)
                middle = p.first;
        
        int x = M[middle]/2;
        for (int i = n/2 - x ; i <= n/2 + x; i++){
            V[i] = middle;
            M[middle]--;
        }
    }
    
    
    int l = 0, r = n - 1;
    
    
    for (auto &p : M){
        char ch = p.first;
        
        while (M[ch]) {
            V[l] = V[r] = ch;
            l++;r--;
            M[ch]-=2;
        }
    }
    
    for (char ch: V)
        cout << ch;
    
    return 0;
    
    
    
    
}