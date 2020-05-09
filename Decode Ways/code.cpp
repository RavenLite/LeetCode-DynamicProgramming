#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<string,int> lookup;
    int helper(string s,int index){
        
        if (s[index] == '0'){
            return 0;
        }
        
        if (index >= s.size()){
            return 1;
        }
        
        string key = to_string(index);
        if (lookup.find(key) != lookup.end()){
            return lookup[key];
        }
        
        int decodeOneChar = helper(s, index+1);
        int decodeTwoChar = 0;
        if (index+1 < s.size()){
            if ((s[index] == '1' && s[index+1] <= '9') || (s[index] == '2' && s[index+1] <= '6')){
                decodeTwoChar = helper(s, index+2);
            }
        }
        
        return lookup[key] = decodeOneChar + decodeTwoChar;
        
    }
    
    int numDecodings(string s) {
        return helper(s,0);
    }
};
