/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int, int> mp;
        int ans = 0, sum = 0;
        for(int i=0; i<n; i++){
            sum += A[i];
            if(sum == 0)
                ans = max(ans, i + 1);
            if(mp.count(sum))
                ans = max(ans, i - mp[sum]);
            
            if(!mp.count(sum))
                mp[sum] = i;
        }
    
        return ans;
    }
};
