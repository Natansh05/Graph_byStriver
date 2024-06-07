// link - https://leetcode.com/problems/surrounded-regions/description/
// Time Complexity - O(M*N *4)  + O(N) + O(M) -----O(N*M)
// Space  Complexity - O(M*N)
class Solution {
    private:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> grid, int delrow[],int delcol[]){
        int n = vis.size();
        int m = vis[0].size();
        vis[i][j] = 1;
        for(int k=0;k<4;++k){
            int row = i + delrow[k];
            int col = j + delcol[k];

            if(row>=0 && row<n && col>=0 && col<m && vis[row][col]==0 && grid[row][col]=='O'){
                vis[row][col] = 1;
                dfs(row,col,vis,grid,delrow,delcol);
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delrow[4] = {-1,0,+1,0};
        int delcol[4] = {0,-1,0,+1};    
        vector<vector<int>> vis(n,vector<int>(m,0));

        // traverse the first row
        for(int j=0;j<m;++j){
            if(!vis[0][j] && grid[0][j]=='O')
                dfs(0,j,vis,grid,delrow,delcol);
            if(!vis[n-1][j] && grid[n-1][j]=='O')
                dfs(n-1,j,vis,grid,delrow,delcol);
        }

        // traverse first col
        for(int i=0;i<n;++i){
            if(!vis[i][0] && grid[i][0]=='O')
                dfs(i,0,vis,grid,delrow,delcol);
            if(!vis[i][m-1] && grid[i][m-1]=='O')
                dfs(i,m-1,vis,grid,delrow,delcol);
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(vis[i][j]==0)
                    grid[i][j] = 'X';
            }
        }

        return;
    }
};
