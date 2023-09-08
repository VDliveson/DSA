#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sol = INT_MIN;

    void helper(int r,int c,vector<vector<int>>& manhattan,int dist){
        int n = manhattan.size();
        int dr[] = {0,1};
        int dc[] = {1,0};
        if(r==n-1 && c==n-1){
            dist = min(dist,manhattan[r][c]);
            sol = max(sol,dist);
            return;
        }

        for(int i=0;i<2;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n){
                helper(nr,nc,manhattan,min(dist,manhattan[r][c]));
            }
        }

    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n= grid.size();

        if(grid[0][0] ==1 || grid[n-1][n-1]==1) return 0;
        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};
        vector<vector<int>> vis(n,vector<int> (n,0));
        vector<vector<int>> manhattan(n,vector<int> (n,-1));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    vis[i][j] = 1;
                    q.push({0,{i,j}});
                }
            }
        }
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.second.first;
            int c = it.second.second;
            int level = it.first;
            // cout<<r<<" "<<c<<" "<<level<<endl;
            manhattan[r][c] = level;

            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc]==0){
                    vis[nr][nc] = 1;
                    q.push({level+1,{nr,nc}});
                }
            }
        }

        int dist = INT_MAX;
        helper(0,0,manhattan,dist);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<manhattan[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return sol;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,1,1},{0,1,1},{1,1,0}};
    cout<<s.maximumSafenessFactor(grid)<<endl;
}

