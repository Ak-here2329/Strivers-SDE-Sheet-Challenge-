#include <bits/stdc++.h>

int findMajorityElement(int nums[], int n) {
	// Write your code here.

    	int major = nums[0], count = 1;
        for(int i=1; i<n; i++){
            if(count == 0){
                major = nums[i];
                count++;
            }else if (nums[i] == major)
                count++;
            else
                count--;
        }
	
	count = 0;
	for(int i=0; i<n; i++)
		if(nums[i] == major)
			count++;
	
	return count > n / 2 ? major : -1;

}
