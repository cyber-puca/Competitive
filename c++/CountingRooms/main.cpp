#include <bits/stdc++.h>

using namespace std;

queue<int> q;
const int N = 1001;
bool visited[N][N];
int n, mE, r, di[4]={-1, 0, 0, 1}, dj[4]={0, -1, 1, 0};
char m[N][N];

void dfs(int x, int y)
{
    if(visited[x][y])
        return;
    visited[x][y] = true;
    for(int k=0;k<4;k++)
        if(m[x+di[k]][y+dj[k]]=='.')
            dfs(x+di[k], y+dj[k]);
}

int main()
{
    cin>>n>>mE;
    for(int i=0;i<n;i++)
        for(int j=0;j<mE;j++)
        {
            cin>>m[i][j];
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<mE;j++)
        {
            if(m[i][j]=='.' && !visited[i][j])
            {
                dfs(i,j);
                r++;
            }
        }
    cout<<r;
    return 0;
}
