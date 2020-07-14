#include <bits/stdc++.h>

using namespace std;
long long n, x, maxT, sum;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        sum += x;
        maxT=max(maxT,x);
    }
    if(maxT>sum-maxT)
    {
        cout<<maxT*2;
    }
    else
    {
        cout<<sum;
    }
    return 0;
}
