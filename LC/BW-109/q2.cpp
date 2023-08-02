#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c){
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        if(vowels.find(c) != vowels.end()){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        int n = s.size();
        priority_queue<char, vector<char>, greater<char> > pq;
        vector<char> v(n,' ');
        for(int i=0; i<n; i++){
            char c = s[i];
            if(isVowel(c)){
                pq.push(c);
            }else{
                v[i] = c;
            }
        }
        
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if(v[i]==' '){
                v[i] = pq.top();
                pq.pop();
            }

            ans+=v[i];
        }

        return ans;
    }
};


int main(){
    string s= "AbeiOu";
    Solution sol;
    cout<<sol.sortVowels(s)<<endl;
    return 0;
}