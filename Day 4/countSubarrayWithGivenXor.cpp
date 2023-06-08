#include <bits/stdc++.h>

int subarraysXor(vector<int> &A, int B)
{
    //    Write your code here.
   
    unordered_map<int, int> mp;
    int exor = 0, ans = 0;
    mp[0] = 1;
    for(auto i : A){
        exor ^= i;
        if(mp.count(exor ^ B))
            ans += mp[exor ^ B];
        mp[exor]++;
    }
    return ans;
}
