#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
vector<int> adj[N];
vector<int> r;
int n, m, a, b, k;
bool visited[N];

void dfs(int s)
{
    if (visited[s])
        return;
    visited[s]=true;
    for(int x:adj[s])
        dfs(x);
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        if(visited[i])
            continue;
        else
        {
            r.push_back(i);
            dfs(i);
            k++;
        }
    }

    cout<<k-1<<"\n";
    for(int i=0;i<r.size()-1;i++)
    {
        cout<<r[i]<<" "<<r[i+1]<<"\n";
    }
    return 0;
}
