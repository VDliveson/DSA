#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long helper(int ind,int parity,vector<int>& nums, int x, vector<vector<long long>> &dp) {
        int n = nums.size();
        if(ind==n) return 0;
         
        if (dp[ind][parity] != -1) return dp[ind][parity];

        long long take=0, notTake=0;
        take = nums[ind] + helper(ind+1, nums[ind]%2,nums, x, dp);
        if ((nums[ind] % 2) != (parity)) {
            take -= x;
        }
        if(ind!=0){
            notTake = 0 + helper(ind+1, parity,nums, x, dp);
        }
        
        long long val = max(take, notTake);
        return dp[ind][parity] = val;
    }

    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long> (2,-1));
        return helper(0, nums[0]%2,nums, x, dp);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,6,1,9,2};
    int x = 5;
    cout<<sol.maxScore(nums,x)<<endl;
    return 0;
}