#include <bits/stdc++.h>

using namespace std;

const int N = 5002;
int d[N][N], n, m;
char s1[N], s2[N];

int main()
{
    cin>>s1>>s2;
    n = strlen(s1);
    m = strlen(s2);

    for(int i=n;i>=1;i--)
    {
        s1[i] = s1[i-1];
        d[i][0] = i;
    }
    for(int i=m;i>=1;i--)
    {
        s2[i] = s2[i-1];
        d[0][i] = i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i]==s2[j])
            {
                d[i][j] = d[i-1][j-1];
            }
            else
            {
                d[i][j] = min(min(d[i-1][j], d[i-1][j-1]), d[i][j-1]) + 1;
            }
        }
    }

    cout<<d[n][m];
    return 0;
}
