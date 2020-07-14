#include <bits/stdc++.h>

using namespace std;
const int N = 1001, INF = 1000000000;
int n, m, distM[N][N], distA[N][N], di[4] = {1, 0, 0, -1}, dj[4] = {0, 1, -1, 0};
char l[N][N], dir[4] = {'U', 'L', 'R', 'D'};
pair<int, int> a;

bool valid(int i, int j)
{
    return (i>0 && j>0 && i<=n && j<=m && l[i][j]!='#');
}

void path(int i, int j)
{
    cout<<"YES\n";
    cout<<distA[i][j]<<"\n";

    string sol;
    int x, y;
    while(make_pair(i, j)!=a)
    {
        for(int k=0;k<4;k++)
        {
            x = i + di[k];
            y = j + dj[k];
            if(valid(x, y) && distA[x][y]==distA[i][j]-1)
            {
                sol += dir[k];
                i = x;
                j = y;
                break;
            }
        }
    }
    reverse(sol.begin(), sol.end());
    cout<<sol;

}

void bfs(queue<pair<int, int>> &q, int dist[N][N])
{
    pair<int, int> p;
    int x, y;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            x = p.first + di[i];
            y = p.second + dj[i];
            if(valid(x,y) && dist[x][y]==INF)
            {
                dist[x][y] = dist[p.first][p.second] + 1;
                q.push({x, y});
            }
        }
    }
}
int main()
{
    vector<pair<int, int>> monsters;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>l[i][j];
            distA[i][j] = INF;
            distM[i][j] = INF;
            if(l[i][j]=='M')
                monsters.push_back({i, j});
            else if(l[i][j]=='A')
                a = {i, j};
        }

    queue<pair<int, int>> q;

    for(auto p:monsters)
    {
        q.push(p);
        distM[p.first][p.second] = 0;
    }
    bfs(q, distM);

    q.push(a);
    distA[a.first][a.second] = 0;
    bfs(q, distA);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(i==1 || j==1 || i==n || j==m)
                if(valid(i, j) && distM[i][j] > distA[i][j])
                {
                    path(i,j);
                    return 0;
                }
    cout<<"NO";
    return 0;
}
