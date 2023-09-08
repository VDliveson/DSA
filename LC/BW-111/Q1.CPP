#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] + nums[j] < target){
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {-6,2,5,-2,-7,-1,3}; 
    int target = -2;
    Solution s;
    cout<<s.countPairs(nums, target);
    return 0;
}