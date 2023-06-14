#include <bits/stdc++.h>
string kthPermutation(int n, int k) {
    // Write your code here.\

    vector<int> nums;
    int fact = 1;
    for(int i=1; i<n; i++){
        nums.push_back(i);
        fact *= i;
    }
    nums.push_back(n);
    string ans = "";
    k--;
    while(1){
        ans += to_string(nums[k/fact]);
        nums.erase(nums.begin() + k / fact);
        if(nums.size() == 0)
            break;
        k %= fact;
        fact /= nums.size();
    }

    return ans;
}
