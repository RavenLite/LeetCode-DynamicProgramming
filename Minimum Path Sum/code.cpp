#include <bits/stdc++.h>
using namespace std;

int minPathSumUsingDP(vector<vector<int>> &grid,int m,int n){
    int dp[m][n];
    dp[0][0] = grid[0][0];
    for (int i=1;i<n;i++){
        dp[0][i] = dp[0][i-1]+grid[0][i];
    }
    for (int i=1;i<m;i++){
        dp[i][0] = dp[i-1][0]+grid[i][0];
    }
    
    for (int i=1;i<m;i++){
        for (int j=1;j<n;j++){
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[m-1][n-1];
}


int main(){
    
    vector<vector<int>> grid = {
        {1,2},
        {5,6},
        {1,1}
    };
    int m = (int)grid.size();
    int n = (int)grid[0].size();
    cout << minPathSumUsingDP(grid, m, n);
    cout << "\n";
}
