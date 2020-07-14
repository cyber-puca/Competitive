#include <bits/stdc++.h>

using namespace std;
const int M = 1000000007;
int c[101], solve[1000001], n, sum, maxC;
int main()
{
    cin>>n>>sum;
    for(int i=1;i<=n;i++)
        cin>>c[i];

    solve[0]=1;
    for(int i=1;i<=sum;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i-c[j]>=0)
            {
                solve[i] = (solve[i]+solve[i-c[j]])%M;
            }
        }
    }
    cout<<solve[sum];
    return 0;
}
