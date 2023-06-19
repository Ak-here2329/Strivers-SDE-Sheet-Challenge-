class Solution {
public:
    void helper(string &s, int idx, string curr, unordered_set<string> &st, vector<string> &res){
        if(idx >= s.size()){
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        
        string word = "";

        for(int i=idx; i<s.size(); i++){
            word.push_back(s[i]);
            if(st.count(word)){
                helper(s, i + 1, curr + word + " ", st, res);
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        vector<string> res;
        for(auto word : wordDict)
            st.insert(word);
        string curr = "";
        
        helper(s, 0, curr, st, res);    
        return res;
    }
};
