#include <limits.h>
int ninjaAndLadoos(vector<int> &a, vector<int> &b, int n1, int n2, int k) {
    // Write your code here.
    int s = max(0, k - n2), e = min(k, n1);
	// int n1 = a.size(), n2 = b.size();
	while (s <= e){
		int cut1 = s + (e - s) / 2;
		int cut2 = k - cut1;
		
		int left1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
		int left2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];

		int right1 = cut1 == n1 ? INT_MAX : a[cut1];
		int right2 = cut2 == n2 ? INT_MAX : b[cut2];

		if(left1 <= right2 && left2 <= right1)
			return max(left1, left2);
		else if(left1 > right2)
			e = cut1 - 1;
		else
			s = cut1 + 1;		
	}
	return -1;
}
