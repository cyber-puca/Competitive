#include <bits/stdc++.h>

using namespace std;
const int N = 100001;
const long long INF = 1LL<<60;
int n, m, a, b, cost;
long long dist[2][N];
bool processed[2][N];
vector<pair<int, int>> adj[N];
priority_queue<tuple<long long, int, int>> q;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>cost;
        adj[a].push_back({b, cost});
    }

    for(int i=1;i<=n;i++)
    {
        dist[0][i] = INF;
        dist[1][i] = INF;
    }

    dist[0][1] = 0;
    q.push({0, 1, 0}); // distance, node, used/not used

    while(!q.empty())
    {
        int a, used;
        long long cost;
        tie(cost, a, used) = q.top();
        q.pop();

        if(processed[used][a])
            continue;
        processed[used][a] = true;
        for(auto x:adj[a])
        {

            if(used)
            {
                if(dist[1][a] + x.second < dist[1][x.first])
                {
                    dist[1][x.first] = dist[1][a] + x.second;
                    q.push({-dist[1][x.first], x.first, 1});
                }
            }
            else
            {
                if(dist[1][x.first]>dist[0][a] + x.second/2)
                {
                    dist[1][x.first] = dist[0][a] + x.second/2;
                    q.push({-dist[1][x.first], x.first, 1});
                }
                if(dist[0][x.first]>dist[0][a] + x.second)
                {
                    dist[0][x.first] = dist[0][a] + x.second;
                    q.push({-dist[0][x.first], x.first, 0});
                }
            }
        }
    }
    cout<<dist[1][n];
    return 0;
}
