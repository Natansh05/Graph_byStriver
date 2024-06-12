// link - https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
// Time Complexity - O(N^3)
// Space Complexity - O(N^2)

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    
	    for(int i=0;i<n;++i){
	        matrix[i][i] = 0;
	        for(int j=0;j<n;++j){
	            if(matrix[i][j]==-1)
	                matrix[i][j] = INT_MAX;
	        }
	    }
	    
	    
	    for(int k=0;k<n;++k){
	        for(int i=0;i<n;++i){
	            for(int j=0;j<n;++j){
	                if(matrix[i][k]!=INT_MAX && matrix[k][j]!=INT_MAX)
	                    matrix[i][j] = min ( matrix[i][j] , matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
	    
	    for(int i=0;i<n;++i){
	        for(int j=0;j<n;++j){
	            if(matrix[i][j]==INT_MAX)
	                matrix[i][j] = -1;
	        }
	    }
	    
	    return;
	    
	}
};



//  to check if negative cycle exists or not , check wheter matrix[i][i] < 0 , if true , that means negative cycle is present in the graph or else not
