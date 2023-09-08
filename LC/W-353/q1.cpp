#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + 2*t;
    }
};

int main(){
    Solution s;
    cout<<s.theMaximumAchievableX(3,2)<<endl;
}