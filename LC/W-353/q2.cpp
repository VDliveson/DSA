#include <bits/stdc++.h>
using namespace std;

    class Solution {
    public:
        int helper(int ind,vector<int> &nums,int target,vector<int> &dp){
            int n = nums.size();
            if(ind==n-1) return 0;

            if(dp[ind]!=-1) return dp[ind];
            int ans = -1e9;

            for(int i=ind+1;i<n;i++){
                if(-target<=nums[i]-nums[ind] && nums[i]-nums[ind]<=target){
                    ans = max(ans,1 + helper(i,nums,target,dp));
                }
            }
            return dp[ind] = ans;
        }

        int maximumJumps(vector<int>& nums, int target) {
            int n = nums.size();
            vector<int> dp(n,-1);
            int ans = helper(0,nums,target,dp);
            if(ans<0) return -1;
            return ans;
        }
    };
int main(){
    Solution s;
    vector<int> nums = {1,3,6,4,1,2};
    int target = 3;
    cout<<s.maximumJumps(nums,target)<<endl;
    return 0;
}