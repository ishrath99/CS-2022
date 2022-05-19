#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int calc_a_i_plus_one(int a_i, int b_i){
    return (((a_i*a_i + 2*b_i + 1)%10007) + 10007)%10007 - 5000;
}

int calc_b_i_plus_one(int a_i, int b_i){
    return (((b_i*b_i + 2*a_i - 1)%10007) + 10007)%10007 - 5000;
}

int calc_c_i_plus_one(int a_i, int b_i, int c_i){
    return (((a_i + b_i + c_i)%121) + 121)%121 - 60;
}

int calc_s_i(int a_i, int b_i, int c_i){
    return a_i + b_i + c_i;
}

void calc_max_profit(int machines[], int N, int cursor, int common_sum_max, int not_common_sum_max){
    
    if (cursor == N){
        cout << std::max({common_sum_max, not_common_sum_max});
        return;
    }
    
    not_common_sum_max = std::max({common_sum_max, not_common_sum_max});
    common_sum_max = std::max({common_sum_max + machines[cursor], machines[cursor]});

    calc_max_profit(machines, N, cursor + 1, common_sum_max, not_common_sum_max);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N;
    int y;
    int d;
    int m;
    cin >> N;
    cin >> y;
    cin >> m;
    cin >> d;
    int a_i = y;
    int b_i = m;
    int c_i = d;  
    
    int machines[N];
    for (int i = 0; i < N; i++){
        
        machines[i] = calc_s_i(a_i, b_i, c_i);
        int copy_a_i = a_i;
        int copy_b_i = b_i;
        int copy_c_i = c_i;
        a_i = calc_a_i_plus_one(copy_a_i, copy_b_i);
        b_i = calc_b_i_plus_one(copy_a_i, copy_b_i);
        c_i = calc_c_i_plus_one(copy_a_i, copy_b_i, copy_c_i);
    }
    
    // for (int i = 0; i < N; i++){
    //     cout << machines[i] << ' ' ;
    // }
    // cout << '\n';
    
    if (N == 1){
        cout << machines[0];
    }
    if (N > 1){
        int common_sum_max = std::max({machines[1], machines[0] + machines[1]});
        int not_common_sum_max = machines[0];
        
        calc_max_profit(machines, N, 2, common_sum_max, not_common_sum_max);
    }
        
    
    return 0;
}


