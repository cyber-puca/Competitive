#include <bits/stdc++.h>

using namespace std;
int w[1000001], c[101];
int n, sum;
const int M = 1000000007;
int main()
{
    cin>>n>>sum;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    w[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=sum-c[i];j++)
        {
            if(w[j]!=0)
            {
                w[j+c[i]] = (w[j+c[i]]+w[j])%M;
            }
        }
    }

    cout<<w[sum];
    return 0;
}
