#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#define lli long long int
 
 
using namespace std;
int n, q;
 
 
/*
 
 Brute Force: O(n^2)
  Root the tree n times, and do a dfs to find out the sum of distances to all nodes from the root.
 
 
 Intuition:
    As we move through the tree we get closer to certain nodes, and farther from certain nodes.
    If we choose the ith node, we get closer to all of the nodes rooted at the ith node, and further from all other nodes.
    We can keep track of how many nodes we are closer to and farther from and update the score accordingly.
 
 
 Optimal:
 Let score be the sum of distances from a node to all other nodes
 We root the tree arbitrarily. Let's say that node 1 is the root.
 Calculate the score for node 1.
 
 
 
 score[ith child] = score[parent] - + size[root] - 2 * size[ith child]
 We need to calculate the size of each subtree. We would calculate the score for the root node as a
 
 
 
 */
 
#define max_n 300000
int T[32][max_n];
 
 
int main() {
    cin >> n >> q;
    
    for (int i = 2; i <= n; i++){
        int a; cin >> a;
        T[0][i] = a;
    }
    
    for (int i = 1; i < 32; i++){
        for (int j = 1; j <= n; j++){
            T[i][j] = T[i-1][T[i-1][j]];
        }
    }
    
    
    for (int i = 0; i < q; i++){
        int x,k; cin >> x >> k;
        
        for (int j = 0; j < 32 && x != 0; j++){
            if ((1 << j) & k)
                x = T[j][x];
        }
        if (x == 0)
            x = -1;
        cout << x << "\n";
    }
}