#include <bits/stdc++.h>

using namespace std;
const int N = 100008;
int n, m, a, b;
bool visited[N], found;
vector<int> adj[N], p;
stack<int> c;

void display(int j)
{
    stack<int> cp(c);
    p.push_back(j);
    while(!cp.empty() && cp.top()!=j)
    {
        p.push_back(cp.top());
        cp.pop();
    }
    p.push_back(j);
    cout<<p.size()<<"\n";
    for(int i=0;i<p.size();i++)
    {
        cout<<p[i]<<" ";
    }
}

void dfs(int s, int l)
{
    visited[s] = true;
    c.push(s);
    for(int j:adj[s])
    {
        if(visited[j] && l!=j && !found)
        {
            display(j);
            found = true;
        }
        else if(!visited[j])
        {
            dfs(j,s);
        }
    }
    c.pop();

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
            dfs(i,0);
        }
    }
    if(!found)
        cout<<"IMPOSSIBLE";
    return 0;
}
