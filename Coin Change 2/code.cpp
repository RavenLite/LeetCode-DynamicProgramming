class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        int n = amount;
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for (int i=0;i<=n;i++){
            dp[0][i] = 0;
        }
        for (int i=0;i<=m;i++){
            dp[i][0] = 1;
        }
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                if (coins[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[m][n];
    }
};
