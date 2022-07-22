int timer=0;
void dfs(int src,int par,vector<int> adj[],vector<int> &vis,vector<vector<int>> &res,
  vector<int> &low,vector<int> &insTime){

  vis[src]=1;
  insTime[src]=low[src]=++timer;

  for(int dest:adj[src]){
  if(dest==par) continue;
  if(vis[dest]){
    // backedge
    low[src]=min(low[src],insTime[dest]);
  }else{
    dfs(dest,src,adj,vis,res,low,insTime);
    low[src]=min(low[src],low[dest]);
    // if the child node cannot be reached by any other path 
    if(low[dest]>insTime[src])
       res.push_back({src,dest});
    }
  }      
}
