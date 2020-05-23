#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPath = INT_MAX;
    void helper(vector<int> &coins, int amount, int n,int pathCount){
        
        if (amount == 0 && pathCount < minPath){
            minPath = pathCount;
            return;
        }
        for (int i=n-1;i>=0;i--){
            if (amount-coins[i] >= 0){
                helper(coins, amount-coins[i], n, pathCount+1);
            }
        }
    }
    
    
    int dpHelper(vector<int> &coins, int amount, int n){
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for (int i=1;i<=amount;i++){
            for (int j=0;j<coins.size();j++){
                if (coins[j] <= i && dp[i-coins[j]] != amount+1){
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        return (dp[amount] == amount+1) ? -1 : dp[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = (int)coins.size();
        if (n == 0) return -1;
        //helper(coins,amount,n,0);
        return dpHelper(coins, amount, n);
    }
};
