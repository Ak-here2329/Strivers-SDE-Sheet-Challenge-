#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    vector<long> pre(n), suf(n);
    pre[0] = arr[0], suf[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--)
        suf[i] = max(suf[i+1], arr[i]);
    
    long ans = 0;
    for(int i=0; i<n; i++){
        if(i != 0)
            pre[i] = max(pre[i-1], arr[i]);
        
        ans += min(pre[i], suf[i]) - arr[i];
    }
    return ans;
}
