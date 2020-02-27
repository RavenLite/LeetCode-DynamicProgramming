#include <bits/stdc++.h>
using namespace std;

bool checkForVP(string ss, int n){
    stack<char> st;
    for (int i=0;i<n;i++){
        if (ss[i] == '('){
            st.push('(');
            continue;
        }
        else if(!st.empty() && st.top() == '(' && ss[i] == ')'){
            st.pop();
            continue;
        }else if(st.empty() && ss[i] == ')'){
            return false;
        }
    }
    if (st.empty()) return true;
    return false;
}

int checkForValidParanthesesBruteForce(string s, int n){
    int maxLength=0;
    
    for (int k=2;k<=n;k++){
        for (int i=0;i<n-k+1;i++){
            string ss = s.substr(i,k);
            if (checkForVP(ss,(int)ss.size()) && ss.size() > maxLength){
                maxLength = (int)ss.size();
            }
        }
    }
    
    return maxLength;
}

int checkForValidPUsingStack(string s,int n){
    stack<int> st;
    st.push(-1);
    int res = 0;
    for (int i=0;i<n;i++){
        if (s[i] == '('){
            st.push(i);
        }
        else{
            st.pop();
            if (!st.empty()){
                res = max(i-st.top(), res);
            }else{
                st.push(i);
            }
        }
    }
    return res;
}

int main(){
    string s = "(()()))(";
    int n = (int)s.size();
    
    // Brute Force
    cout << checkForValidParanthesesBruteForce(s,n);
    
    // using stack
    cout << checkForValidPUsingStack(s,n);
    
    cout << "\n";
}
