#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int fibonnaci(int numm){
    if (numm == 1 || numm == 2){
        return 1;
    }
    else{
        return fibonnaci(numm-1) + fibonnaci(numm-2) ;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int num;
    cin >> num;
    int result = fibonnaci(num);
    cout << result;
    return 0;
}


