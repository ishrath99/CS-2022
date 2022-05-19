#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";
        
    bool num = false;
    bool lc = false;
    bool uc = false;
    bool sc = false;
    
    int i = 0;
    while (( num == false || lc == false || uc == false || sc== false) && (i < n) ){
        cout<< i <<'\n';
        if (numbers.find(password[i]) != string::npos){
            num = true;
            i++;
            continue;
        }
        if (lower_case.find(password[i]) != string::npos){
            lc = true;
            i++;
            continue;
        }
        if (upper_case.find(password[i]) != string::npos){
            uc = true;
            i++;
            continue;
        }
        if (special_characters.find(password[i]) != string::npos){
            sc = true;
            i++;
            continue;
        }
        
    }
    
    cout << num ;
    cout << lc ;
    cout << uc ;
    cout << sc<< '\n' ;
        
    
    
    int add = 0;
    if (num == false){
        add++;
    }
    if (lc == false){
        add++;
    }
    if (uc == false){
        add++;
    }
    if (sc == false){
        add++;
    }
    if (n + add < 6){
        add += (6 - add - n);
    }
    
    return add;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
