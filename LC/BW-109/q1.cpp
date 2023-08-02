#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }

        for(auto it:mp){
            if(it.first >n-1) return false;
            if(it.first == n-1 && it.second!=2) return false;
            if(it.first <n-1 && it.second !=1) return false;
        }
        return true;
    }
};


int main(){
    vector<int> nums = {5,1,2,2,5,1};
    Solution sol;
    cout<<sol.isGood(nums)<<endl;
    return 0;
}