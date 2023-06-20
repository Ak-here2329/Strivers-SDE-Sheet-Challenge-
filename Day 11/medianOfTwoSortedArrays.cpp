double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	int s = 0, e = a.size();
	int n1 = a.size(), n2 = b.size();
	while (s <= e){
		int cut1 = s + (e - s) / 2;
		int cut2 = (n1 + n2 + 1) / 2 - cut1;
		
		int left1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
		int left2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];

		int right1 = cut1 == n1 ? INT_MAX : a[cut1];
		int right2 = cut2 == n2 ? INT_MAX : b[cut2];

		if(left1 <= right2 && left2 <= right1){
			if((n1 + n2) % 2 == 0)
				return (max(left1, left2) + min(right1, right2)) / 2.0;
			else	
				return max(left1, left2);
		}else if(left1 > right2)
			e = cut1 - 1;
		else
			s = cut1 + 1;		
	}
	return -1;
}
