class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            
            long long tar1 = target - nums[i];
            
            for(int j=i+1; j<n; j++){
                
                long long tar2 = tar1 - nums[j];
                int front = j+1, back = n-1;
                
                while(front < back){
                    
                    int sum = nums[front] + nums[back];
                    if (sum == tar2){
                        vector<int> squad = {nums[i], nums[j], nums[front], nums[back]};
                        ans.push_back(squad);
                        //remove dups
                        while(front < back and nums[front] == squad[2])
                            front++;
                        while(front < back and nums[back] == squad[3])
                            back--;
                    }else if (sum < tar2)
                        front++;
                    else
                        back--;
                    
                }
                
                while(j+1 < n and nums[j+1] == nums[j])
                    j++;
            }
            while(i+1 < n and nums[i+1] == nums[i])
                i++;
        }
        return ans;
    }
};
