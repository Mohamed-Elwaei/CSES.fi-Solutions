#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define lli  long long int
 
 
 
 
 
 
int main(){
    char last = 'X';
    string s;
    int count = 1;
    int ans = 0;
    
    cin >> s;
    
    for (auto& x: s){
        if (x == last)
            count+=1;
        else
            count = 1;
        last = x;
        ans = max(count, ans);
    }
    
    cout << ans;
}