#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// int stepPerms(int n) {
//     if (n == 1){
//         return 1%10000000007;
//     }
//     if (n == 2){
//         return 2%10000000007;
//     }
//     if (n == 3){
//         return 4%10000000007;
//     }
//     else{
//         return (stepPerms(n-1)+stepPerms(n-2)+stepPerms(n-3))%10000000007;
//     }
    
// }

int stepPerms(int num) {
    
    if(num == 1) { //Declaring base cases
        return 1;
    }
    if(num == 2) { //Declaring base cases
        return 2;
    }
                 
    if(num == 3) { //Declaring base cases
        return 4;
    }
    
    int base1 = 1;
    int base2 = 2;
    int base3 = 4;  
    int result = 0;
    
    for(int i=4; i<=num; i++){
        // accumulate the steps to the result and shift bases
        result = (base1 + base2 + base3)%10000000007;
        base1 = base2;
        base2 = base3;
        base3 = result;
    }
    return result;
}

int main()
{
    int s;
    cin >> s;
    for (int i = 0; i < s; i++) {
        int n;
        cin >> n;
        cout << stepPerms(n) << endl;
    }
    return 0;
}