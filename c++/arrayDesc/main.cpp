#include <bits/stdc++.h>

using namespace std;
const int M = 1000000007;
long long n, maxV, sub[102][100002], x, ar, i;

void update(int val)
{
    sub[val][i] = (sub[val-1][i-1]+sub[val][i-1]+sub[val+1][i-1])%M;
}

int main()
{
    cin>>n>>maxV;
    cin>>x;
    if(x==0)
    {
        for(int j=1;j<=maxV;j++)
        {
            sub[j][1]=1;
        }
    }
    else
    {
        sub[x][1]=1;
    }
    for(i=2;i<=n;i++)
    {
        cin>>x;
        if(x==0)
        {
            for(int j=1;j<=maxV;j++)
                update(j);
        }
        else
        {
            update(x);
        }
    }

    if(x==0)
    {
        for(int j=1;j<=maxV;j++)
                ar= (ar+sub[j][i-1])%M;
        cout<<ar;
    }
    else
    {
        cout<<sub[x][n];
    }
    return 0;
}
