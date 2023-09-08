#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int> &nums){
        vector<int>dp(nums.size(),1);
        for(int i = 0; i < nums.size(); i++)
            for(int j = i -1 ; j >= 0; j--)
               if(nums[i] >= nums[j]) dp[i] = max(dp[i], 1 + dp[j]);
        return *max_element(dp.begin(),dp.end());
    }
    
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        return n-helper(nums);
    }
};

int main(){
    vector<int> nums = {1,3,2,1,3,3};
    Solution s;
    cout<<s.minimumOperations(nums);
    return 0;
}