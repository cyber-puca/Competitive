#include <bits/stdc++.h>

using namespace std;
const int N = 1001;
int n, sum, p[N], pag[N], m[100001], maxP=0;

int main()
{
    cin>>n>>sum;
    for(int i=1;i<=sum;i++)
        m[i]=-1;
    for(int i=0;i<n;i++)
        cin>>p[i];
    for(int i=0;i<n;i++)
        cin>>pag[i];

    m[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=sum;j>=1;j--)
        {
            if(j-p[i]>=0 && m[j-p[i]]!=-1)
            {
                m[j] = max(m[j], m[j-p[i]]+pag[i]);
            }
        }
    }
    for(int j=0;j<=sum;j++)
    {
        maxP=max(maxP,m[j]);
    }
    cout<<maxP;
    return 0;
}
