#include <bits/stdc++.h>

using namespace std;
int n, sum, c[101], solve[1000001];

int main()
{
    cin>>n>>sum;
    for(int i=1;i<=n;i++)
        cin>>c[i];

    solve[0]=0;
    for (int i=1;i<=sum;i++)
    {
        solve[i]=1000001;
        for(int j=1;j<=n;j++)
            if(i-c[j]>=0)
            {
               solve[i] = min(solve[i],solve[i-c[j]]+1);
            }
    }
    if(solve[sum]==1000001)
        cout<<-1;
    else
        cout<<solve[sum];
    return 0;
}
