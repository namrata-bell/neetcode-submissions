class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indeg(numCourses,0);
        for(auto &it:prerequisites){
            int course=it[0];
            int prerequisite=it[1];
            adj[prerequisite].push_back(course);
            indeg[course]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(int nei:adj[node]){
                indeg[nei]--;
                if(indeg[nei]==0)q.push(nei);
            }
        }
return cnt==numCourses;
    }
};
