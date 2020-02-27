#include <bits/stdc++.h>
using namespace std;

int M,N;

int uniquePathsUtil(int x,int y){
    
    if (x>M || y>N){
        return 0;
    }
    
    if (x == M && y == N){
        return 1;
    }
    
    int rightPath = uniquePathsUtil(x, y+1);
    int downPath = uniquePathsUtil(x+1, y);
    
    return rightPath + downPath;
    
}

int uniquePathsUsingMemoization(int m,int n){
    M = n;
    N = m;
    
    return uniquePathsUtil(1,1);
}

int uniquePathsUsingDP(int m,int n){
    M = n;
    N = m;
    int dp[M][N];
    
    for (int j=0;j<N;j++){
        dp[M-1][j] = 1;
    }
    for (int i=0;i<M;i++){
        dp[i][N-1] = 1;
    }
    for (int i=M-2;i>=0;i--){
        for (int j=N-2;j>=0;j--){
            dp[i][j] = dp[i+1][j] + dp[i][j+1];
        }
    }
    return dp[0][0];
}

int main(){
    
    cout << uniquePathsUsingMemoization(19, 13) << "\n";
    
    cout << uniquePathsUsingDP(19, 13);
    cout << "\n";
}
