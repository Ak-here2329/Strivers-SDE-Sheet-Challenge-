// #include <bits/stdc++.h> 

// void solve(vector<int> &arr, int idx, vector<int> &curr, set<vector<int>> &ans){
//     if(idx >= arr.size()){
//         // if(curr.size() > 0){
//             sort(curr.begin(), curr.end());
//             ans.insert(curr);
//         // }
//         return;
//     }
//     solve(arr, idx + 1, curr, ans);
//     curr.push_back(arr[idx]);
//     solve(arr, idx + 1, curr, ans);
//     curr.pop_back();
// }

// vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
// {
//     // Write your code here.
//     set<vector<int>> ans;
//     vector<int> curr;
//     solve(arr, 0, curr, ans);
//     return vector<vector<int>>(ans.begin(), ans.end());
// }

#include <bits/stdc++.h> 

void solve(int idx,vector<int>&temp,vector<vector<int>>&ans,vector<int>&arr,int n){

    ans.push_back(temp);

    if(idx>=n)return;

    for(int i=idx;i<n;i++){

        if(i>idx && arr[i]==arr[i-1])continue;

        temp.push_back(arr[i]);

        solve(i+1,temp,ans,arr,n);

        temp.pop_back();

    }

}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)

{

    // Write your code here.

    if(n==0)return{};

    sort(arr.begin(),arr.end());

    vector<int>temp;

    vector<vector<int>>ans;

    solve(0,temp,ans,arr,n);

    return ans;

}
