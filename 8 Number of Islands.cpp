// link - geeksforgeeks.org/problems/find-the-number-of-islands/1
// Time Complexity - O(N^2 * 9)---GFG and O(N^2 * 4) on leetcode
// Space Complexity - O(N^2) + O(N^2)---recursive stack space

class Solution {
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>>& grid){
        vis[i][j] = 1;
        int n = vis.size();
        int m = vis[0].size();
        for(int delrow=-1;delrow<=1;++delrow){
            for(int delcol = -1;delcol<=1;++delcol){
                int row = i + delrow;
                int col = j + delcol;
                
                if(row>=0 && row<n && col>=0 && col<m)
                    if(vis[row][col]==0 && grid[row][col]=='1')
                        dfs(row,col,vis,grid);
            }
        }
        return;
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,vis,grid);
                    ++cnt;
                }
            }
        }
        return cnt;
        
    }
};
