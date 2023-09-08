#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int> nums,int target){
        int n = nums.size();
        vector<int> temp = nums;
        
        
        int t = 0;
        while(true){
            t++;
            for(int i=0;i<n;i++){
                int a = nums[(i - 1 + n) % n];
                int b = nums[(i + 1) % n];
                if(nums[i] == target || a==target || b==target){
                    temp[i] = target;
                }
            }
            unordered_set<int> st;
            for(auto it:temp) st.insert(it);
            if(st.size()==1){
                cout<<st.size()<<endl;
                break;
            }
            
        }
        return t;
        
    }
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(),nums.end());
        if(st.size()==1) return 0;
        
        int ans = INT_MAX;
        for(auto it:st){
            ans = min(ans,helper(nums,it));
        }
        return ans;
    }
};


int main(){
    Solution s;
    vector<int> nums = {2,1,3,3,2};
    cout<<s.minimumSeconds(nums)<<endl;
}