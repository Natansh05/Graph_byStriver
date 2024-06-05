// link - https://www.geeksforgeeks.org/problems/number-of-provinces/1
// Time Complexity - O(N + N + 2E)
// Space Complexity - O(N)


class Solution {
    void dfs(int node,vector<int> adj[],int vis[]){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(vis[it]==0)
                dfs(it,adj,vis);
        }
        return;
    }
  public:
    int numProvinces(vector<vector<int>> mat, int n) {
        //  to make first adjancency list , hume matrix diya gaya hai
        vector<int> adj[n];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        int vis[n]={0};
        for(int i=0;i<n;++i){
            if(vis[i]==0){
                dfs(i,adj,vis);
                ++cnt;
            }
        }
        return cnt;
        
        
    }
};
