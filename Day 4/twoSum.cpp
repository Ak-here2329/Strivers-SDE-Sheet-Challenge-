class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(mp.count(diff)){
                ans = {mp[diff], i};
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};
