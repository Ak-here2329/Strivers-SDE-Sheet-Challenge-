#include <bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int count = 0, n = start.size();
    vector<vector<int>> acti;
    for(int i=0; i<n; i++)
        acti.push_back({start[i], finish[i]});
    
    sort(acti.begin(), acti.end(), [](const vector<int> &a, const vector<int> &b){
        if(a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    });

    int prev = -1;

    for(int i=0; i<n; i++){
        if(prev <= acti[i][0]){
            count++;
            prev = acti[i][1];
        }
    }
    return count;
}
