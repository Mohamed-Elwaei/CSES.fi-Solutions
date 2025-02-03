#include <vector>
#include <queue>
#include <iostream>
 
 
using namespace std;
#define lli long long int
 
struct node{
    int val;
    node* next;
};
 
 
 
 
 
int main()
{
    int n; cin >> n;
    queue<int> Q;
    
    for (int i = 1; i <= n; i++){
        Q.push(i);
    }
    bool turn = 0;
    while (Q.size()){
        if (turn){
            cout << Q.front() << " ";
            Q.pop();
        }
        else{
            Q.push(Q.front());
            Q.pop();
        }
        turn ^= 1;
    }
}
