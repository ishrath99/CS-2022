#include <bits/stdc++.h>

using namespace std;


int stepPerms(int n) {
    if (n == 1){
        return 1%10000000007;
    }
    if (n == 2){
        return 2%10000000007;
    }
    if (n == 3){
        return 4%10000000007;
    }
    else{
        return (stepPerms(n-1)+stepPerms(n-2)+stepPerms(n-3))%10000000007;
    }
    
    

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