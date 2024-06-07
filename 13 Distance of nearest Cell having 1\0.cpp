// link - https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?
// Time Complexity - O(N*M)
// Space Complexity - O(N*M)----dist + O(N*M)----Queue + O(N*M)---vis array

class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist = vis;
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;++i){
            for(int j =0;j<m;++j){
                if(grid[i][j]){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,-1,0,1};
        
        while(q.empty()==0){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            
            dist[row][col] = steps;
            q.pop();
            
            for(int i=0;i<4;++i){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
        
        return dist;
    }
};
