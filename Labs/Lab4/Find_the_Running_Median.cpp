#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

vector<double> runningMedian(vector<int> a) {
    int N = a.size();
    vector<double> median(N);
    
    for (int i = 0; i < N; i++) {
        int val = a[i];
        if (i%2 == 0){
            for (int j = 0; j < i+1; j++){
                int temp = a[j];
                if (val <= a[j]){
                    a[j] = val;
                    a[j+1] = temp;
                    break;
                }
            } 
            int val = a[i/2];
            double var = 1.0*val;
            cout << var << '\n';
            median[i] = var;
            
        }
        
        
        else{
            for (int j = 0; j < i+1; j++){
                int temp = a[j];
                if (val <= a[j]){
                    a[j] = val;
                    a[j+1] = temp;
                    break;
                }  
            }
            cout << 0.5*(double)(a[i/2] + a[i/2 + 1]) << '\n';
            median[i] = 0.5*(double)(a[i/2] + a[i/2 + 1]);
        }

    }
    return median;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);
    
    int x = 15;
    double v = 1.0*x;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << v << '\n';

    for (size_t i = 0; i < result.size(); i++) {
        std::cout << std::fixed;
        std::cout << std::setprecision(1);
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
