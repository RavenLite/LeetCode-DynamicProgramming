class Solution {
public:
    map<string,int> mp;
    int countStairs=0;
    
    int climbStairs(int n) {
        if (n < 0 ) return 0;
        if (n == 0) {
            countStairs++;
            return 1;
        }
        string key = "|" + to_string(n) + "|";
        if (mp.find(key) != mp.end()){
            return mp[key];
        }
        mp[key] = climbStairs(n-1) + climbStairs(n-2);
        return mp[key];
    }
};
