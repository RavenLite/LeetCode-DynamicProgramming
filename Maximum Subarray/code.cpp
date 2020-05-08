#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        int maxTillNow = nums[0];
        dp[0] = nums[0];
        
        for (int i=1;i<n;i++){
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            if (dp[i] > maxTillNow) maxTillNow = dp[i];
        }
        return maxTillNow;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(nums);
    cout << "\n";
    
}
