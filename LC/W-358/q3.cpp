#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        map<int,int>mm;
        for(int i = x;i<nums.size();i++){
            mm[nums[i]] = i;
        }

        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            int val = nums[i];
            auto it = mm.upper_bound(val);
            
            if(it != mm.begin()) {
                --it;                
            }

            if(it->first != 0)ans = min(ans,abs(val-(it->first)));
            it = mm.lower_bound(val);
            if(it->first != 0)ans = min(ans,abs(val-(it->first)));
            if(i+x<n && mm[nums[i+x]] == i+x)mm.erase(nums[i+x]);
        }
        return ans;
        
    }
};