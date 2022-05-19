#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int a;
    int b;
    cin >> a;
    cin >> b;
    int sum = a+b;
    int diff = a-b;
    int mult = a*b;
    cout << sum << '\n';
    cout << diff<< '\n';
    cout << mult;
    return 0;
}
