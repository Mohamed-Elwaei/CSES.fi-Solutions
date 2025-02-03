#include <stack>
#include <iostream>
 
 
using namespace std;
#define lli long long int
/*
 Use a monotinacally increasing stack. Top of stack will have index, and num
 */
 
int main()
{
    int n;
    cin >> n;
    
    stack<pair<int,int>> S; //Index, And number;
    
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        while (!S.empty() && S.top().second >= x)
            S.pop();
        
        cout << ((S.empty()) ? 0 : S.top().first) << " ";
        S.push(make_pair(i, x));
        
    }
}