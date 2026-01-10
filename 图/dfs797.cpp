//bool Solution::visit[100][100];
class Solution {
public:
    bool visit[100]; 
    void dfs(int u,int sz,vector<vector<int>>& result,vector<int>& res,vector<vector<int>>& graph){
        if(u > sz)return;
        if(visit[u])return;
        res.push_back(u);
        visit[u] = true;
        if(u == sz){
            result.push_back(res);
        }
        for(int i :graph[u]){
            dfs(i,sz,result,res,graph);
        }
        res.pop_back();
        visit[u] = false;

   }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>result;
        vector<int>res;
        int sz = graph.size() - 1;
       // for(int i :graph[0]){
            dfs(0,sz,result,res,graph);
      // }/////////////////////////////
        return result;
    }
};