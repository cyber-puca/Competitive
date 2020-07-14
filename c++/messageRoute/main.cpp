#include <bits/stdc++.h>

using namespace std;
const int N = 100001;
queue<int> q;
bool visited[N];
int dist[N], n, m, a, b;
vector<int> adj[N];
stack<int> r;

void bfs()
{
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        for(int i:adj[s])
        {
            if(visited[i])
                continue;
            visited[i] = true;
            dist[i] = dist[s]+1;
            q.push(i);

        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    q.push(1);
    visited[1] = true;
    dist[1] = 0;

    bfs();
    if(dist[n]==0)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<dist[n]+1<<"\n";

    int node = n;
    while(node!=1)
    {
        r.push(node);
        for(int i:adj[node])
        {
            if(visited[i] && dist[i]==dist[node]-1)
            {
                node = i;
            }
        }
    }
    cout<<1<<" ";
    while(!r.empty())
    {
        cout<<r.top()<<" ";
        r.pop();
    }
    return 0;
}
