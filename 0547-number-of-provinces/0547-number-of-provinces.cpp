class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected,
             vector<bool>& visited) {

        visited[node] = true;

        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
            if (isConnected[node][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        vector<bool> visited(V, false);
        int provinces = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(i, isConnected, visited);
            }
        }

        return provinces;
    }
};