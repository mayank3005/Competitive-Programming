class DisjointSet{
    vector<int> parent,size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }   
    int findParent(int u){
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }
    void Union(int u,int v){
        u=findParent(u),v=findParent(v);
        if(size[u]>size[v]){
            parent[v]=u;
            size[u]+=size[v];
        }else{
            parent[u]=v;
            size[v]+=size[u];
        }
    }
};
