// link - https://leetcode.com/problems/accounts-merge/description/
// Time Complexity - O(VlogE)
// Space Complexity- O(N)

class DisjointSet {
public: 
    vector<int> rank, parent, size; 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ult_u = findUPar(u); 
        int ult_v = findUPar(v); 
        if(ult_u == ult_v) return; 
        if(rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v; 
        }
        else if(rank[ult_v] < rank[ult_u]) {
            parent[ult_v] = ult_u; 
        }
        else {
            parent[ult_v] = ult_u; 
            rank[ult_u]++; 
        }
    }
    

    void UnionBySize(int u, int v) {
        int ult_u = findUPar(u); 
        int ult_v = findUPar(v); 
        if(ult_u == ult_v) return; 
        if(size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v; 
            size[ult_v] += size[ult_u]; 
        }
        else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v]; 
        }
    }
}; 



class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n+1);
        unordered_map<string , int> mp;
        for(int i=0;i<n;++i){
            for(int j=1;j<accounts[i].size();++j){
                if(mp.find(accounts[i][j])==mp.end())
                    mp[accounts[i][j]] = i;
                else
                    ds.UnionBySize(mp[accounts[i][j]] , i);
            }
        }
        
        vector<string> merge[n];
        for(auto it : mp){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            
            merge[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i=0;i<n;++i){
            if(merge[i].size()==0)
                continue;
            sort(merge[i].begin(),merge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : merge[i])
                temp.push_back(it);
            ans.push_back(temp);
        }
        
        return ans;
    }
};
