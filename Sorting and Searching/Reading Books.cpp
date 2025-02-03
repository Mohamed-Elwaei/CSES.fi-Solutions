#include <vector>
#include <queue>
#include <iostream>
 
 
 
using namespace std;
#define lli long long int
 
 
 
 
 
int main()
{
    /*
     One reads books from shortest to longest, other reads them from longest to shortest.
     minimum answer is sum of all the books.
     */
    
    lli n, sum = 0; cin >> n;
    
    vector<lli> V(n);
    lli ma = -1;
    for (int i = 0; i < n; i++){
        cin >> V[i];
        sum += V[i];
        ma = max(ma, V[i]);
    }
    
    cout <<( ma > (sum - ma) ? 2 * ma : sum) ;
    
 
    
     
}