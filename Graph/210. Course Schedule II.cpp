// LeetCode Link - "https://leetcode.com/problems/course-schedule-ii/description"


class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graphs(num,vector<int>());
        vector<int>indegree(num);
        for(vector<int>&ans : prerequisites){
            graphs[ans[1]].push_back(ans[0]);
            indegree[ans[0]]++;
        }
        queue<int>zero;
        for(int i=0;i<num;i++){
            if(indegree[i] == 0) zero.push(i);
        }
        vector<int>ans;
        int visited = 0;
        while(!zero.empty()){
            int u = zero.front();
            zero.pop();
            ans.push_back(u);
            visited++;
            for(int v: graphs[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    zero.push(v);
                }
            }
        }
        if(visited == num){
            return ans;
        } 
        return {};
    }
};



// Solution ---> STack
class Solution {
public:
    bool DFS(int node, vector<vector<int>>& adj, vector<int>& state, stack<int>& st) {
        state[node] = 1; // visiting

        for(int neighbor : adj[node]) {
            if(state[neighbor] == 1) return false; // cycle detected
            if(state[neighbor] == 0) {
                if(!DFS(neighbor, adj, state, st)) return false;
            }
        }

        state[node] = 2; // visited
        st.push(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course); // prereq -> course
        }

        vector<int> state(numCourses, 0); // 0=unvisited, 1=visiting, 2=visited
        stack<int> st;

        for(int i = 0; i < numCourses; i++) {
            if(state[i] == 0) {
                if(!DFS(i, adj, state, st)) return {}; // cycle detected
            }
        }

        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
