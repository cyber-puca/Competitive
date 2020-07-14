#include <bits/stdc++.h>

using namespace std;
const int N = 501, INF = 25000;
int p[N][N], n, m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i!=j)
                p[i][j] = INF;
            for(int cut=1;cut<=j;cut++)
            {
                p[i][j] = min(p[i][j], p[i][cut]+p[i][j-cut]+1);
            }
            for(int cut=1;cut<=i;cut++)
            {
                p[i][j] = min(p[i][j], p[cut][j]+p[i-cut][j]+1);
            }
        }
    }
    cout<<p[n][m];
    return 0;
}
