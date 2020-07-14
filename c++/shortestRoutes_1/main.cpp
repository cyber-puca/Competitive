#include <bits/stdc++.h>

using namespace std;
const int N = 100001;
long long INF = 1LL<<60;
priority_queue<pair<long long, int>> q;
int n, m, a, b, cost;
long long dist[N];
vector<pair<int, int>> adj[N];
bool processed[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>cost;
        adj[a].push_back({b,cost});
    }
    for(int i=1;i<=n;i++)
    {
        dist[i] = INF;
    }
    q.push({0, 1});
    dist[1] = 0;
    while(!q.empty())
    {
        a = q.top().second;
        q.pop();
        if(processed[a])
            continue;
        processed[a] = true;
        for(auto x:adj[a])
        {
            b = x.first;
            cost = x.second;
            if(dist[b] > dist[a] + cost)
            {
                dist[b] = dist[a] + cost;
                q.push({-dist[b], b});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}
