#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    
    int n = (int)nums.size();
    int maxTillNow=INT_MIN;
    vector<int> dp1(n),dp2(n);
    for (int i=0;i<n;i++){
        //dp[i][i] = nums[i];
        dp1[i] = nums[i];
        if (nums[i] > maxTillNow){
            maxTillNow = nums[i];
        }
    }
    for (int i=1;i<n;i++){
        if (i==1){
            dp2[i-1] = nums[1] + dp1[i-1];
            if (dp2[i-1] > maxTillNow) maxTillNow = dp2[i-1];
            continue;
        }
        int a = dp1[i-1] + nums[i];
        int b = dp2[i-2] + nums[i];
        dp2[i-1] = max(a,b);
        if (dp2[i-1] > maxTillNow){
            maxTillNow = dp2[i-1];
        }
    }
    return maxTillNow;
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);
    cout << "\n";
    
}
