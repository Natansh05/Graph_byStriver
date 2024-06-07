// link - https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
// Time Complexity - O(N*Mlog(N*M)) + O(M*N)
// Space Complexity - O(N*M)

class Solution {
    
    
    void printSet(const set<vector<pair<int, int>>>& st) {
        for (const auto& vec : st) { // Iterate through each vector in the set
            cout << "{ ";
            for (const auto& p : vec) { // Iterate through each pair in the vector
                cout << "(" << p.first << ", " << p.second << ") ";
            }
            cout << "}\n";
        }
    }
    
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,-1,0,1};
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid,vector<pair<int,int>> &temp){
        vis[i][j] = 1;
        
        int n = vis.size();
        int m = vis[0].size();
        
        if(temp.size()==0){
            // cout<<i<<" "<<j<<endl;
            temp.push_back({i,j});
        }
        else{
            // cout<<i<<" "<<j<<endl;
            temp.push_back({i-temp[0].first,j-temp[0].second});
        }
        
        for(int k=0;k<4;++k){
            int row = i + delrow[k];
            int col = j + delcol[k];
            
            if(row>=0 && row<n && col>=0 && col<m && vis[row][col]==0 && grid[row][col]==1){
                dfs(row,col,vis,grid,temp);
            }
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(vis[i][j]==0 && grid[i][j] == 1){
                    vector<pair<int,int>> temp;
                    dfs(i,j,vis,grid,temp);
                    temp[0].first = 0;
                    temp[0].second = 0;
                    st.insert(temp);
                }
            }
        }
        // printSet(st);
        return st.size();
    }
};
