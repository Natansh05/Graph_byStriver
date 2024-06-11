// link - https://leetcode.com/problems/path-with-minimum-effort/
// Time Complexity - O(ElogV) == O(N*M*4 * log(n*m))
// Space Complexity - O(N*M) + O(N*M)

class Solution {
    typedef pair<int,pair<int,int>> ppi;
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        pq.push({0,{0,0}});
        dist[0][0] = 0;

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,-1,0,1};

        while(pq.empty()==0){
            ppi top = pq.top();
            int dis = top.first;
            int row = top.second.first;
            int col = top.second.second;
            pq.pop();

            if(row==n-1 && col == m-1)
                return dis;

            for(int i=0;i<4;++i){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newEf = max( abs (grid[nrow][ncol]-grid[row][col]), dis);
                    if(newEf < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEf;
                        pq.push({newEf,{nrow,ncol}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};
