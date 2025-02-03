#include <vector>
#include <queue>
#include <iostream>
 
 
using namespace std;
#define lli long long int
 
 
/*
 5 3
 2 4 7 3 5
 2 6 13 16 21
 
 At k = 2
 2 4 7    3 5
 2 6 13   3 8
 
 
 At k = 2
 2 4  7   3 5
 
 Use a priority Queue to store the maximum sum subarray to split it at the next iteration.
 
 Each entry in the Priority Queue will store an integer, and a pair.
 Integer is the sum of the subarray, and pair the start and the end indices of that subarray;
 */
 
 
//Input is a vector which is a prefix sum.
lli max_sum = 1e19;
 
bool is_possible(vector<lli>& V, lli max_sum , const int k){
    lli curr_sum = 0;
    lli sub_count = 0;
    for (auto& x: V){
        if (x > max_sum)
            return false;
        if (curr_sum + x > max_sum){
            curr_sum = 0;
            sub_count++;
        }
        curr_sum += x;
        
    }
    if (curr_sum > 0) sub_count++;
    
    return sub_count <= k;
}
 
 
 
int main()
{
    
    int n,k; cin >> n >> k;
    
    vector<lli> V(n);
    for (int i = 0; i < n; i++) cin >> V[i];
    
    lli l = 1, r = max_sum;
    while (l <= r) {
        lli mid = (r - l) / 2 + l;
 
        
        if (is_possible(V, mid, k)){
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
    cout << l;
    return 0;
    
}