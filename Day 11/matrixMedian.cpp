int lessThanEqual(vector<int> &nums, int x){
    int s = 0, e = nums.size() - 1;
    
    while(s <= e){
        int mid = s + (e - s) / 2;
        if(nums[mid] <= x)
            s = mid + 1;
        else   
            e = mid - 1;
    }
    return s;
}


int Solution::findMedian(vector<vector<int> > &A) {
    
    int s = INT_MAX, e = INT_MIN;
    int m = A.size(), n = A[0].size();
    for(int i=0; i<m; i++){
        s = min(s, A[i][0]);
        e = max(e, A[i][n-1]);
    }
    
    while(s <= e){
        int mid = s + (e - s) / 2;
        int cnt = 0;
        for(int i=0; i<m; i++)
            cnt += lessThanEqual(A[i], mid);
        if(cnt <= (m * n) / 2)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return s;
}
