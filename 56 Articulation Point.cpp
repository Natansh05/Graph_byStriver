// link - https://www.geeksforgeeks.org/problems/articulation-point-1/1
// Time Complexity - O(N + N +E)
// Space Complexity - O(N)


class Solution {
  private:
  int timer = 1;
  void dfs(int node, int parent, vector<int>& visited, int low[], int tn[], vector<int>adj[],vector<int>&mark) {
      visited[node] = 1;
      low[node] = tn[node] = timer;
      timer++;
      int child=0;
      for(auto it:adj[node]) {
          if(it==parent) continue;
          if(!visited[it]) {
              dfs(it,node,visited,low,tn,adj,mark);
              low[node] = min(low[node],low[it]);
              if(low[it] >=tn[node] && parent!=-1) {
                  mark[node] = 1;
              }
              child++;
          }
          else {
              low[node] = min(low[node],tn[it]);
          }
      }
      if(child>1 && parent==-1) {
          mark[node] = 1;
      }
  }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // striver no betho code
        vector<int>visited(V,0);
        int low[V],tn[V];
        vector<int>mark(V,0);
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                dfs(i,-1,visited,low,tn,adj,mark);
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++) {
            if(mark[i]==1) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};
