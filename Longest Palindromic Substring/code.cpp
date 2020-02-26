#include <bits/stdc++.h>
using namespace std;

string checkPalindromicSubstringBruteForce(string s,int n){
    string res = "";
    
    for (int i=0;i<n-1;i++){
        for (int j=2;j<=n-i;j++){
            string ss = s.substr(i,j);
            int x=0;
            int y=(int)ss.size()-1;
            while (x<=y){
                if (ss[x] == ss[y]){
                    x++;
                    y--;
                }else{
                    break;
                }
            }
            if (x>y && ss.size() > res.size()){
                res = ss;
            }
        }
    }
    
    return res;
}

string checkPalindromicSubstringDP(string s,int n){
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    int start=0;
    int maxLength = 1;
    string res = "";
    for (int i=0;i<n;i++){
        dp[i][i] = true;
    }
    
    // for length two
    for (int i=0;i<n-1;i++){
        if (s[i] == s[i+1]){
            dp[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }
    
    // for length greater than 2
    for (int k=3;k<=n;k++){
        for (int i=0;i<n-k+1;i++){
            int j = i+k-1;
            if (dp[i+1][j-1] && s[i] == s[j]){
                dp[i][j] = true;
                start = i;
                if (k > maxLength){
                    maxLength = k;
                }
            }
        }
    }
    
    res = s.substr(start,maxLength);
    return res;
    
}

string expand(string s, int low, int high){
    
    while (low>=0 && high<s.size()-1 && s[low] == s[high]){
        low--;
        high++;
    }
    return s.substr(low+1,high-low-1);
}

string checkPalindromicSubstringNonDP(string s, int n){
    
    int maxLength = 0;
    string res="";
    for (int i=0;i<n;i++){
        
        string cs = expand(s,i,i);
        int clen = (int)cs.size();
        
        if ( clen > maxLength){
            maxLength = clen;
            res = cs;
        }
        
        cs = expand(s,i,i+1);
        clen = (int)cs.size();
        if (clen > maxLength){
            maxLength = clen;
            res = cs;
        }
    }
    return res;
}


int main(){
    
    string s = "asdfghhgfdjkkl";
    int n = (int)s.size();
    // Brute Force  TC: O(n^3)
    cout << checkPalindromicSubstringBruteForce(s,n);
    
    // Dynamic Programming TC: O(n^2) 
    cout << checkPalindromicSubstringDP(s,n);
    
    // Non DP in TC: O(n^2)
    cout << checkPalindromicSubstringNonDP(s, n);
    
    cout << "\n";
}
