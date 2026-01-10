class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>result;//创建接收路径的二维数组
        queue<vector<int>>pathqueue;//创建一个装路径的队列
        queue<int>nodequeue;//创建一个装节点的队列
        pathqueue.push({0});//初始化
        nodequeue.push(0);//初始化
        int target = graph.size() - 1;//拿出终止节点

        while(!nodequeue.empty()){
            vector<int> currentpath = pathqueue.front();
            int cur = nodequeue.front();
            pathqueue.pop();
            nodequeue.pop();
            if(cur == target){//如果到达终点
                result.push_back(currentpath);//加入完整的一条路径
                continue;//直接下一轮，再往下没意义
            }
            for(int i:graph[cur]){//访问该节点的邻居
                vector<int>newpath = currentpath;//创建新路径，currentpath要留着下轮循环用，不能改
                nodequeue.push(i);//推入节点
                newpath.push_back(i);//拓展路径
                pathqueue.push(newpath);//把路径专门推入装路径的队列
            }

        }
        return result;
    }
};