#include <bits/stdc++.h>
using namespace std;

map<string,int> mp;
int minDistanceUsingMemoization(string word1, string word2, int m,int n){
    
    if (min(m,n) == 0) return max(m,n);
    
    int cost;
    if (word1[m-1] == word2[n-1]){
        cost = 0;
    }else cost = 1;
    
    string key = to_string(m) + "-" + to_string(n);
    if (mp.find(key) != mp.end()){
        return mp[key];
    }
    
    mp[key] = min(min(minDistanceUsingMemoization(word1, word2, m-1, n)+1,minDistanceUsingMemoization(word1, word2, m, n-1)+1),
               minDistanceUsingMemoization(word1, word2, m-1, n-1) + cost);
    return mp[key];
}

int minDistanceUsingDP(string word1, string word2, int m,int n){
    
    int dp[m+1][n+1];
    
    for (int i=0;i<=m;i++){
        dp[i][0] = i;
    }
    for (int j=0;j<=n;j++){
        dp[0][j] = j;
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if (word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            }
        }
    }
    
    return dp[m][n];
}

int main(){
    
    string word1 = "horse";
    string word2 = "ros";
    int m = (int)word1.size();
    int n = (int)word2.size();
    cout << minDistanceUsingMemoization(word1, word2, m, n);
    cout << "\n";
    
    cout << minDistanceUsingDP(word1, word2, m, n);
    
    cout << "\n";
}
