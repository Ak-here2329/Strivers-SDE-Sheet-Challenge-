#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int denom[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int i = 8;
    int coins = 0;
    while(i >= 0 && amount){
        coins += amount / denom[i];
        amount %= denom[i];
        i--;
    }
    return coins;
}
