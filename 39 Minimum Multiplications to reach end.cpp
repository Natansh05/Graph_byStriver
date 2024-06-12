// link - https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
// Time Complexity - O(N+E)
// Space Complexity - O(1e5) + O(N+E)

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        q.push({start,0});
        int mod = 100000;
        vector<int> dist(100000,INT_MAX);
        dist[start] = 0;
        
        if(start==end)
            return 0;
        
        while(q.empty()==0){
            int node = q.front().first;
            int cost = q.front().second;
            
            q.pop();
            
            for(auto it : arr){
                int num = (node * it ) % mod;
                if(num==end)
                    return cost+1;
                
                if(cost + 1 < dist[num]){
                    dist[num] = cost + 1;
                     q.push({num,cost + 1});
                }
            }
        }
        return -1;
    }
};
