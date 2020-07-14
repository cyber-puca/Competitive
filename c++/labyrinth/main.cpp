#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
queue<pair<int, int> > q;
bool visited[N][N];
int dist[N][N];
int n, m, di[4]={-1, 0, 0, 1}, dj[4]={0, -1, 1, 0}, x, y;
char a[N][N], c[4] = {'D', 'R', 'L', 'U'};
stack<char> path;
pair<int, int> b, e, s;

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='B')
                e = {i,j};
            else if(a[i][j]=='A')
                b = {i,j};
        }

   visited[b.first][b.second] = true;
   dist[b.first][b.second] = 0;
   q.push({b.first, b.second});
   while(!q.empty())
   {
       s = q.front();
       q.pop();
       for(int k=0;k<4;k++)
       {
           x = s.first + di[k];
           y = s.second + dj[k];
           if(x<n && y<m && x>=0 && y>=0 && a[x][y]!='#' && !visited[x][y])
           {
               visited[x][y] = true;
               dist[x][y] = dist[s.first][s.second] + 1;
               q.push({x,y});
           }
       }
   }


    if(!visited[e.first][e.second])
    {
        cout<<"NO";
        return 0;
    }

    cout<<"YES\n";
    cout<<dist[e.first][e.second]<<"\n";
    s = {e.first, e.second};
    int d = dist[e.first][e.second];
    while(d>0)
    {
        for(int k=0;k<4;k++)
       {
           x = s.first + di[k];
           y = s.second + dj[k];
           if(x<n && y<m && x>=0 && y>=0 && visited[x][y] && dist[x][y]==d-1)
           {
               path.push(c[k]);
               s = {x, y};
               d--;
               break;
           }
       }
    }
    while(!path.empty())
    {
        cout<<path.top();
        path.pop();
    }

    return 0;
}
