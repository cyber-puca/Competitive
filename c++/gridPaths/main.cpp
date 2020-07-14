#include <bits/stdc++.h>

using namespace std;
const int N = 1001, M=1000000007;
long long p[N][N], n;
char c;

int main()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>c;
            if(c=='*')
            {
                p[i][j]=0;
            }
            else if(i==1 && j==1)
            {
                p[i][j]=1;
            }
            else
            {
                p[i][j]=(p[i-1][j]+p[i][j-1])%M;
            }
        }
    }
    cout<<p[n][n];
    return 0;
}
