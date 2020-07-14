#include <bits/stdc++.h>

using namespace std;
const int N = 2501;
const long long INF = 9999999999;
int n, m, a, b, cost;
long long dist[N];
vector<pair<int, int>> adj[N];
bool visitedS[N], visitedE[N];
vector<int> cycle;

void dfs(int s, bool visited[N])
{
    if(visited[s])
        return;
    visited[s] = true;
    for(auto x:adj[s])
    {
        dfs(x.first, visited);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>cost;
        adj[a].push_back({b, cost});
    }

    for(int i=1;i<=n;i++)
        dist[i] = -INF;

    dist[1] = 0;

    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(auto x:adj[j])
            {
                dist[x.first] = max(dist[j] + x.second, dist[x.first]);
            }
        }
    }


    for(int j=1;j<=n;j++)
    {
        for(auto x:adj[j])
        {
            if(dist[j] + x.second > dist[x.first])
            {
                dist[x.first] = dist[j] + x.second;
                cycle.push_back(x.first);
            }
        }
    }
    if(!cycle.empty())
    {
        dfs(1, visitedS);
        for(auto start:cycle)
            if(visitedS[start])
                dfs(start, visitedE);

        if(visitedE[n])
        {
            cout<<-1;
            return 0;
        }
    }


    cout<<dist[n];

    return 0;
}
