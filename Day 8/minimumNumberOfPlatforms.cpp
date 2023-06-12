int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at, at + n);
    sort(dt, dt + n);

    int i = 1, j = 0, ans = 1, curr = 1;
    
    while(i < n){
        if(at[i] <= dt[j])
            curr++, i++;
        else
            curr--, j++;
        ans = max(ans, curr);        
    }

    return ans;
}
