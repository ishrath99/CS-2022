#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'prims' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER start
 */

int prims(int n, vector<vector<int>> edges, int start) {
    int total_weight = 0;
    
    vector <int> min_weights(n);
    for (int i = 0; i< n; i++){
        min_weights[i] = 100000;
    }
    
    vector <bool> MST(n);
    for (int i = 0; i< n; i++){
        MST[i] = false;
    }
    
    min_weights[start-1] = 0;
    
    for (int i = 0; i< n - 1; i++){
        int weight = 100000;
        int index;
        for (int j=0; j<n; j++){
            if (MST[j] == false && min_weights[j] < weight){
                weight = min_weights[j];
                index = j;
            }
        }
        MST[index] = true;
        for(long unsigned int k=0; k < edges.size(); k++){
            
            int u = edges[k][0];
            int v = edges[k][1];
            int w = edges[k][2];
            
            if(u == index + 1 && MST[v - 1]==false && min_weights[v - 1] > w){
                min_weights[v - 1] = w;
            }
            else if(v == index + 1 && MST[u - 1]==false && min_weights[u - 1] > w){
                min_weights[u - 1] = w;
            }            
        }
    }
    
    for (int i=0; i < n ; i++){
        total_weight += min_weights[i];
    }
    return total_weight;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> edges(m);

    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    string start_temp;
    getline(cin, start_temp);

    int start = stoi(ltrim(rtrim(start_temp)));

    int result = prims(n, edges, start);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
