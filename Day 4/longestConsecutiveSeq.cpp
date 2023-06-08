class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        unordered_set<int> st;
        for(auto i : nums)
            st.insert(i);
        int ans = 1;
        for(auto i : st){
            if(st.find(i-1) == st.end()){
                int x = i, cnt = 0;
                while(st.find(x) != st.end())
                    x++, cnt++;
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
