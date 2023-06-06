class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            vector<int> curr = ans.back();
            if(intervals[i][0] <= curr[1])
                ans[ans.size()-1] = {min(curr[0], intervals[i][0]), max(curr[1], intervals[i][1])};
            else
                ans.push_back(intervals[i]);        
        }

        return ans;
    }
};
