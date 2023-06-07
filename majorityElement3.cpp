class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0, first = INT_MIN, second = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == first)
                c1++;
            else if(nums[i] == second)
                c2++;
            else if(c1 == 0){
                first = nums[i];
                c1++;
            }else if(c2 == 0){
                second = nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1 = 0, c2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == first)
                c1++;
            else if(nums[i] == second)
                c2++;
        }
        
        vector<int> ans;
        if(c1 > (nums.size() / 3))
            ans.push_back(first);
        if(c2 > (nums.size() / 3))
            ans.push_back(second);
        return ans;
        
    }
};
