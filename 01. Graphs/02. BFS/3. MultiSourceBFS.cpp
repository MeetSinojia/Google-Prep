/* 
    This is a really good usecase of multi-source BFS 
    In this question we see how we can traverse from a point to tht point itself
    using minimum path.
    We can go back and forth btw nodes but should never land on the same config again
    https://www.youtube.com/watch?v=xvi8PqRrAyU
*/

//847. Shortest Path Visiting All Nodes

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int V = graph.size();
        queue<pair<int, int>> currLevel;
        for (int u = 0; u < V; u++) 
        {
            currLevel.push({u, 1 << u});  // Start Node,Initial state
        }
        
        int allVisited = (1 << V) - 1;  // Final state
        vector<vector<bool>> visited(V, vector<bool>(allVisited + 1, false));
        for (int u = 0; u < V; u++) 
        {
            visited[u][1 << u] = true;
        }
        
        int pathLength = 0;
        
        while (!currLevel.empty()) 
        {
            int n = currLevel.size();
            while (n > 0)  // We have to consider each point as start and check for minimum
            {
                pair<int, int> node = currLevel.front();
                currLevel.pop();
                int u = node.first;
                int bitMask = node.second;
                
                if (bitMask == allVisited) 
                {
                    return pathLength;
                }
                
                for (int v : graph[u]) 
                {
                    int nextBitMask = bitMask | (1 << v);
                    
                    if (visited[v][nextBitMask]) 
                    {
                        continue;
                    }
                    
                    if (nextBitMask == allVisited) 
                    {
                        return pathLength + 1;
                    }
                    
                    currLevel.push({v, nextBitMask});
                    visited[v][nextBitMask] = true;
                }
                
                n--;
            }
            
            pathLength++;
        }
        
        return -1;
    }
}; 
