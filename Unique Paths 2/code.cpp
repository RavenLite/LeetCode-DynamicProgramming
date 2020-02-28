#include <bits/stdc++.h>
using namespace std;

int M,N;
map<string,int> mp;

int uniquePathsWithObstaclesUsingMemoization(vector<vector<int>> &obstacleGrid,int x,int y){
    
    if (x >= M || y >= N){
        return 0;
    }
    if (obstacleGrid[x][y] == 1){
        return 0;
    }
    if (x == M-1 && y == N-1){
        return 1;
    }
    string key = "(" + to_string(x) + "," + to_string(y) + ")";
    if (mp.find(key) != mp.end()){
        return mp[key];
    }
        
    int rightPath = uniquePathsWithObstaclesUsingMemoization(obstacleGrid, x, y+1);
    int downPath = uniquePathsWithObstaclesUsingMemoization(obstacleGrid, x+1, y);
    
    mp[key] = rightPath + downPath;
    return mp[key];
}

int uniquePathsWithObstaclesUsingDP(vector<vector<int>> &obstacleGrid){
    unsigned int dp[M][N];
    bool isOneEncountered = false;
    for (int i=0;i<N;i++){
        if (isOneEncountered){
            dp[0][i] = 0;
            continue;
        }else{
            if (obstacleGrid[0][i] == 1){
                dp[0][i] = 0;
                isOneEncountered = true;
            }else{
                dp[0][i] = 1;
            }
        }
    }
    isOneEncountered = false;
    for (int i=0;i<M;i++){
        if (isOneEncountered){
            dp[i][0] = 0;
            continue;
        }else{
            if (obstacleGrid[i][0] == 1){
                dp[i][0] = 0;
                isOneEncountered = true;
            }else{
                dp[i][0] = 1;
            }
        }
    }
    
    for (int i=1;i<M;i++){
        for (int j=1;j<N;j++){
            if (obstacleGrid[i][j] == 1){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[M-1][N-1];
}

int main(){
    
    vector<vector<int>> obstacleGrid = {
        {0,1}
    };
    
    M = (int)obstacleGrid.size();
    N = (int)obstacleGrid[0].size();
    
    cout << uniquePathsWithObstaclesUsingMemoization(obstacleGrid,0,0) << "\n";
    cout <<uniquePathsWithObstaclesUsingDP(obstacleGrid);
    
    cout << "\n";
    
}
