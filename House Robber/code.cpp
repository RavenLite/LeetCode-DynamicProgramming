#include <bits/stdc++.h>
using namespace std;

int robUtility(vector<int> &nums, int i,int sum){
    
    if (i >= nums.size()){
        return sum;
    }
    int leftMax = robUtility(nums, i+1, sum);
    int rightMax = robUtility(nums, i+2, sum+nums[i]);
    return max(leftMax,rightMax);
}


int rob(vector<int>& nums) {
    return robUtility(nums,0,0);
}


int robDP(vector<int> &nums){
    int n = (int)nums.size();
    int dp[n];
    if (n==1) return nums[0];
    if (n==2) return max(nums[0],nums[1]);
    
    dp[0] = nums[0];
    dp[1] = max(dp[0],nums[1]);
    for (int i=2;i<n;i++){
        dp[i] = max((dp[i-2]+nums[i]),dp[i-1]);
    }
    return dp[n-1];
}

int main(){
    
    vector<int> nums = {2,7,9,1,1,10,1};
    // recursive method gives TLE
    cout << rob(nums) << "\n";
    // dynamic programming solution works fine
    cout << robDP(nums);

    cout << "\n";
    
}
