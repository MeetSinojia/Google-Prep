class Solution {
    
  public:
    bool dfs(int node,vector<int> adj[],int vis[],int pvis[])
    {
        vis[node]=1;
        pvis[node]=1;
        
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,pvis)==true)
                {
                    return true;
                }
            }
            
            else if(vis[it] && pvis[it])
            {
                return true;
            }
        }
        pvis[node]=0;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int pvis[V]={0};
        
        for(int i=0;i<V;i++)
        {
            if(dfs(i,adj,vis,pvis)==true)
            {
                return true;
            }
        }
        
        return false;
    }
};
