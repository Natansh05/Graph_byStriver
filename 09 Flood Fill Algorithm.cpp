// link - geeksforgeeks.org/problems/flood-fill-algorithm1856/1
// Time Complexity - O(M*N)
// Space Complexity - O(N*M + N*M)

class Solution {
    void dfs(int row,int col,vector<vector<int>>& ans,
    vector<vector<int>>& image, int color,int drow[],int dcol[],int ini){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i=0;i<4;++i){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == ini && ans[nrow][ncol]!=color){
                dfs(nrow,ncol,ans,image ,color,drow,dcol,ini);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int ini = image[sr][sc];
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        dfs(sr,sc,ans,image,color,drow,dcol,ini);
        return ans;
    }
};
