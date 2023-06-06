#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &A, int N)
{
	// Write your code here 
	long long n = A.size();
    long long s1 = 0, s2 = 0;
    for(auto i : A){
        s1 += (long long)i;
        s2 += ((long long)i * (long long)i);
    }
    long long sn1 = (n *(n + 1)) / 2;
    long long sn2 = (n * (n + 1) * (2 * n + 1)) / 6;
    long long diff = s1 - sn1;
    long long add = (s2 - sn2);
    add /= diff;
    long long a = (add + diff) / 2;
    long long b = (add - a);
    return {b, a};
	
}
