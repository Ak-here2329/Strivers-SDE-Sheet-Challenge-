#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int n = input.size(), i = 0, j = 0, ans = 1;
    unordered_map<char, int> mp;
    while(j < n){
        mp[input[j]]++;
        if(mp.size() == (j - i + 1))
            ans = max(ans, j - i + 1);
        else{
            while(mp.size() < (j - i + 1)){
                mp[input[i]]--;
                if(mp[input[i]] == 0)
                    mp.erase(input[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        j++;
    }
    return ans;
}
