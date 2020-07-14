#include <bits/stdc++.h>

using namespace std;
const int N = 100001;
bool visited[N];
int n, m, a, b, team[N];
vector<int> adj[N];

void dfs(int s)
{
    visited[s] = true;
    for(int i:adj[s])
    {
        if(!visited[i])
        {
            team[i] = team[s]%2 +1;
            dfs(i);
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


    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            team[i] = 1;
            dfs(i);
        }

    }

    for(int i = 1;i<=n;i++)
    {
        for(int j:adj[i])
        {
            if(team[j]==team[i])
            {
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<team[i]<<" ";
    }

    return 0;
}
