#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int ind,int prev,
    vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp){
        int n = nums1.size();
        if(ind==n) return 0;
        
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

        int notPick = 0;
        int left = 0; 
        int right = 0;
        if(prev==0){
            if(nums1[ind-1]<=nums1[ind]){
                left = 1 + helper(ind+1,0,nums1,nums2,dp);
            }

            if(nums1[ind-1]<=nums2[ind]){
                right = 1 + helper(ind+1,1,nums1,nums2,dp);
            }
        }
        else if(prev==1){
            if(nums2[ind-1]<=nums1[ind]){
                left = 1 + helper(ind+1,0,nums1,nums2,dp);
            }
            if(nums2[ind-1]<=nums2[ind]){
                right = 1 + helper(ind+1,1,nums1,nums2,dp);
            }
        }else{
            left = 1 + helper(ind+1,0,nums1,nums2,dp);
            right = 1 + helper(ind+1,1,nums1,nums2,dp);
            notPick = helper(ind+1,prev,nums1,nums2,dp);
        }
        return dp[ind][prev+1] = max(notPick,max(left, right));
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return helper(0,-1,nums1,nums2,dp);
    }
};

int main(){
    vector<int> nums1 = {3,19,13,19}; 
    vector<int> nums2 = {20,18,7,14};
    // Ans 2
    Solution s;
    cout<<s.maxNonDecreasingLength(nums1,nums2)<<endl;
    return 0;
}