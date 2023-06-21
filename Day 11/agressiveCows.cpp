#include <bits/stdc++.h> 

bool possible(vector<int> &pos, int c, int space){
	int prev = pos[0], cnt = 1;
	for(int i=1; i<pos.size(); i++){
		if(pos[i] - prev >= space){
			prev = pos[i];
			cnt++;
		}
	}
	return cnt >= c;
}


int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(), positions.end());
	int s = 1, e = *max_element(positions.begin(), positions.end()), ans = -1;

	while(s <= e){
		int mid = s + (e - s) / 2;
		if(possible(positions, c, mid)){
			ans = mid;
			s = mid + 1;
		}else 
			e = mid - 1;
	}

	return ans;
}
