class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, mid = 0, high = nums.size() - 1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[lo], nums[mid]);
                mid++, lo++;
            }else if(nums[mid] == 1)
                mid++;
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }

    }
};
