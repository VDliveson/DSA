#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int start = nums[i] - k;
        int end = min(nums[i] + k,n-1);

    }
};

int main(){
    Solution s;
    vector<int> nums = {4,6,1,2};
    int k = 2;
    cout<<s.maximumBeauty(nums,k)<<endl;
}