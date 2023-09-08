#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMax(int a){
        int amax = INT_MIN; 
        while(a){
            amax = max(a%10,amax);
            a = a/10;
        }
        return amax;
    }
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for(int i=0;i<n;i++){
            int amax = getMax(nums[i]);
            for(int j=i+1;j<n;j++){
                int bmax = getMax(nums[j]);
                if(bmax==amax){
                    ans = max(ans,nums[i]+nums[j]);
                }                
            }
        }
        return ans;
    }
};