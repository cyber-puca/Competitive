#include <bits/stdc++.h>

using namespace std;
const int N = 501;
long long d[N][N];
const long long INF = 1LL<<60;
int n, m, t, a, b, len;

int main()
{
    cin>>n>>m>>t;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            d[i][j] = INF;
            if(i==j)
                d[i][i] = 0;
        }

    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>len;
        if(d[a][b]>len)
        {
            d[a][b] = len;
            d[b][a] = len;
        }
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
            {
                if(d[j][k]>d[j][i]+d[i][k])
                    d[j][k] = d[j][i] + d[i][k];
            }

    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;
        if(d[a][b]!=INF)
            cout<<d[a][b]<<"\n";
        else
            cout<<-1<<"\n";
    }

    return 0;
}
