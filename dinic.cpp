struct Dinic
{
    struct Edge
    {
        int u,v;
        long long int cap,flow=0;
        Edge(){}
        Edge(int u,int v,long long int cap):u(u),v(v),cap(cap){}
    };
    int N;
    vector<Edge>edge;
    vector<vector<int>>adj;
    vector<int>d,pt;
    Dinic(int N):N(N),edge(0),adj(N),d(N),pt(N){}
    void addEdge(int u,int v, lli cap)
    {
        if(u==v) return;
        edge.emplace_back(u,v,cap);
        adj[u].emplace_back(edge.size()-1);
        edge.emplace_back(v,u,0);
        adj[v].emplace_back(edge.size()-1);
    }

    bool bfs(int s,int t)
    {
        queue<int>q({s});
        fill(d.begin(),d.end(),N+1);
        d[s]=0;
        while(!q.empty())
        {
            int u=q.front();q.pop();
            if(u==t) break;
            for(int k:adj[u])
            {
                Edge &e = edge[k];
                if(e.flow<e.cap && d[e.v]>d[e.u]+1)
                {
                    d[e.v]=d[e.u]+1;
                    q.emplace(e.v);
                }
            }
        }
        return d[t]!=N+1;
    }
    long long int dfs(int u,int T,long long int flow = -1)
    {
        if(u==T|| flow==0) return flow;
        for(int &i = pt[u];i<adj[u].size();i++)
        {
            Edge &e = edge[adj[u][i]];
            Edge &oe = edge[adj[u][i]^1];
            if(d[e.v]==d[e.u]+1)
            {
                long long int amt = e.cap-e.flow;
                if(flow!=-1 && amt>flow) amt = flow;
                if(long long int pushed = dfs(e.v,T,amt))
                {
                    e.flow+=pushed;
                    oe.flow-=pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    long long int maxFlow(int s,int t)
    {
        long long int total=0;
        while(bfs(s,t))
        {
            fill(pt.begin(),pt.end(),0);
            while(long long int flow = dfs(s,t))
            {
                total+=flow;
            }
        }
        return total;
    }

};

//call Dinic di(nubmer of nodes);
