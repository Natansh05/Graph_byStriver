// link - https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
// Time Complexity - O(M*N*8)
// Space Complexity - O(N^2) + O(V^2) 


class Solution {
    typedef pair<int,pair<int,int>> ppi;
    typedef pair<int,int> pi;
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //  bfs karna hai , as soon as we reach till destination , we need to return minimum steps
        int n = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;

        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<ppi> q;
        dist[0][0] = 1;
        q.push({1,{0,0}});

        vector<pi> direction ={ {1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1} };
        while(q.empty()==0){
            ppi top = q.front();
            int dis = top.first;
            int row = top.second.first;
            int col = top.second.second;
            q.pop();

            for(int i=0;i<8;++i){
                pi del = direction[i];
                int nrow = row + del.first;
                int ncol = col + del.second;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dis + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = dis + 1;
                    q.push({dist[nrow][ncol], {nrow,ncol}});
                }
            }

        }

        return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1];
    }
};
