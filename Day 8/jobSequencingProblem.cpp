#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(), jobs.end(), [](const vector<int> &a, const vector<int> &b){
        if(a[1] == b[1])
            return a[0] < b[0];
        return a[1] > b[1];
    });

    int ans = 0, sz = 0;
    for(int i=0; i<jobs.size(); i++)
        sz = max(sz, jobs[i][0]);
    
    vector<int> dates(sz + 1, -1);

    for(int i=0; i<jobs.size(); i++){
        int j = jobs[i][0];
        while(j > 0 && dates[j] != -1)
            j--;
        if(j > 0){
            ans += jobs[i][1];
            dates[j] = i;
        }
    }
    return ans;
}
