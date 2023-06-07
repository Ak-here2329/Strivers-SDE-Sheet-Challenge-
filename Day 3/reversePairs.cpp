class Solution {
public:

    int mergeSorted(vector<int> &nums, int l, int mid, int r){
        int i = l, j = mid + 1, p = mid + 1, k = 0, ans = 0;
        int merge[r-l+1];
        
        while(i <= mid){
            while(p <= r && nums[i] > (2l * nums[p]))
                p++;
            ans += (p - mid - 1);
            
            while(j <= r and nums[i] >= nums[j])
                merge[k++] = nums[j++];
            merge[k++] = nums[i++];
        }
        
        while(j <= r)
            merge[k++] = nums[j++];
        
        k = 0, i = l;
        while(i <= r)
            nums[i++] = merge[k++];
        
        return ans;
    }

    int mergeSort(vector<int> &nums, int l, int r){
        if(l >= r)
            return 0;
        
        int mid = l + (r - l) / 2;
        
        return mergeSort(nums, l, mid) + mergeSort(nums, mid+1, r) + mergeSorted(nums, l, mid, r);
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
