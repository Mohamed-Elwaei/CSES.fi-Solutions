#include <vector>
#include <iostream>
 
 
using namespace std;
#define lli long long int
/*
 Use a monotinacally increasing stack. Top of stack will have index, and num
 */
 
int main()
{
    int n, x; cin >> n >> x;
    vector<int> V(n);
    
    for (int i = 0; i < n; i++)
        cin >> V[i];
    
    int l = 0;
    lli sum = 0;
    int ans = 0;
    for (int r = 0; r < n; r++){
        sum += V[r];
        while (sum > x ){
            sum -=  V[l];
            l++;
        }
        if (sum == x) ans++;
    }
    
    cout << ans;
    
}