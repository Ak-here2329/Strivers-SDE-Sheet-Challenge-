#include <bits/stdc++.h> 

void solve(vector<int> nums, int idx, vector<int> &ans, int sum){
    if(idx >= nums.size()){
        ans.push_back(sum);
        return;
    }

    solve(nums, idx + 1, ans, sum + nums[idx]);
    solve(nums, idx + 1, ans, sum);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    solve(num, 0, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}
