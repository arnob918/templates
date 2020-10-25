#define N 200200
#define LN 20
int table[N][LN];
vector<int> dis;
vector<int> par(N);
vector<int> po(20);

vector<int> bfs(int x)
{
    vector<int> d(n+1, -1);
    queue<int> qu;
    qu.push(x);
    d[x] = 0;
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];

            if(d[v] == -1){
                d[v] = d[u]+1;
                qu.push(v);
                par[v] = u;
            }
        }
    }
    return d;
}

void sptb()
{
    par[1] = -1;
    dis = bfs(1);
    po[0] = 1;
    for(int i=1; i<LN; i++){
        po[i] = po[i-1]<<1;
    }
    for(int i=1; i<=n; i++){
        table[i][0] = par[i];
    }
    for(int i=1; i<LN; i++){
        for(int j=1; j<=n; j++){
            if(dis[j] >= po[i]){
                table[j][i] = table[table[j][i-1]][i-1];
            }
            else{
                table[j][i] = -1;
            }
        }
    }
}

int lca(int u, int v)
{
    if(dis[u] < dis[v]){
        int x = dis[v]-dis[u];
        for(int i=19; i>=0; i--){
            if(po[i]<=x){
                v = table[v][i];
                x -= po[i];
            }
        }
    }
    else if(dis[u] > dis[v]){
        int x = dis[u] - dis[v];
        for(int i=19; i>=0; i--){
            if(po[i]<=x){
                u = table[u][i];
                x -= po[i];
            }
        }
    }

    if(u == v){
        return u;
    }

    for(int i=19; i>=0; i--){
        if(dis[u] >= po[i] && table[u][i] != table[v][i]){
            u = table[u][i];
            v = table[v][i];
        }
    }
    return par[u];
}
