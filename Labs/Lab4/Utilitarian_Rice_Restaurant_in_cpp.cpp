#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> customers(n);
    for (int i = 0; i < n; ++i) {
        cin >> customers[i].first;   //arrival time
        cin >> customers[i].second;  //cooking time        
    }
    
    sort(customers.begin(), customers.end());  //first came -> first index
    
    int totalWaitingTime = 0;
    set<pair<int, int>> queue; //priority queue (lowest cooking time first)   [[cooking time, index]]
    
    int time = customers[0].first;  //current time
    int i = 0;
    
    while (i < n || queue.size()) {
        while (i < n && customers[i].first <= time) {
            queue.insert(pair<int, int>(customers[i].second, i));
            ++i;
        }
        
        if (queue.empty()) {   //this happens if arrival time of 1st sutomer = 0
            time = customers[i].first;
        } else {
            int index = queue.begin()->second;
            queue.erase(queue.begin());
            
            time += customers[index].second;
            totalWaitingTime += time - customers[index].first;
        }
    }
    
    cout << totalWaitingTime / n << endl;
    
    return 0;
}