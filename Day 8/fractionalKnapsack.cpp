#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        double y = (double) b.second / b.first;
        double x = (double) a.second / a.first;
        if(x == y)
            return a.first < b.first;
        return x > y;
    });

    int i = 0;
    double ans = 0;
    while(i < n && w){
        if (items[i].first <= w) {
            ans += items[i].second;
            w -= items[i].first;
        } else {
            double density = (double)items[i].second / items[i].first;
            ans += w * density;
            w = 0;
        }
        i++;
    }
    return ans;
}
