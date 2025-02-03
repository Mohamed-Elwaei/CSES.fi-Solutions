#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define lli  long long int
int n;
 
void print(int a, int b){
    while (a <= n) {
        cout << a << " ";
        a += 2;
    }
    while (b <= n) {
        cout << b << " ";
        b += 2;
    }
}
 
 
 
 
int main(){
     cin >> n;
    
    
    //Only case it would not work is n==2 or n == 3;
    
    
    int even = n - (n%2), odd = n - (n+1) % 2;
    
    if (abs(even - 1) > 1 || n == 1)
        print(2,1);
    else if (abs(odd - 2) > 1)
        print(1,2);
    else
        cout << "NO SOLUTION";
    return 0;
    
}
