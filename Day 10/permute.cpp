class Solution {
public:
    
    void helper(vector<int> &a, vector<vector<int>> &ans, int begin){
        if(a.size() <= begin){
            ans.push_back(a);
            return;
        }
        
        for(int i=begin; i<a.size(); i++){
            swap(a[begin], a[i]);
            helper(a, ans, begin+1);
            swap(a[begin], a[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, ans, 0);
        return ans;
    }
};
