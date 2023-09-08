#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        if(n==1){
            if (num[0]-'0' == 0) return 0;
            return 1;
        }

        int sum = 0;
        for(int i=n-2;i<n;i++){
            sum = sum*10 + num[i]-'0';
        }

        if(sum%25==0) return 0;


        if(n==2){
            if(sum%10==0) return 1;
            return 2;
        }
        
        vector<int> s2,s5,s7,s0;
        for(int i=n-1;i>=0;i--){
            if(num[i]=='2'){
                s2.push_back(i);
            }
            if(num[i]=='0'){
                s0.push_back(i);
            }
            if(num[i]=='5'){
                s5.push_back(i);
            }
            if(num[i]=='7'){
                s7.push_back(i);
            }
        }
        
        int make25 = 1e9;
        int make75 = 1e9;
        int make00 = 1e9;
        int make50 = 1e9;

        for(auto it:s5){
            int idx = it;
            int get = -1;
            for(auto it1:s2){
                if(it1<idx){
                    get = it1;
                    break;
                }
            }
            if(get!=-1){
                make25 = n-get-2;
                break;
            }
        }

        for(auto it:s5){
            int idx = it;
            int get = -1;
            for(auto it1:s7){
                if(it1<idx){
                    get = it1;
                    break;
                }
            }
            if(get!=-1){
                make75 = n-get-2;
                break;
            }
        }

        for(auto it:s0){
            int idx = it;
            int get = -1;
            for(auto it1:s5){
                if(it1<idx){
                    get = it1;
                    break;
                }
            }
            if(get!=-1){
                make50 = n-get-2;
                break;
            }            
        }

        if(s0.size()>=2){
            make00 = (n-s0[1]-2);
        }

        
        int ans = min(min(make25,make50),min(make75,make00));
        if(ans==1e9){
            if(s0.size()==0){
                return n;
            }else{
                return n-1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    string num = "701455107";
    string num = "820366";
    cout<<s.minimumOperations(num)<<endl;
}