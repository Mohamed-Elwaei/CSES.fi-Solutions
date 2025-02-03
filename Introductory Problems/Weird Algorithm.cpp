#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define lli  long long int
 
 
lli n;
 
 
 
int main(){
    cin >> n;
    
    while (n != 1)
    {
        cout << n << " ";
        if (n % 2 == 0){
            n /= 2;
        }
        else{
            n = n*3 + 1;
        }
    }
    cout << n;
}