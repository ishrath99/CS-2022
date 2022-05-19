#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s) {
    int len = s.length();
    int odds = len;
    
    for (int i=0; i < len; i++){
        if (s[i] != '0'){
            for (int j=i+1; j < len; j++){
                if (s[i] == s[j]){
                    s[i] = s[j] = '0';
                    odds -= 2;
                    break;
                }
            }
        }              
    }
    cout << s;
    
    
    if (odds > 1){
       return "NO";
    }
        
    return "YES";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
